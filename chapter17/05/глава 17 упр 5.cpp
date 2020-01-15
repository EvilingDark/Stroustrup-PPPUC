// глава 17 упр 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <std_lib_facilities.h>

void to_lower(char* s)
{
	if (s == nullptr)
	{
		error("Doesn't contain a pointer value", s);
		return;
	}
	while (*s != '0')
	{
		if (isupper(*s))
			* s = tolower(*s);
		s += 1;
	}
}

void print(char* s)
{
	if (s == nullptr)
	{
		error("Doesn't contain a pointer value", s);
		return;
	}
	while (*s != '0')
	{
		cout << *s;
		s += 1;
	}
	cout << endl;
}

int size(char* s)
{
	if (s == nullptr)
	{
		error("Doesn't contain a pointer value", s);
		return 0;
	}
	int count = 0;
	while (*s != '0')
	{
		s += 1;
		++count;
	}
	return count;
}

char* _strdup(const char* str)
{
	if (str == nullptr)
	{
		error("Doesn't contain a pointer value", str);
		return nullptr;
	}
	char* st0 = const_cast<char*>(str);
	int length = size(st0);
	char* st1 = new char[length + 1];
	for (int i = 0; i <= length; ++i)
		st1[i] = st0[i];
	return st1;
}

char* _findx(const char* s, const char* x)
{
	if (s == nullptr)
	{
		error("Doesn't contain a pointer value", s);
		return nullptr;
	}
	if (x == nullptr)
	{
		error("Doesn't contain a pointer value", x);
		return nullptr;
	}
	char* str_one = const_cast<char*>(s);
	char* str_two = const_cast<char*>(x);
	int length_one = size(str_one);
	int length_two = size(str_two);
	int min = 0;
	if (length_one <= length_two)
		min = length_one;
	else
		min = length_two;
	for (int i = 0; i < min; ++i)
		if (str_one[i] == str_two[i])
			return str_one + i;
	return nullptr;
}

char* enter()
{
	cout << "Enter the number of characters" << endl;
	int n = 0;
	cin >> n;
	cout << "Enter the characters" << endl;
	char* s = new char[n + 1];
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	s[n] = '0';
	return s;
}

int main()
{
	char* s = enter();
	print(s);
	char* str = _strdup(s);
	to_lower(str);
	print(str);
	cout << *_findx(s, str) << endl;
	delete[] s;
	delete[] str;
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
