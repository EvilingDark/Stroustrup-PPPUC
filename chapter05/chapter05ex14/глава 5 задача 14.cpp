// глава 5 задача 14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//в программу нужно ввести по 7 значений для каждого дня и она посчитает сумму для каждого дня
inline void error(const string& s)
{
	throw runtime_error(s);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		string day = " ";
		int number = 0;
		vector<int> monday;
		vector<int> tuesday;
		vector<int> wednesday;
		vector<int> thursday;
		vector<int> friday;
		vector<int> saturday;
		vector<int> sunday;
		int sum_mon = 0, sum_tue = 0, sum_wed = 0, sum_thu = 0, sum_fri = 0, sum_sat = 0, sum_sun = 0;
		int check = 0, count = 0;
		while(check == 0)
		{
			cout << "Введите день недели и значение\n";
			cin >> day >> number;
			if (day == "Monday" || day == "Mon" || day == "monday")
				monday.push_back(number);
			else if (day == "Tuesday" || day == "Tue" || day == "tuesday")
				tuesday.push_back(number);
			else if (day == "Wednesday" || day == "Wed" || day == "wednesday")
				wednesday.push_back(number);
			else if (day == "Thursday" || day == "Thu" || day == "thursday")
				thursday.push_back(number);
			else if (day == "Friday" || day == "Fri" || day == "friday")
				friday.push_back(number);
			else if (day == "Saturday" || day == "Sat" || day == "saturday")
				saturday.push_back(number);
			else if (day == "Sunday" || day == "Sun" || day == "sunday")
				sunday.push_back(number);
			else if (day == "Stop")
				check = 1;
			else
				++count;
		}
		//////////////////////////////////////////
		cout << " Monday ";
		for (int i = 0; i < monday.size(); ++i)
		{
			cout << " " << monday[i] << " ";
			sum_mon += monday[i];
		}
		cout << " сумма = " << sum_mon << "\n";
		//////////////////////////////////////////
		cout << " Tuesday ";
		for (int i = 0; i < tuesday.size(); ++i)
		{
			cout << " " << tuesday[i] << " ";
			sum_tue += tuesday[i];
		}
		cout << " сумма = " << sum_tue << "\n";
		/////////////////////////////////////////////
		cout << " Wednesday ";
		for (int i = 0; i < wednesday.size(); ++i)
		{
			cout << " " << wednesday[i] << " ";
			sum_wed += wednesday[i];
		}
		cout << " сумма = " << sum_wed << "\n";
		/////////////////////////////////////////////
		cout << " Thursday ";
		for (int i = 0; i < thursday.size(); ++i)
		{
			cout << " " << thursday[i] << " ";
			sum_thu += thursday[i];
		}
		cout << " сумма = " << sum_thu << "\n";
		//////////////////////////////////////////////
		cout << " Friday ";
		for (int i = 0; i < friday.size(); ++i)
		{
			cout << " " << friday[i] << " ";
			sum_fri += friday[i];
		}
		cout << " сумма = " << sum_fri << "\n";
		//////////////////////////////////////////////
		cout << " Saturday ";
		for (int i = 0; i < saturday.size(); ++i)
		{
			cout << " " << saturday[i] << " ";
			sum_sat += saturday[i];
		}
		cout << " сумма = " << sum_sat << "\n";
		///////////////////////////////////////////////
		cout << " Sunday ";
		for (int i = 0; i < sunday.size(); ++i)
		{
			cout << " " << sunday[i] << " ";
			sum_sun += sunday[i];
		}
		cout << " сумма = " << sum_sun << "\n\n";
		cout << " Количество неправильно введенных дней = " << count << "\n";

		system("pause");
		return 0;
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
