// глава 12 задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	Point t1{ 200,200 };
	Simple_window win{ t1, 1400, 950, "Canvas" };

	Graph_lib::Polygon poly;
	poly.add(Point{ 50,200 });
	poly.add(Point{ 50,400 });
	poly.add(Point{ 300,400 });
	poly.add(Point(400, 300));
	poly.add(Point{ 300,200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dashdot, 2));
	poly.set_fill_color(Color::dark_magenta);
	win.attach(poly);

	Graph_lib::Rectangle r(Point(500, 400), 200, 100);
	r.set_color(Color::dark_yellow);
	r.set_style(Line_style(Line_style::dot, 2));
	r.set_fill_color(Color::white);
	win.attach(r);

	Axis xa(Axis::x, Point(100, 550), 600, 15, "x axis");
	xa.set_color(Color::magenta);
	xa.set_style(Line_style(Line_style::dash));
	win.attach(xa);

	Axis ya(Axis::y, Point(100, 550), 500, 15, "y axis");
	ya.set_color(Color::cyan);
	ya.set_style(Line_style(Line_style::dashdotdot, 2));
	win.attach(ya);

	Function sine(sin, 0, 100, Point(100, 300), 5000, 50, 100);
	sine.set_color(Color::dark_green);
	win.attach(sine);

	Text t(Point(500, 100), "Hello, graphical world!");
	t.set_font(Font::helvetica_bold);
	t.set_font_size(25);
	t.set_color(Color::dark_blue);
	win.attach(t);

	Image ii(Point(600, 500), "1.jpeg");
	win.attach(ii);

	Circle c(Point(200, 700), 100);
	c.set_fill_color(Color::black);
	win.attach(c);

	ostringstream ost;
	ost << "screen size: " << x_max() << " x " << y_max() << " window size: "
		<< win.x_max() << " x " << win.y_max();
	Text t2(Point(400, 900), ost.str());
	t2.set_color(Color::dark_red);
	win.attach(t2);

	win.set_label("Canvas #2");
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
