// глава 5 задание 12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

//программа создает последовательность из 4 цифр по ключу и вы пытаетесь ее отгадать
inline void error(const string& s)
{
	throw runtime_error(s);
}

default_random_engine& get_rand()
{
	static default_random_engine ran;
	return ran;
};

void seed_randint(int s) { get_rand().seed(s); }

inline int randint(int min, int max) { return uniform_int_distribution<>{min, max}(get_rand()); }

inline int randint(int max) { return randint(0, max); }
////////////////////////////////////////////////////////////////////////////////////////////////
void key_check();
vector<int> key;
vector<int> secret;
int check = 0;

void secret_create()		//создание угадываемых чисел
{
	int number = 0;
	cout << "Введите число для создания угадываемой последовательности\n";
	cin >> number;
	srand(number);
	for (int i = 0; i < 4; ++i)
	{
		secret.push_back(randint(10));
		cout << " " << secret[i];
	}
	cout << "\n";
	check = 0;
}

void key_create()		//создание вектора ключа
{
	cout << "Введите четыре цифры чтобы попытаться отгадать последовательность\n";
	for (int i = 0; i < secret.size(); ++i)
	{
		int number = 0;
		cin >> number;
		key.push_back(number);
	}
	key_check();
}

void key_check()		//проверка на повторения в векторе ключа
{
	for (int i = 0; i < key.size(); ++i)
	{
		for (int j = 0; j < key.size(); ++j)
		{
			if (key[i] == key[j] && i != j)
			{
				error("Ошибка повторяющиеся цифры в последовательности");
			}
		}
	}
}

void guess()		//проверка вектора ключа с угадываемым вектором и вывод совпадений
{
	int count = 0;
	for (int i = 0; i < secret.size(); ++i)
	{
		if (secret[i] == key[i])
			++count;
		if (count == 4)
		{
			cout << "Вы угадали!\n";
			system("pause");
			check = 1;
			secret.erase(secret.begin(), secret.end());		//удаляет значения из вектора secret
		}
	}
	if (check == 0)
	{
		cout << " " << count << " коровы\n";
		count = 0;
		for (int i = 0; i < secret.size(); ++i)
			for (int j = 0; j < key.size(); ++j)
				if (secret[i] == key[j] && i != j)
					++count;
		cout << " " << count << " быка\n";
	}
	key.erase(key.begin(), key.end());		//удаляет значения из вектора key
}

int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		secret_create();
		while (true)
		{
			key_create();
			guess();
			if (check == 1)
				secret_create();
		}
	}

	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
		system("pause");
		return 1;
	}
	catch (out_of_range)
	{
		cout << "Ошибка диапозона\n" << endl;
		system("pause");
		return 2;
	}
	catch (...)
	{
		cerr << "Неизвестное исключение! \n";
		system("pause");
		return 3;
	}
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
