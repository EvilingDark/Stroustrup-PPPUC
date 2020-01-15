// глава 12 упр 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

	Point t1{ 300,200 };
	Simple_window win{ t1, 1000, 750, "Canvas" };

	Circle c1(Point(150, 150), 100);
	c1.set_color(Color::blue);
	c1.set_style(Line_style(Line_style::solid, 5));
	win.attach(c1);

	Circle c2(Point(360, 150), 100);
	c2.set_color(Color::black);
	c2.set_style(Line_style(Line_style::solid, 5));
	win.attach(c2);

	Circle c3(Point(570, 150), 100);
	c3.set_color(Color::red);
	c3.set_style(Line_style(Line_style::solid, 5));
	win.attach(c3);

	Circle c4(Point(255, 280), 100);
	c4.set_color(Color::yellow);
	c4.set_style(Line_style(Line_style::solid, 5));
	win.attach(c4);

	Circle c5(Point(465, 280), 100);
	c5.set_color(Color::green);
	c5.set_style(Line_style(Line_style::solid, 5));
	win.attach(c5);

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
