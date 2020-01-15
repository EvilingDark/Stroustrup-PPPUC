// глава 15 упр 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>

double one(double) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return slope(x) + cos(x); }
double fac_rec(double n) { return n > 1 ? n * fac_rec(n - 1) : 1; }
double fac_ite(double n) {
	double r = 1;
	while (n > 1) {
		r *= n;
		--n;
	}
	return r;
}

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

	Graph_lib::Axis x(Axis::x, { xcenter - 200,ycenter }, 400, 20, "1 == 20 pixels");
	x.set_color(Color::red);
	x.label.move(-40, 0);
	Axis y(Axis::y, { xcenter,ycenter + 200 }, 400, 20, "1 == 20 pixels");
	y.set_color(Color::red);
	y.label.move(-25, 0);

	win.attach(x);
	win.attach(y);

	constexpr int r_min = -10;
	constexpr int r_max = 11;

	Function f1(one, r_min, r_max, center, 400, 20, 20);
	f1.set_color(Color::blue);
	//win.attach(f1);
	Function f2(slope, r_min, r_max, center, 400, 20, 20);
	f2.set_color(Color::blue);
	//win.attach(f2);
	Function f3(square, r_min, r_max, center, 400, 20, 20);
	f3.set_color(Color::blue);
	//win.attach(f3);
	Function f4(cos, r_min, r_max, center, 400, 20, 20);
	f4.set_color(Color::blue);
	//win.attach(f4);
	Function f5(sloping_cos, r_min, r_max, center, 400, 20, 20);
	f5.set_color(Color::blue);
	//win.attach(f5);
	Function f6(fac_rec, r_min, 4, center, 400, 20, 20);
	f6.set_color(Color::blue);
	win.attach(f6);

	Text f2t{ {100,380}, "x/2" };
	f2t.set_color(Color::black);
	//win.attach(f2t);

	for (int i = 0; i <= 20; ++i) {
		cout << i << " " << fac_rec(i) << endl;
	}

	cout << endl << endl;

	for (int i = 0; i <= 20; ++i) {
		cout << i << " " << fac_ite(i) << endl;
	}

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
