#pragma once
#include <GUI.h>
#include <Add_Graph.h>

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
	protected:
		virtual void next() { button_pushed = true; }
	};

	struct Chess : My_window {
		Chess(Point xy, int w, int h, const string& title)
			: My_window(xy, w, h, title),
			figure(Point(x_max() - 70, 60), 70, 20, Menu::vertical, "Menu"),
			fig_button(Point(x_max() - 70, 60), 70, 20, "Figures", cb_5),
			x(Point(x_max() - 230, 0), 70, 20, "x:"),
			y(Point(x_max() - 140, 0), 70, 20, "y:"),
			height(Point(x_max() - 140, 20), 70, 20, "h:"),
			width(Point(x_max() - 230, 20), 70, 20, "w:")
		{
			figure.attach(new Button(Point(x_max() - 70, 60), 70, 20, "Circle", cb_1));
			figure.attach(new Button(Point(x_max() - 70, 90), 70, 20, "Rectangle", cb_2));
			figure.attach(new Button(Point(x_max() - 70, 120), 70, 20, "Eq triangle", cb_3));
			figure.attach(new Button(Point(x_max() - 70, 150), 70, 20, "Hexagon", cb_4));
			attach(fig_button);
			attach(figure);
			figure.hide();
			attach(x);
			attach(y);
			attach(height);
			attach(width);
		}
	private:
		Vector_ref<Shape> shapes;
		In_box x;
		In_box y;
		In_box height;
		In_box width;
		Button fig_button;
		Menu figure;
		void cb_circle() {
			shapes.push_back(new Circle(Point(x.get_int(), y.get_int()), width.get_int() + height.get_int()));
			attach(shapes[shapes.size() - 1]);
			figure.hide();
			fig_button.show();
			Fl::redraw();
		};
		void cb_rec() {
			shapes.push_back(new Rectangle(Point(x.get_int(), y.get_int()), width.get_int(), height.get_int()));
			attach(shapes[shapes.size() - 1]);
			figure.hide();
			fig_button.show();
			Fl::redraw();
		};
		void cb_eq_tri() {
			shapes.push_back(new Right_Triangle(Point(x.get_int(), y.get_int()), width.get_int() + height.get_int(), width.get_int() + height.get_int()));
			attach(shapes[shapes.size() - 1]);
			figure.hide();
			fig_button.show();
			Fl::redraw();
		};
		void cb_hex() {
			shapes.push_back(new Regular_hexagon(Point(x.get_int(), y.get_int()), width.get_int() + height.get_int()));
			attach(shapes[shapes.size() - 1]);
			figure.hide();
			fig_button.show();
			Fl::redraw();
		};
		void cb_show_menu() {
			fig_button.hide();
			figure.show();
			Fl::redraw();
		};
		void next() {
			shapes[shapes.size() - 1].move(x.get_int(), y.get_int());
			Fl::redraw();
		}
		static void cb_1(Address, Address pw) {
			reference_to<Chess>(pw).cb_circle();
		};
		static void cb_2(Address, Address pw) {
			reference_to<Chess>(pw).cb_rec();
		};
		static void cb_3(Address, Address pw) {
			reference_to<Chess>(pw).cb_eq_tri();
		};
		static void cb_4(Address, Address pw) {
			reference_to<Chess>(pw).cb_hex();
		};
		static void cb_5(Address, Address pw) {
			reference_to<Chess>(pw).cb_show_menu();
		};
	};
}