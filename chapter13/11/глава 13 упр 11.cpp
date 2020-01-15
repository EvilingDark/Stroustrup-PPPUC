// глава 13 упр 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Point.h>
#include <Graph.cpp>
#include <GUI.cpp>
#include <std_lib_facilities.h>

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	Point t1{ 200,200 };
	Simple_window win{ t1, 1400, 950, "Canvas" };

	Graph_lib::Ellipse el(Point{ 500,400 }, 150, 100);
	el.set_color(Color::magenta);
	win.attach(el);

	Axis ax(Axis::x, Point{ 300, 400 }, 400, 0,"Axis x");
	ax.set_color(Color::black);
	win.attach(ax);

	Axis ay(Axis::y, Point{ 500, 550 }, 300, 0, "Axis y");
	ay.set_color(Color::black);
	win.attach(ay);

	Marks mx("x");
	mx.add({ 425,400 });
	mx.add({ 575,400 });
	mx.add({ 450,307 });
	win.attach(mx);

	Lines lns;
	lns.add({ 425,400 }, { 450,307 });
	lns.add({ 575,400 }, { 450,307 });
	win.attach(lns);
	

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
