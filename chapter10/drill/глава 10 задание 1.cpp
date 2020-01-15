// глава 10 задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Header.h>
#include <Point.h>

void print_point(const vector<Point>& p)
{
	for (int i = 0; i < p.size(); ++i)
		cout << p[i] << endl;
}

void write_to_file(const vector<Point>& p, string oname)
{
	ofstream ost{ oname };
	if (!ost)
		error("Невозможно открыть выходной файл", oname);
	for (int i = 0; i < p.size(); ++i)
		ost << '(' << p[i].x << ',' << p[i].y << ')' << endl;
}

void read_to_vector(vector<Point>& p, string iname)
{
	ifstream ist{ iname };
	if (!ist)
		error("Невозможно открыть входной файл", iname);
	char ch0, ch1, ch2;
	int x = 0, y = 0;
	while (ist >> ch0 >> x >> ch1 >> y >> ch2)
	{
		//ist >> ch0 >> x >> ch1 >> y >> ch2;
		if (ch0 == '(' && ch1 == ',' && ch2 == ')')
			p.push_back(Point{ x,y });
		else
			error("Ошибка формата файла", iname);
		if (ist.eof()) {
			cout << "Достигнут конец файла" << iname << endl;
			return;
		}
	}
}

void enter_vector(vector<Point>& p)
{
	cout << "Введите семь пар точек с координатами x, y\n";
	for (int i = 0; i < 7; ++i)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		p.push_back(Point{ x,y });
	}
}

void compare(const vector<Point>& a, const vector<Point>& b)
{
	if (a.size() == b.size())
	{
		int check = 0;
		for (int i = 0; i < a.size(); ++i)
			if (a[i] != b[i])
				++check;
		if (check == 0)
			cout << "Вектора равны" << endl;
		else
			cout << "Вектора не равны" << endl;
	}
	else
		cout << "Векторы не равны" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<Point> original_points;

	enter_vector(original_points);
	print_point(original_points);
	write_to_file(original_points, "mydata.txt");
	vector<Point> processed_points;
	read_to_vector(processed_points, "mydata.txt");
	cout << endl;
	print_point(processed_points);
	compare(original_points, processed_points);
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
