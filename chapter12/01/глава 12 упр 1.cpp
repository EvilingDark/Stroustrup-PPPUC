// глава 12 упр 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	Simple_window win{ t1, 1000, 700, "Canvas" };

	Graph_lib::Polygon poly;
	poly.add(Point{ 50,200 });
	poly.add(Point{ 50,400 });
	poly.add(Point{ 300,400 });
	poly.add(Point{ 300,200 });
	poly.set_color(Color::red);
	win.attach(poly);

	Graph_lib::Rectangle r(Point(500, 400), 200, 100);
	r.set_color(Color::blue);
	win.attach(r);

	Graph_lib::Rectangle rec(Point(200, 500), 100, 30);
	rec.set_color(Color::black);
	win.attach(rec);

	Text t(Point(225, 515), "Howdy!");
	t.set_color(Color::dark_cyan);
	win.attach(t);

	Text to(Point(400, 650), "O");
	to.set_font_size(150);
	to.set_color(Color::white);
	win.attach(to);

	Text to2(Point(510, 650), "O");
	to2.set_font_size(150);
	to2.set_color(Color::blue);
	win.attach(to2);

	Text to3(Point(620, 650), "D");
	to3.set_font_size(150);
	to3.set_color(Color::red);
	win.attach(to3);

	Graph_lib::Rectangle r_1(Point(400, 50), 100, 100);
	r_1.set_fill_color(Color::red);
	win.attach(r_1);

	Graph_lib::Rectangle r_2(Point(500, 50), 100, 100);
	r_2.set_fill_color(Color::white);
	win.attach(r_2);

	Graph_lib::Rectangle r_3(Point(600, 50), 100, 100);
	r_3.set_fill_color(Color::red);
	win.attach(r_3);

	Graph_lib::Rectangle r_4(Point(400, 150), 100, 100);
	r_4.set_fill_color(Color::white);
	win.attach(r_4);

	Graph_lib::Rectangle r_5(Point(500, 150), 100, 100);
	r_5.set_fill_color(Color::red);
	win.attach(r_5);

	Graph_lib::Rectangle r_6(Point(600, 150), 100, 100);
	r_6.set_fill_color(Color::white);
	win.attach(r_6);

	Graph_lib::Rectangle r_7(Point(400, 250), 100, 100);
	r_7.set_fill_color(Color::red);
	win.attach(r_7);

	Graph_lib::Rectangle r_8(Point(500, 250), 100, 100);
	r_8.set_fill_color(Color::white);
	win.attach(r_8);

	Graph_lib::Rectangle r_9(Point(600, 250), 100, 100);
	r_9.set_fill_color(Color::red);
	win.attach(r_9);

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
