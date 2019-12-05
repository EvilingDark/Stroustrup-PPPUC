// глава 5 упр 10_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

//программа считает сумму первых N членов введенного ряда
inline void error(const string& s)
{
	throw runtime_error(s);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		cout << "Введите количество суммуруемых значений\n";
		int n = 0;
		double point = 0, sum = 0;
		cin >> n;
		vector<double> numbers;
		vector<int> real_numbers;
		cout << "Введите несколько целых чисел (| для выхода)\n";
		while (cin >> point)
		{
			if (!cin)
				error("Ошибка ввода\n");
			cout << "Введите несколько целых чисел (| для выхода)\n";
			numbers.push_back(point);
			if (int(point) == point) //записываем в вектор целые числа
				real_numbers.push_back(int(point));
		}
		if (n > int(numbers.size()))
			error("Количествол суммуруемых значений больше чем введено");
		for (int i = 0; i < n; ++i)
			sum += numbers[i];
		cout << "Сумма значений ( ";
		for (int i = 0; i < n; ++i)
			cout << numbers[i] << " ";
		cout << ") равна " << sum << "\n";
		if (real_numbers.size() > 1) //если целых чисел в векторе больше одного считаем разность соседних величин
		{
			cout << "Разность действительных чисел n и n + 1\n";
			for (int i = 0; i < real_numbers.size(); ++i)
				if (i + 1 < n)
					cout << "( " << real_numbers[i] << " " << real_numbers[i + 1] << " ) равна "
					<< real_numbers[i] - real_numbers[i + 1] << "\n";

			cout << "\n";
		}


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
