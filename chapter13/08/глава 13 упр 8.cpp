// глава 13 упр 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Point.h>
#include <Graph.cpp>
#include <GUI.cpp>
#include <std_lib_facilities.h>
#include <Regular_hexagon.h>
#include <Regular_polygon.h>

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	Point t1{ 200,200 };
	Simple_window win{ t1, 1400, 950, "Canvas" };

	Regular_hexagon rh(Point(300, 300), 100);
	rh.set_color(Color::red);
	rh.set_style(Line_style(Line_style::solid, 3));
	rh.set_fill_color(Color::blue);
	win.attach(rh);

	Regular_hexagon rh0(Point(450, 385), 100);
	rh0.set_color(Color::red);
	rh0.set_style(Line_style(Line_style::solid, 3));
	rh0.set_fill_color(Color::blue);
	win.attach(rh0);

	Regular_hexagon rh1(Point(450, 215), 100);
	rh1.set_color(Color::red);
	rh1.set_style(Line_style(Line_style::solid, 3));
	rh1.set_fill_color(Color::blue);
	win.attach(rh1);

	Regular_hexagon rh2(Point(600, 300), 100);
	rh2.set_color(Color::red);
	rh2.set_style(Line_style(Line_style::solid, 3));
	rh2.set_fill_color(Color::blue);
	win.attach(rh2);

	Regular_polygon rp(Point{ 700,600 }, 8, 120);
	rp.set_color(Color::red);
	rp.set_style(Line_style(Line_style::solid, 3));
	rp.set_fill_color(Color::blue);
	win.attach(rp);

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
