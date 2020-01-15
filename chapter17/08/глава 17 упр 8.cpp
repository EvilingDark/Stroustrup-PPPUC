// глава 17 упр 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <std_lib_facilities.h>

void print(char* s)
{
	if (s == nullptr)
	{
		error("Doesn't contain a pointer value", s);
		return;
	}
	const char stop_char = '!';
	while (*s != stop_char)
	{
		cout << *s;
		s += 1;
	}
	cout << endl;
}

char* enter()
{
	const char stop_char = '!';
	cout << "Enter characters" << endl;
	char* st = new char[2000];
	char ch;
	int count = 0;
	while (cin.get(ch) && ch != stop_char)
	{
		st[count] = ch;
		++count;
	}
	return st;
}

void st_print(const string& s)
{
	for (auto ch : s)
		cout << ch;
	cout << endl;
}

string st_enter()
{
	const char stop_char = '!';
	cout << "Enter characters" << endl;
	string st;
	char ch;
	while (cin.get(ch) && ch != stop_char)
		st.push_back(ch);
	return st;
}

int main()
try
{
	char* st = enter();
	print(st);
	delete[] st;
	cout << endl;
	string s = st_enter();
	st_print(s);
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
	return 1;
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
