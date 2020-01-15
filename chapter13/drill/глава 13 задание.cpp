// глава 13 задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>
#include <Arc.h>
#include <Box.h>

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	Point t1{ 150,100 };
	Simple_window win{ t1, 800, 1000, "Canvas" };

	int x_grid{ 100 };
	int y_grid{ 100 };
	Lines grid;
	for (int i = x_grid; i < 800; i += x_grid)
		grid.add(Point(i, 0), Point(i, 800));
	for (int i = y_grid; i < 801; i += y_grid)
		grid.add(Point(0, i), Point(win.x_max(), i));
	grid.set_color(Color::blue);
	win.attach(grid);

	int x_rect = 100;
	int y_rect = 100;
	Vector_ref<Graph_lib::Rectangle> rect;
	for (int i = 0; i < 8; ++i)
		rect.push_back(new Graph_lib::Rectangle(Point{ x_rect * i,y_rect * i }, 100, 100));
	for (int i = 0; i < rect.size(); ++i)
	{
		rect[i].set_fill_color(Color::red);
		win.attach(rect[i]);
	}
	
	string s{ "1.jpg" };
	Vector_ref<Graph_lib::Image> img{ new Image{Point{200,0}, s},
	new Image{Point{0,200}, s}, new Image{Point{400,200}, s} };
	for (int i = 0; i < img.size(); ++i)
	{
		img[i].set_mask(Point(60, 0), 200, 200);
		win.attach(img[i]);
	}

	Image to_move{ Point{0,0}, s };
	to_move.set_mask(Point(0, 0), 100, 100);
	win.attach(to_move);

	Graph_lib::Arc arc(Point{ 300,300 }, 100, 50, 180);
	arc.set_color(Color::dark_yellow);
	win.attach(arc);

	Box b(Point{ 500,500 }, 300, 150, 50);
	b.set_color(Color::green);
	win.attach(b);

	while (true)
	{
		win.wait_for_button();
		to_move.move(100, 0);
	}
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
