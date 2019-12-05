// глава 6 упр 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void error(const string& s)
{
	throw runtime_error(s);
}

class Grammar {		//содержит тип слова и само слово
public:
	char kind;        // what kind of token
	string Wd;     // for numbers: a value
	Grammar(char ch, string w)     // make a Token from a char and a double
		:kind(ch), Wd(w) { }
};

class Grammar_stream {
public:
	Grammar_stream();
	Grammar get();      // get a Token (get() is defined elsewhere)
	void putback(Grammar w);
private:
	bool full;        // is there a Token in the buffer?
	Grammar buffer;     // here is where we keep a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Grammar_stream::Grammar_stream()
	:full(false), buffer(' ', " ")    // no Token in buffer
{
}	

// The putback() member function puts its argument back into the Token_stream's buffer:
void Grammar_stream::putback(Grammar w)		//ложим в буфер
{
	if (full) error("putback() into a full buffer");
	buffer = w;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Grammar Grammar_stream::get()	//получаем Grammar
{
	if (full) {       // do we already have a Token ready?
					// remove token from buffer
		full = false;
		return buffer;
	}

	string s;
	cin >> s;    // note that >> skips whitespace (space, newline, tab, etc.)
	if (s == ".")	//проверка на конец предложения
		return Grammar('q', s);
	vector<string> article { "the", "a", "an" };	//проверяем артикли
	for (int i = 0; i < article.size(); ++i)
	{
		if (s == article[i])
			return Grammar('a', s);
	}
	return Grammar(' ', s);

}

Grammar_stream gs;
///////////////////////////////////////////////////////////////////////////////////////

Grammar noun()	//проверяем существительные
{
	Grammar word = gs.get();
	if (word.kind == ' ')
	{
		vector<string> noun = { "birds", "fish", "C++" };
		for (int i = 0; i < noun.size(); ++i)
			if (word.Wd == noun[i])
				return Grammar('n', word.Wd);
	}
	return word;
}

Grammar verd()	//проверяем глаголы
{
	Grammar word = noun();
	if (word.kind == ' ')
	{
		vector<string> verb = { "rules", "fly", "swim" };
		for (int i = 0; i < verb.size(); ++i)
			if (word.Wd == verb[i])
				return Grammar('v', word.Wd);
	}
	return word;
}

Grammar league() //проверяем союзы
{
	Grammar word = verd();
	if (word.kind == ' ')
	{
		vector<string> league = { "and", "or", "but" };
		for (int i = 0; i < league.size(); ++i)
			if (word.Wd == league[i])
				return Grammar('l', word.Wd);
	}
	if (word.kind == ' ')
		error("Слово неизвестно");
	return word;
}

//программа определяет корректность предложения относительно грамматики английского языка
int main()
try
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите предложение заканчивающееся ' .'\n";
	while (cin)
	{
		vector<char> sentence;
		while (cin)
		{
			Grammar word_left = gs.get();		//берем из потока ввода слово для проверки конца предложения и смотрим его тип
			if (word_left.kind == 'q')
			{
				if (sentence[0] == 'a' && sentence[1] == 'n' && sentence[2] == 'v')
					cout << "Это предложение\n";
				else if (sentence[0] == 'n' && sentence[1] == 'v')
					cout << "Это предложение\n";
				else if (sentence[0] == 'a' && sentence[1] == 'n' && sentence[2] == 'v' && sentence[3] == 'l' && sentence[4] == 'n' && sentence[5] == 'v')
					cout << "Это предложение\n";
				else if (sentence[0] == 'a' && sentence[1] == 'n' && sentence[2] == 'v' && sentence[3] == 'l' && sentence[4] == 'a' && sentence[5] == 'n' && sentence[6] == 'v')
					cout << "Это предложение\n";
				else if (sentence[0] == 'n' && sentence[1] == 'v' && sentence[2] == 'l' && sentence[3] == 'a' && sentence[4] == 'n' && sentence[5] == 'v')
					cout << "Это предложение\n";
				else
					cout << "Это не предложение\n";
				keep_window_open();
				break;
			}
			else
			{
				gs.putback(word_left);		//ложим его назазад
			}
			Grammar word = league();		//определяем тип слова из потока ввода
			sentence.push_back(word.kind);	//записываем в вектор последовательность типов слов для проверки грамматики
		}
	}
	keep_window_open();
	return 0;
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
