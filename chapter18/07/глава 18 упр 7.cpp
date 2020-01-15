// глава 18 упр 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <std_lib_facilities.h>

using namespace std;

int strlen1(const char* st)
{
	int i = 0;
	while (*st)
	{
		++st;
		++i;
	}
	return i;
}

char* cat_dot(const char* s1, const char* s2, const char* dot)
{
	int l_s1 = strlen1(s1);
	int l_s2 = strlen1(s2);
	int l_dot = strlen1(dot);
	int length = l_s1 + l_s2 + l_dot;
	char* cat = new char[length + 1];
	char* p = cat;
	while (*s1)
	{
		*p = *s1;
		++p;
		++s1;
	}
	while (*dot)
	{
		*p = *dot;
		++p;
		++dot;
	}
	while (*s2)
	{
		*p = *s2;
		++p;
		++s2;
	}
	*p = 0;
	return cat;
}

void print_char(const char* st)
{
	while (*st)
	{
		cout << *st;
		++st;
	}
	cout << endl;
}

int main()
{
	char s1[]{ "Lesha" };
	char s2[]{ "Pasha" };
	char dot[]{ "qwerty" };
	char* s = cat_dot(s1, s2, dot);
	print_char(s);
	delete[] s;
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
