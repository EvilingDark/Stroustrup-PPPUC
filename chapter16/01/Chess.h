#pragma once
#include </Users/Oleg Olvinskiy/source/repos/глава 16 упр 1/глава 16 упр 1/My_window.h>
#include <GUI.h>

namespace Graph_lib {
	struct Chess : My_window {
		Chess(Point xy, int w, int h, const string& title)
			: My_window(xy, w, h, title),
			first_col(Point(x_max() - 400, y_max() - 400), 50, 50, Menu::vertical, "1"),
			second_col(Point(x_max() - 350, y_max() - 400), 50, 50, Menu::vertical, "2"),
			third_col(Point(x_max() - 300, y_max() - 400), 50, 50, Menu::vertical, "3"),
			fourth_col(Point(x_max() - 250, y_max() - 400), 50, 50, Menu::vertical, "4")
		{
			first_col.attach(new Button(Point(x_max() - 400, y_max() - 400), 50, 50, "1", cb_1));
			first_col.attach(new Button(Point(x_max() - 400, y_max() - 350), 50, 50, "5", cb_5));
			first_col.attach(new Button(Point(x_max() - 400, y_max() - 300), 50, 50, "9", cb_1));
			first_col.attach(new Button(Point(x_max() - 400, y_max() - 250), 50, 50, "13", cb_5));
			second_col.attach(new Button(Point(x_max() - 350, y_max() - 400), 50, 50, "2", cb_2));
			second_col.attach(new Button(Point(x_max() - 350, y_max() - 350), 50, 50, "6", cb_6));
			second_col.attach(new Button(Point(x_max() - 350, y_max() - 300), 50, 50, "10", cb_2));
			second_col.attach(new Button(Point(x_max() - 350, y_max() - 250), 50, 50, "14", cb_6));
			third_col.attach(new Button(Point(x_max() - 300, y_max() - 400), 50, 50, "3", cb_3));
			third_col.attach(new Button(Point(x_max() - 300, y_max() - 350), 50, 50, "7", cb_7));
			third_col.attach(new Button(Point(x_max() - 300, y_max() - 300), 50, 50, "11", cb_3));
			third_col.attach(new Button(Point(x_max() - 300, y_max() - 250), 50, 50, "15", cb_7));
			fourth_col.attach(new Button(Point(x_max() - 250, y_max() - 400), 50, 50, "4", cb_4));
			fourth_col.attach(new Button(Point(x_max() - 250, y_max() - 400), 50, 50, "8", cb_8));
			fourth_col.attach(new Button(Point(x_max() - 250, y_max() - 400), 50, 50, "12", cb_4));
			fourth_col.attach(new Button(Point(x_max() - 250, y_max() - 400), 50, 50, "16", cb_8));
			attach(first_col);
			attach(second_col);
			attach(third_col);
			attach(fourth_col);
		}
	private:
		Menu first_col;
		Menu second_col;
		Menu third_col;
		Menu fourth_col;
		static void cb_1(Address, Address pw) {};
		static void cb_2(Address, Address pw) {};
		static void cb_3(Address, Address pw) {};
		static void cb_4(Address, Address pw) {};
		static void cb_5(Address, Address pw) {};
		static void cb_6(Address, Address pw) {};
		static void cb_7(Address, Address pw) {};
		static void cb_8(Address, Address pw) {};
	};
}