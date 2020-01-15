// глава 12 упр 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

	Point t1{ 200,100 };
	Simple_window win{ t1, 1000,900, "Canvas" };
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_0(Point(100,100), 200, 50);
	r_0.set_fill_color(Color::white);
	r_0.set_color(Color::black);
	win.attach(r_0);

	Text t_0(Point(105, 95), "Point.h:");
	t_0.set_color(Color::black);
	t_0.set_font(Font::times_bold);
	t_0.set_font_size(15);
	win.attach(t_0);

	Text t_0_1(Point(110, 120), "struct Point { ... };");
	t_0_1.set_color(Color::black);
	t_0_1.set_font(Font::times_bold);
	t_0_1.set_font_size(15);
	win.attach(t_0_1);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_1(Point(440,80), 150, 50);
	r_1.set_fill_color(Color::white);
	r_1.set_color(Color::black);
	win.attach(r_1);

	Graph_lib::Rectangle r_1_0(Point(445, 85), 150, 50);
	r_1_0.set_fill_color(Color::white);
	r_1_0.set_color(Color::black);
	win.attach(r_1_0);

	Graph_lib::Rectangle r_1_1(Point(450, 90), 150, 50);
	r_1_1.set_fill_color(Color::white);
	r_1_1.set_color(Color::black);
	win.attach(r_1_1);

	Text t_1(Point(460, 110), "FLTK headers");
	t_1.set_color(Color::black);
	t_1.set_font(Font::times);
	t_1.set_font_size(15);
	win.attach(t_1);

	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_2(Point(700,100), 120, 50);
	r_2.set_fill_color(Color::white);
	r_2.set_color(Color::black);
	win.attach(r_2);

	Graph_lib::Rectangle r_2_0(Point(705, 105), 120, 50);
	r_2_0.set_fill_color(Color::white);
	r_2_0.set_color(Color::black);
	win.attach(r_2_0);

	Graph_lib::Rectangle r_2_1(Point(710, 110), 120, 50);
	r_2_1.set_fill_color(Color::white);
	r_2_1.set_color(Color::black);
	win.attach(r_2_1);

	Text t_2(Point(720, 130), "FLTK code");
	t_2.set_color(Color::black);
	t_2.set_font(Font::times);
	t_2.set_font_size(15);
	win.attach(t_2);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_3(Point(100, 280), 220, 100);
	r_3.set_fill_color(Color::white);
	r_3.set_color(Color::black);
	win.attach(r_3);

	Text t_3(Point(105, 275), "Graph.h:");
	t_3.set_color(Color::black);
	t_3.set_font(Font::times_bold);
	t_3.set_font_size(15);
	win.attach(t_3);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_4(Point(410, 230), 220, 100);
	r_4.set_fill_color(Color::white);
	r_4.set_color(Color::black);
	win.attach(r_4);

	Text t_4(Point(415, 225), "Window.h:");
	t_4.set_color(Color::black);
	t_4.set_font(Font::times_bold);
	t_4.set_font_size(15);
	win.attach(t_4);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_5(Point(600, 400), 220, 100);
	r_5.set_fill_color(Color::white);
	r_5.set_color(Color::black);
	win.attach(r_5);

	Text t_5(Point(605, 395), "GUI.h:");
	t_5.set_color(Color::black);
	t_5.set_font(Font::times_bold);
	t_5.set_font_size(15);
	win.attach(t_5);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_6(Point(60, 540), 200, 50);
	r_6.set_fill_color(Color::white);
	r_6.set_color(Color::black);
	win.attach(r_6);

	Text t_6(Point(65, 535), "Graph.cpp:");
	t_6.set_color(Color::black);
	t_6.set_font(Font::times_bold);
	t_6.set_font_size(15);
	win.attach(t_6);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_7(Point(300, 440), 200, 50);
	r_7.set_fill_color(Color::white);
	r_7.set_color(Color::black);
	win.attach(r_7);

	Text t_7(Point(305, 435), "window.cpp:");
	t_7.set_color(Color::black);
	t_7.set_font(Font::times_bold);
	t_7.set_font_size(15);
	win.attach(t_7);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_8(Point(640, 560), 120, 50);
	r_8.set_fill_color(Color::white);
	r_8.set_color(Color::black);
	win.attach(r_8);

	Text t_8(Point(645, 555), "GUI.cpp:");
	t_8.set_color(Color::black);
	t_8.set_font(Font::times_bold);
	t_8.set_font_size(15);
	win.attach(t_8);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_9(Point(120, 750), 250, 100);
	r_9.set_fill_color(Color::white);
	r_9.set_color(Color::black);
	win.attach(r_9);

	Text t_9(Point(125, 745), "chapter12.cpp:");
	t_9.set_color(Color::black);
	t_9.set_font(Font::times_bold);
	t_9.set_font_size(15);
	win.attach(t_9);

	Text t_9_0(Point(130, 770), "#include \"Graph.h\"");
	t_9_0.set_color(Color::black);
	t_9_0.set_font(Font::times_bold);
	t_9_0.set_font_size(15);
	win.attach(t_9_0);

	Text t_9_1(Point(130, 790), "#include \"Simple_window.h\"");
	t_9_1.set_color(Color::black);
	t_9_1.set_font(Font::times_bold);
	t_9_1.set_font_size(15);
	win.attach(t_9_1);

	Text t_9_2(Point(130, 810), "int main() { ... }");
	t_9_2.set_color(Color::black);
	t_9_2.set_font(Font::times_bold);
	t_9_2.set_font_size(15);
	win.attach(t_9_2);
	//////////////////////////////////////////////////////////
	Graph_lib::Rectangle r_10(Point(340, 580), 250, 100);
	r_10.set_fill_color(Color::white);
	r_10.set_color(Color::black);
	win.attach(r_10);

	Text t_10(Point(345, 575), "Simple_window.h:");
	t_10.set_color(Color::black);
	t_10.set_font(Font::times_bold);
	t_10.set_font_size(15);
	win.attach(t_10);
	//////////////////////////////////////////////////////////
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
