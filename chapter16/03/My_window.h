#pragma once
#include <GUI.h>
#include <std_lib_facilities.h>

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

	struct Image_Button : My_window {
		Image_Button(Point xy, int w, int h, const string& title)
			: My_window(xy, w, h, title),
			Image(Point(x_max() - 400, y_max() - 400), 50, 50, "", cb_1),
			img(Point(x_max() - 400, y_max() - 400), "button.jpg")
		{
			attach(Image);
			attach(img);
		}
	private:
		Button Image;
		Graph_lib::Image img;
		void move_img() {
			int x = 50 * randint(4);
			int y = 50 * randint(4);
			if (randint(1) == 0)
				x = -x;
			if (randint(1) == 0)
				x = -y;
			Image.move(x, y);
			img.move(x, y);
			Fl::redraw();
		};
		static void cb_1(Address, Address pw) {
			reference_to<Image_Button>(pw).move_img();
		};
	};
}