// глава 15 упр 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>
#include <bar_graph.h>

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	constexpr int xmax = 600;
	constexpr int ymax = 600;

	constexpr int xcenter = xmax / 2;
	constexpr int ycenter = ymax / 2;

	Point center{ xcenter,ycenter };

	Simple_window win{ {200,200}, xmax, ymax, "Canvas" };
	win.set_label("Function graphs");

	Graph_lib::Axis x(Axis::x, { xcenter - 200,ycenter + 200 }, 400, 6, "1 == 5 cm, begin 170 cm");
	x.set_color(Color::red);
	x.label.move(-40, 0);
	Axis y(Axis::y, { xcenter - 200,ycenter + 200 }, 400, 25, "persons");
	y.set_color(Color::red);
	y.label.move(-25, 0);


	constexpr int r_min = -10;
	constexpr int r_max = 11;

	bar_graph bg({ center.x - 200,center.y + 200 }, 400, 368);
	bg.add_data(7, "170", Color::blue);
	bg.add_data(9, "175", Color::magenta);
	bg.add_data(23, "180", Color::yellow);
	bg.add_data(17, "185", Color::dark_green);
	bg.add_data(9, "190", Color::dark_cyan);
	bg.add_data(1, "195", Color::dark_red);
	win.attach(bg);

	win.attach(x);
	win.attach(y);

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
