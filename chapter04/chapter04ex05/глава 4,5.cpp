// глава 4,5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа записывает и сравнивает числа
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите число\n\n";
	string val_1 = " ";
	vector<double> numbers;
	vector<string> s_numbers;
	vector<double> numbers_x;
	vector<string> s_numbers_x;
	while (cin >> val_1)
	{
		if (val_1 == "|")
			return true;
		char * a;
		double v1 = strtod(val_1.c_str(), &a);
		double max = 0, min = 1000, total = 0;
		int check = 0;
		string ch = a;
		//string s_max = " ", s_min = " ";
		int c_max = 0, c_min = 0;
		cout << "Введенное число: " << v1 << " " << a << "\n\n";
		if (ch == "m")  //выполняем проверку на правильность ввода единицы измерения
			check = 1;
		if (ch == "cm")
			check = 1;
		if (ch == "in")
			check = 1;
		if (ch == "ft")
			check = 1;
		if (check == 1)
		{
			numbers.push_back(v1); //содержит оригинальные значения
			numbers_x.push_back(v1); //содержит переведенные в метры значения
			s_numbers.push_back(a);
			s_numbers_x.push_back(a);
			for (int i = 0; i < numbers.size(); ++i)
			{
				if (s_numbers_x[i] == "cm") //переводим все величины в метры
				{
					numbers_x[i] /=100;
					s_numbers_x[i] = "m";
				}
				if (s_numbers_x[i] == "in")
				{
					numbers_x[i] /=39.370079;
					s_numbers_x[i] = "m";
				}
				if (s_numbers_x[i] == "ft")
				{
					numbers_x[i] *=0.3048;
					s_numbers_x[i] = "m";
				}
///////////////////////////////////////////////////////////////////////////////
				if (max < numbers_x[i]) //сравниваем переведенные значения
				{
					max = numbers_x[i];
					c_max = i;
				}
				if (min > numbers_x[i])
				{
					min = numbers_x[i];
					c_min = i;
				}
				total += numbers_x[i];
			}
			cout << "Наибольшее среди введенных: " << numbers[c_max] << " " << s_numbers[c_max] << "\n"
			<< "Наименьшее среди введенных: " << numbers[c_min] << " " << s_numbers[c_min] << "\n"
			<< "Количество введенных значений: " << numbers.size() << "\n"
			<< "Сумма всех значений: " << total << "\n\n";
		}
		else
			cout << "Неизвестная единица измерения\n";
	}
	sort(numbers_x.begin(), numbers_x.end());
	for (int i = 0; i < numbers.size(); ++i)
		cout << numbers_x[i] << " m\n";

	system ("pause");
	return 0;
}

