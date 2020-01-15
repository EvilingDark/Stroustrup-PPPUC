// глава 12 упр 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

	Graph_lib::Rectangle house(Point(300, 350), 550, 300);
	house.set_color(Color::yellow);
	house.set_fill_color(Color::yellow);
	win.attach(house);

	Graph_lib::Rectangle window(Point(370, 420), 150, 100);
	window.set_color(Color::black);
	window.set_fill_color(Color::white);
	win.attach(window);

	Graph_lib::Rectangle window2(Point(630, 420), 150, 100);
	window2.set_color(Color::black);
	window2.set_fill_color(Color::white);
	win.attach(window2);

	Graph_lib::Polygon poly;
	poly.add(Point(270, 350));
	poly.add(Point(880, 350));
	poly.add(Point(575, 200));
	poly.set_fill_color(Color::dark_yellow);
	win.attach(poly);

	Graph_lib::Rectangle tube(Point(700, 150), 60, 160);
	tube.set_fill_color(Color::red);
	win.attach(tube);

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
