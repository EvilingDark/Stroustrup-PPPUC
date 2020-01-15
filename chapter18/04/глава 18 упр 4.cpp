// глава 18 упр 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

char* _strdup(const char* ch, int max_num)
{
	int i = 1;
	const char* p = ch;
	while (*p)
	{
		if (i > max_num)
			break;
		++i;
		++p;
	}
	char* copy = new char[i + 1];
	p = ch;
	i = 1;
	while (*p)
	{
		if (i > max_num)
		{
			--i;
			break;
		}
		*copy = *p;
		++copy;
		++p;
		++i;
	}
	*copy = 0;
	copy -= i;
	return copy;
}

char* findx(const char* st, const char* x, int max_num)
{
	int i = 1;
	const char* p = st;
	while (*p)
	{
		if (i > max_num)
			break;
		if (*p == *x)
			return const_cast<char*>(p);
		++p;
		++i;
	}
	return nullptr;
}

int strcmp(const char* st_zero, const char* st_one, int max_num_zero, int max_num_one)
{
	const char* p_zero = st_zero;
	const char* p_one = st_one;
	int zero = 1;
	int one = 1;
	while (*p_zero)
	{
		if (zero > max_num_zero)
			break;
		if (*p_zero > * p_one)
			return 1;
		if (*p_zero < *p_one)
			return -1;
		++p_zero;
		++p_one;
		++zero;
	}
	p_zero = st_zero;
	p_one = st_one;
	while (*p_one)
	{
		if (one > max_num_one)
			break;
		if (*p_zero > * p_one)
			return 1;
		if (*p_zero < *p_one)
			return -1;
		++p_zero;
		++p_one;
		++one;
	}
	return 0;
}

void print_char(const char* st, int max_num)
{
	int i = 1;
	while (*st)
	{
		if (i > max_num)
			break;
		cout << *st;
		++st;
		++i;
	}
	cout << endl;
}

int main()
{
	char ch0[]{ 'a','b','c','d' };
	char* ch1 = _strdup(ch0, 4);
	print_char(ch0, 4);
	print_char(ch1, 4);
	char x[]{ 'c','d' };
	char* find = findx(ch0, x, 4);
	cout << *find << endl;
	char ch2[]{ 'a','b','c','d' };
	int i = strcmp(ch0, ch2, 4, 4);
	print_char(ch2, 4);
	cout << i << endl;
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
