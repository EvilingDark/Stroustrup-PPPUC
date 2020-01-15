// глава 15 упр 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
double sin_plus_cos(double x) { return sin(x) + cos(x); }
double sin_multiply_cos(double x) { return sin(x) * cos(x); }
double dsin_plus_dcos(double x) { return sin(x) * sin(x) + cos(x) * cos(x); }
double leibniz(int n) {
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		double x = pow(-1, i) / (2 * i + 1);
		sum += x;
	}
	return 4*sum;
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

	//Function f1(leibniz, 0, r_max, center, 400, 20, 20);
	//f1.set_color(Color::blue);
	//win.attach(f1);

	for (int i = 0; i <= 32; ++i) {
		cout << fixed << setprecision(16) << leibniz(i) << endl;
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
