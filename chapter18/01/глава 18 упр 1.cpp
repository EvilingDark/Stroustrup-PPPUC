// глава 18 упр 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int my_strlen(const char* ch)
{
	int count = 0;
	while (ch[count])
		++count;
	return count;
}

char* _strdup(const char* ch)
{
	int i = 0;
	const char* p = ch;
	while (*p)
	{
		++i;
		++p;
	}
	cout << i << endl;
	char* copy = new char[i + 1];
	p = ch;
	while (*p)
	{
		*copy = *p;
		++copy;
		++p;
	}
	*copy = 0;
	copy -= i;
	return copy;
}

char* findx(const char* st, const char* x)
{
	const char* p = st;
	while (*p)
	{
		if (*p == *x)
			return const_cast<char*>(p);
		++p;
	}
	return nullptr;
}

int strcmp(const char* st_zero, const char* st_one)
{
	const char* p_zero = st_zero;
	const char* p_one = st_one;
	while (*p_zero)
	{
		if (*p_zero > * p_one)
			return 1;
		if (*p_zero < *p_one)
			return -1;
		++p_zero;
		++p_one;
	}
	p_zero = st_zero;
	p_one = st_one;
	while (*p_one)
	{
		if (*p_zero > * p_one)
			return 1;
		if (*p_zero < *p_one)
			return -1;
		++p_zero;
		++p_one;
	}
	return 0;
}

int main()
{
	char ch[]{ "abcde" };
	char ch1[]{ 'e' };
	char* p = _strdup(ch);
	cout << endl;
	for (int i = 0; i < my_strlen(p); ++i)
		cout << p[i];
	cout << endl;
	char* x = findx(ch, ch1);
	cout << *x << endl;
	char st0[]{ "qwerty" };
	char st1[]{ "qwerty" };
	cout << strcmp(st0, st1) << endl;
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
