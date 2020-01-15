// глава 13 упр 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>
#include <Direction_Graph.h>


int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	Point t1{ 200,200 };
	Simple_window win{ t1, 1400, 950, "Canvas" };

	Graph_lib::Rectangle r{ Point{100,150}, 200, 100 };
	r.set_color(Color::blue);
	win.attach(r);

	Circle c{ Point{300,400}, 100 };
	c.set_color(Color::red);
	win.attach(c);

	Graph_lib::Ellipse el{ Point{700,600}, 100, 150};
	el.set_color(Color::black);
	win.attach(el);

	Marks m{ "x" };
	using namespace Direction_Graph;
	m.add({ n(r) });
	m.add({ s(r) });
	m.add({ e(r) });
	m.add({ w(r) });
	m.add({ center(r) });
	m.add({ sw(r) });
	m.add({ se(r) });
	m.add({ nw(r) });
	m.add({ ne(r) });

	m.add({ n(c) });
	m.add({ s(c) });
	m.add({ e(c) });
	m.add({ w(c) });
	m.add({ center(c) });
	m.add({ sw(c) });
	m.add({ se(c) });
	m.add({ nw(c) });
	m.add({ ne(c) });

	m.add({ n(el) });
	m.add({ s(el) });
	m.add({ e(el) });
	m.add({ w(el) });
	m.add({ center(el) });
	m.add({ sw(el) });
	m.add({ se(el) });
	m.add({ nw(el) });
	m.add({ ne(el) });
	win.attach(m);

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
