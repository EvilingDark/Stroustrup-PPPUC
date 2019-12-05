// глава 6 упр 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

//программа для работы с логическими операциями
inline void error(const string& s)
{
	throw runtime_error(s);
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

void print_binary(char c) //вывод на экран в бинарном виде
{
	int k = 128;
	//printf("%d ", (int)c);
	while (k > 0) 
	{
		printf("%d", bool(c & k));
		k = k >> 1;
	};
	printf("\n");
}

class Token {
public:
	char kind;        // для операций
	char value;     // для переменных
	Token(char ch)    // make a Token from a char
		:kind(ch), value(' ') { }
	Token(char ch, char val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(' ', ' ')    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token_stream ts;

//------------------------------------------------------------------------------

Token Token_stream::get() //работает с !, ~ и буквами
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char left_ch;
	char ch;
	cin >> left_ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (left_ch) 
	{
	case '!':
	{
		cin >> ch;
		return Token('8', !ch);
	}
	case '~':
	{
		cin >> ch;
		return Token('8', ~ch);
	}
	case '^': case '|':
	case '(': case ')': case '&': case '=':
		return Token(left_ch);        // let each character represent itself
	case 'a':
	case 'b': case 'c': case 'd': case 'e': case 'f':
	case 'g': case 'h': case 'i': case 'j':
	case 'k': case 'l': case 'm': case 'n': case 'o':
	case 'p': case 'q': case 'r': case 's':
	case 't': case 'u': case 'v': case 'w': case 'x':
	case 'y': case 'z':
	{
		return Token('8', left_ch);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

Token b_and() //работает с &
{
	Token left = ts.get();
	Token t = ts.get();
	switch (t.kind) {
	case '&':            // we use '8' to represent a number
		t = ts.get();
		left.value &= t.value;
		return left;
	case '=':
		return Token(t.kind, left.value);
	default:
		ts.putback(t);
		return left;
	}
}

//работает с ^
Token b_xor()
{
	Token left = b_and();
	Token t = ts.get();
	switch (t.kind) {
	case '^':
	{
		t = b_and();
		left.value ^= t.value;
		return left;
	}
	case '=':
		return Token(t.kind, left.value);
	default:
		ts.putback(t);
		return left;
	}
}

// работает с |
Token b_or()
{
	Token left = b_xor();
	Token t = ts.get();
	switch (t.kind) {
	case '|':
	{
		t = b_and();
		left.value |= t.value;
		return left;
	}
	case '=':
		return Token(t.kind, left.value);
	default:
		ts.putback(t);
		return left;
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	setlocale(LC_ALL, "Russian");
	cout << "Добро пожаловать в побитовый логический калькулятор!\n" <<
		"Вводите логическую операцию\n\n" <<
		"Программа умеет работать с операциями !, ~, ^, |, &\n" <<
		"Для получения результата введите '=' в конце выражения.\n\n";
	Token val(' ', ' ');
	while (cin) 
	{
//		char x;  //код чтобы смотреть бинарный код символов
//		cin >> x;
//		print_binary(x);
		Token t = ts.get();
		if (t.kind == '=')        // ';' for "print now"
		{
			cout << " = ";
			print_binary(val.value);
		}
		else
			ts.putback(t);
		val = b_or();
		cout << val.kind << " ";
		print_binary(val.value);
		cout << "\n";
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
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
