﻿// глава 7 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>

using namespace std;

//программа со скобками и переменными
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s + s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s << ": " << i;
	error(os.str());
}

template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r) != a) error(string("info loss"));
	return r;
}

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s == "") return;
	cin.clear();
	cin.ignore(120, '\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss != s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}
//////////////////////////////////////////////////////////////////////
struct Token 
{
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n), value(0) { }
};

class Token_stream 
{
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

struct Variable
{
	string name;
	double value;
	bool type;
	Variable(string n, double v) :name(n), value(v), type(0) { }
	Variable(string n, double v, bool t) :name(n), value(v), type(t) { }
};

const char let = '#';
const char letc = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

double primary();
Token_stream ts;
double expression();
vector<Variable> names;
double sqrt_calc();
double pow_calc();
void clean_up_mess();

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '.':				//число может начинаться с .
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	default:
		if (isalpha(ch))		//если буква
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || (ch == '_'))) s += ch;		//считывает символ символ с потока cin и проверяет является он буквой или цифрой
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "letc") return Token(letc);
			if (s == "exit") return Token(quit);
			if (s == "sqrt") return Token(number, sqrt_calc());
			if (s == "pow") return Token(number, pow_calc());
			return Token(name, s);
		}
		error("Bad token");
	}
}

double sqrt_calc()
{
	double left = primary();
	if (left < 0)
		error("извлечение квадратного корня из отрицательного числа");
	double val = sqrt(left);
	return val;
}

double pow_calc()
{
	double val;
	Token t = ts.get();
	if (t.kind != '(')
		error("нет открывающей скобки в функции pow");
	t = ts.get();
	Token t2 = ts.get();
	if (t2.kind != ',')
		error("неверное использование функции pow");
	t2 = ts.get();
	int i = narrow_cast<int>(t2.value);
	if (t.kind == '8' && t2.kind == '8')
		val = pow(t.value, i);
	else error("неверные аргументы функции pow");
	t2 = ts.get();
	if (t2.kind != ')')
		error("нет закрывающей скобки в функции pow");
	return val;
}

void Token_stream::ignore(char c)		//игнорирует поток ввода cin до c
{
	if (full && c == buffer.kind) 
	{
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

double get_value(string s)		//возвращает значение переменной по имени s в векторе names
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)		//добавляет в вектор names переменную
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)		//проверяет введенное имя переменной с тем что хранится в векторе names
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double primary()		//работает со скобками
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term()		//работает с * и /
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind)
		{
		case '*':
		{
			left *= primary();
			break;
		}
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("%: divide by zero");
			left = fmod(left, d);
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()		//работает с + и -
{
	double left = term();
	while (true) 
	{
		Token t = ts.get();
		switch (t.kind) 
		{
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()		//объявление переменной "let имя = число"
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name))
	{
		cout << "Переменная " << name << " уже определена.\n" <<
			"Хотите изменить значение? y/n\n";
		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		clean_up_mess();
		char ch;
		cin >> ch;
		if (ch == 'y')
			for (int i = 0; i < names.size(); ++i)
				if (names[i].name == name)
				{
					names[i].value = d;
					clean_up_mess();
					return d;
				}
		error(name, " declared twice");
	}
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) 
	{
	case let:
		return declaration();
	case letc:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (cin) 
	try 
	{
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try 
{
	setlocale(LC_ALL, "Russian");

	names.push_back(Variable("pi", 3.141592));
	names.push_back(Variable("e", 2.718281));
	names.push_back(Variable("k", 1000));

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
