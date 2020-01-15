#pragma once
#include <GUI.h>

namespace Graph_lib {
	struct My_window : Window {
		My_window(Point xy, int w, int h, const string& title)
			: Window(xy, w, h, title),
			button_pushed(false),
			next_button(Point(x_max() - 70, 30), 70, 20, "Next", cb_next),
			quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit)
		{
			attach(next_button);
			attach(quit_button);
		}
		void wait_for_button()
			// modified event loop
			// handle all events (as per default), but quit when button_pushed becomes true
			// this allows graphics without control inversion
		{
			while (!button_pushed) Fl::wait();
			button_pushed = false;
			Fl::redraw();
		}
		Button next_button;
	private:
		Button quit_button;
		void quit()
		{
			hide();
		}
		bool button_pushed;
		static void cb_next(Address, Address addr) // callback for next_button
		{
			reference_to<My_window>(addr).next();
		}
		static void cb_quit(Address, Address addr) // callback for next_button
		{
			reference_to<My_window>(addr).quit();
		}
		void next() { button_pushed = true; }
	};

	struct Chess : My_window {
		Chess(Point xy, int w, int h, const string& title)
			: My_window(xy, w, h, title),
			first_col(Point(x_max() - 400, y_max() - 400), 50, 50, Menu::vertical, "1"),
			second_col(Point(x_max() - 350, y_max() - 400), 50, 50, Menu::vertical, "2"),
			third_col(Point(x_max() - 300, y_max() - 400), 50, 50, Menu::vertical, "3"),
			fourth_col(Point(x_max() - 250, y_max() - 400), 50, 50, Menu::vertical, "4"),
			number(Point(x_max()-70, 60), 70,20,"")
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
			attach(number);
		}
	private:
		Menu first_col;
		Menu second_col;
		Menu third_col;
		Menu fourth_col;
		Out_box number;
		void ch_num(int a) {
			number.put(a);
		};
		static void cb_1(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(1);
		};
		static void cb_2(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(2);
		};
		static void cb_3(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(3);
		};
		static void cb_4(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(4);
		};
		static void cb_5(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(5);
		};
		static void cb_6(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(6);
		};
		static void cb_7(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(7);
		};
		static void cb_8(Address, Address pw) {
			reference_to<Chess>(pw).ch_num(8);
		};
	};
}