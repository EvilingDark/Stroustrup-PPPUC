// глава 13 упр 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>
#include <Arc.h>
#include <Box.h>
#include <Arrow.h>

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	Point t1{ 150,100 };
	Simple_window win{ t1, 800, 1000, "Canvas" };

//	Graph_lib::Arc arc(Point{ 300,300 }, 100, 50, 180);
//	arc.set_color(Color::dark_yellow);
//	win.attach(arc);

	Box b(Point{ 250,120 }, 400, 400, 100);
	b.set_color(Color::red);
	b.set_fill_color(Color::blue);
//	win.attach(b);

	Arrow a(Point{ 50,300 }, Point{ 200,150 });
	a.set_color(Color::red);
	win.attach(a);

	Arrow a1(Point{ 200,200 }, Point{ 400,300 });
	a1.set_color(Color::red);
	win.attach(a1);

	Arrow a2(Point{ 100,400 }, Point{ 300,350 });
	a2.set_color(Color::red);
	win.attach(a2);

	Marks m("x"); 
	m.add({ 200,150 });
	m.add({ 500, 150 });
	m.add({ 500,300 });
	m.add({ 200, 300 });
//	win.attach(m);


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
