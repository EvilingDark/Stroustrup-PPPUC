// глава 12 упр 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>

#define PI 3.14159265

vector<Point> point_n(int n, Point p,  int radius)
{
	vector<Point> pv;
	double angle = 360 / n;
	for (int i = 0; i < n; ++i)
	{
		int a = radius * cos(angle * i * PI / 180.0);
		int b = radius * sin(angle * i * PI / 180.0);
		pv.push_back(Point(p.x + a,p.y - b));
	}
	return pv;
}

void poly_dots(Graph_lib::Polygon& poly, const vector<Point>& pv, int thickness = 1)
{
	for (const Point& p : pv)
		poly.add(p);
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::solid, thickness));
}

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	vector<Point> pv;
	Point t1{ 200,200 };
	Simple_window win{ t1, 1400, 950, "Canvas" };
	Point center(300, 300);

	pv = point_n(3, center, 100);
	Graph_lib::Polygon p1;
	poly_dots(p1, pv);
	win.attach(p1);

	pv = point_n(4, center, 100);
	Graph_lib::Polygon p2;
	poly_dots(p2, pv);
	win.attach(p2);

	pv = point_n(5, center, 100);
	Graph_lib::Polygon p3;
	poly_dots(p3, pv);
	win.attach(p3);

	pv = point_n(6, center, 100);
	Graph_lib::Polygon p4;
	poly_dots(p4, pv);
	win.attach(p4);

//	for (int i = 0; i < 361; ++i)
//		cout << "cos( " << i << " ) = " << cos(i * PI / 180.0) << "  sin( " << i << " ) = " << sin(i * PI / 180.0) << endl;

	win.wait_for_button();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
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
