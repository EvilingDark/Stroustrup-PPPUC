// глава 5 упр 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

inline void error(const string& s)
{
	throw runtime_error(s);
}

int area(int length, int width) // Площадь прямоугольника
{
	setlocale(LC_ALL, "Russian");
	if (length <= 0)
		error("Длина равна или меньше нуля функции area");
	if (width <= 0)
		error("Ширина равна или меньше нуля функции area");

	return length * width;
}

int framed_area(int x, int y) // Площадь в педелах рамки
{
	if (x - 2 <= 0)
		error("Длина равна или меньше нуля функции framed_area");
	if (y - 2 <= 0)
		error("Ширина равна или меньше нуля функции framed_area");
	return area(x - 2, y - 2);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int x = 1;
	int y = 2;
	int z = 4;
	// . . .
	try
	{
		int area1 = area(x, y);
		int area2 = framed_area(1, z);
		int	area3 = framed_area(y, z);
		double ratio = double(area1) / area3;
		cout << "area1 = " << area1 << "\n" << "area2 = " << area2 << "\n"
			<< "area3 = " << area3 << "\n" << "ratio = " << ratio << "\n";
	}

	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
		system("pause");
		return 1;
	}
	catch (...)
	{
		cerr << "Неизвестное исключение! \n";
		system("pause");
		return 2;
	}
	system("pause");
	return 0;
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
