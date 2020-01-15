// глава 14 упр 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>
#include <Add_Graph.h>
#include <Group.h>

int main()
try
{
	using namespace Graph_lib;
	setlocale(LC_ALL, "Russian");

	Point t1{ 200,200 };
	Simple_window win{ t1, 1400, 950, "Canvas" };

	Circle cr({ 150,150 }, 50);
	Circle cr0({ 350,350 }, 50);

	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i =0;i < 8;++i)
		for (int j = 0; j < 8; ++j)
			vr.push_back(new Graph_lib::Rectangle({ 100 * i,100 * j }, 100, 100));
	for (int i = 0; i < vr.size(); ++i)
	{
		int a = i / 8;
		int b = a % 2;
		if (i % 2 == 0 && b == 0)
			vr[i].set_fill_color(Color::yellow);
		else if (i % 2 == 1 && b == 1)
			vr[i].set_fill_color(Color::yellow);
		else
			vr[i].set_fill_color(Color::white);
		win.attach(vr[i]);
	}

	win.attach(cr);
	win.attach(cr0);
	Group grp;
	grp.add_Shape(cr);
	grp.add_Shape(cr0);
	grp.set_color(Color::blue);
	while (true) {
		win.wait_for_button();
		grp.move(100, 100);
	}
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
