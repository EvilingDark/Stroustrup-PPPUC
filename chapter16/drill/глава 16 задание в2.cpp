// глава 16 задание в2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Window.cpp>
#include <Simple_window.h>
#include <Graph.cpp>
#include <Point.h>
#include <GUI.cpp>
#include <std_lib_facilities.h>

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
	Open_polyline lines;
private:
	Button next_button;
	Button quit_button;
	Menu color_menu;
	Button menu_button;
	Menu lines_menu;
	Button lines_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	void menu_show();
	void lines_show();
	void next();
	void quit();
	void setup_color(Color c) { lines.set_color(c); }
	void red() { setup_color(Color::red); color_menu.hide(); menu_button.show(); }
	void cyan() { setup_color(Color::cyan); color_menu.hide(); menu_button.show(); }
	void black() { setup_color(Color::black); color_menu.hide(); menu_button.show(); }
	void setup_line_dash() { lines.set_style(Line_style(Line_style::dash)); lines_menu.hide(); lines_button.show(); }
	void setup_line_dashdot() { lines.set_style(Line_style(Line_style::dashdot)); lines_menu.hide(); lines_button.show(); }
	void setup_line_solid() { lines.set_style(Line_style(Line_style::solid)); lines_menu.hide(); lines_button.show(); }
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	next_button(Point(x_max() - 150, 0), 70, 20, "Next label",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).next();
		}),
	quit_button(Point(x_max() - 70, 0), 70, 20, "Quit",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).quit();
		}),
	menu_button(Point(x_max() - 70, y_max() - 360), 70, 20, "Color Menu",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).menu_show();
		}),
	lines_button(Point(x_max() - 150, y_max() - 360), 70, 20, "Lines style",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).lines_show();
		}),
	lines_menu(Point(x_max() - 150, y_max() - 360), 70, 20, Menu::vertical, "Lines style"),
	color_menu(Point(x_max() - 70, y_max()-360), 70, 20, Menu::vertical, "Color Menu"),
	next_x(Point(x_max() - 310, 0), 50, 20, "next x:"),
	next_y(Point(x_max() - 210, 0), 50, 20, "next_y:"),
	xy_out(Point(100, 0), 100, 20, "current (x,y):")
{
	attach(next_button);
	attach(quit_button);
	attach(menu_button);
	attach(lines_button);
	color_menu.attach(new Button(Point(x_max() - 70, y_max() - 360), 70, 20, "Black",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).black();
		}));
	color_menu.attach(new Button(Point(x_max() - 70, y_max() - 330), 70, 20, "Cyan",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).cyan();
		}));
	color_menu.attach(new Button(Point(x_max() - 70, y_max() - 300), 70, 20, "Red",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).red();
		}));
	attach(color_menu);
	color_menu.hide();
	lines_menu.attach(new Button(Point(x_max() - 150, y_max() - 360), 70, 20, "Dash",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).setup_line_dash();
		}));
	lines_menu.attach(new Button(Point(x_max() - 150, y_max() - 330), 70, 20, "Dashdot",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).setup_line_dashdot();
		}));
	lines_menu.attach(new Button(Point(x_max() - 150, y_max() - 300), 70, 20, "Solid",
		[](Address, Address pw) {
			reference_to<Lines_window>(pw).setup_line_solid();
		}));
	attach(lines_menu);
	lines_menu.hide();
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point(x, y));
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

void Lines_window::menu_show()
{
	menu_button.hide();
	color_menu.show();
}

void Lines_window::lines_show()
{
	lines_button.hide();
	lines_menu.show();
}

int main()
try
{
	Lines_window win(Point(100, 100), 600, 400, "Lines");
	return gui_main();
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << endl;
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
