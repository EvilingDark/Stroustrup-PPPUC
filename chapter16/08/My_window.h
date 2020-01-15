#pragma once
#include <GUI.h>
#include <time.h>
#include <map>

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

	struct Analog_clock : My_window {
		Analog_clock(Point xy, int w, int h, const string& title)
			: My_window(xy, w, h, title),
			p_centr(x_max() / 2, y_max() / 2),
			clock(Point(p_centr.x, p_centr.y), x_max() / 4),
			second_0(Point(x_max() / 2 - 5, y_max() / 2 - x_max() / 4 - 10), "0"),
			second_15(Point(x_max() / 2 + x_max() / 4 + 10, y_max() / 2), "15"),
			second_30(Point(x_max() / 2 - 5, y_max() / 2 + x_max() / 4 + 15), "30"),
			second_45(Point(x_max() / 2 - x_max() / 4 - 20, y_max() / 2), "45")
		{
			clock.set_color(Color(Color::blue));
			clock.set_style(Line_style(Line_style::solid, 3));
			attach(clock);
			second_0.set_color(Color::dark_blue);
			second_0.set_font_size(x_max() / 50);
			second_15.set_color(Color::dark_blue);
			second_15.set_font_size(x_max() / 50);
			second_30.set_color(Color::dark_blue);
			second_30.set_font_size(x_max() / 50);
			second_45.set_color(Color::dark_blue);
			second_45.set_font_size(x_max() / 50);
			attach(second_0);
			attach(second_15);
			attach(second_30);
			attach(second_45);
		}
	private:
		Point p_centr;
		Circle clock;
		Text second_0;
		Text second_15;
		Text second_30;
		Text second_45;
		Vector_ref<Line> lines;
		const double PI = 3.14159265;
		const int l_sec_hand = x_max() * 2 / 9;
		void next() {
			//while (true) {
				int old_st = 0;
				SYSTEMTIME st;
				GetLocalTime(&st);
				if (st.wSecond != old_st) {
					int sec_a0 = l_sec_hand * cos((st.wSecond * 6 * PI) / 180.0);
					int sec_b0 = l_sec_hand * sin((st.wSecond * 6 * PI) / 180.0);
					cout << sec_a0 << " " << sec_b0 << " " << p_centr.x << " " << st.wSecond << endl;
					//Line sec_hand(Point(p_centr.x, p_centr.y), Point(p_centr.x + sec_a0, p_centr.y - sec_b0));
					//Line sec_hand(Point(p_centr.x, p_centr.y), Point(p_centr.x + 100, p_centr.y - 100));
					//sec_hand.set_color(Color(Color::black));
					//sec_hand.set_style(Line_style(Line_style::solid, 4));
					if (lines.size() != 0)
						detach(lines[lines.size() - 1]);
					lines.push_back(new Line(Point(p_centr.x, p_centr.y), Point(p_centr.x + sec_a0, p_centr.y - sec_b0)));
					attach(lines[lines.size() - 1]);
					Fl::redraw();
				}
				Sleep(999);
				old_st = st.wSecond;
			//}
		}
	};

	struct Cur_convertor : My_window {
		Cur_convertor(Point xy, int w, int h, const string& title)
			: My_window(xy, w, h, title),
			inb(Point(150, 100), 100, 30, ""),
			outb(Point(350, 100), 100, 30, ""),
			num_origin(Point(100, 100), 50, 30, ""),
			num_total(Point(300, 100), 50, 30, ""),
			cur_old(Point(150, 130), 100, 30, Menu::vertical, ""),
			cur_new(Point(350, 130), 100, 30, Menu::vertical, ""),
			do_it(Point(250, 100), 50, 30, "Do", cb_do)
		{
			attach(inb);
			attach(outb);
			attach(num_origin);
			attach(num_total);
			cur_old.attach(new Button(Point(150, 130), 100, 30, "RUR", cb_old_rur));
			cur_old.attach(new Button(Point(150, 160), 100, 30, "USD", cb_old_usd));
			cur_old.attach(new Button(Point(150, 190), 100, 30, "EUR", cb_old_eur));
			cur_old.attach(new Button(Point(150, 220), 100, 30, "GBP", cb_old_gbp));
			cur_new.attach(new Button(Point(350, 130), 100, 30, "RUR", cb_new_rur));
			cur_new.attach(new Button(Point(350, 130), 100, 30, "USD", cb_new_usd));
			cur_new.attach(new Button(Point(350, 130), 100, 30, "EUR", cb_new_eur));
			cur_new.attach(new Button(Point(350, 130), 100, 30, "GBP", cb_new_gbp));
			attach(cur_old);
			attach(cur_new);
			attach(do_it);
			exc_rates("123.txt");
		}
	private:
		map<string, double> c_RUR;
		map<string, double> c_USD;
		map<string, double> c_EUR;
		map<string, double> c_GBP;
		map<string, map<string, double>*> currencys;
		Menu cur_old;
		Menu cur_new;
		In_box inb;
		Out_box outb;
		Out_box num_origin;
		Out_box num_total;
		string origin;
		string total;
		Button do_it;
		void write_to_num(string box, string currency) {
			if (box == "old") {
				num_origin.put(currency);
				origin = currency;
			}
			if (box == "new") {
				num_total.put(currency);
				total = currency;
			}
		}
		void count() {
			if (origin == total) {
				cout << "error0" << endl;
				return;
			}
			else if (origin == "RUR") {
				double d = inb.get_int() / c_RUR[total];
				outb.put(d);
			}
			else if (origin == "USD") {
				double d = inb.get_int() / c_USD[total];
				outb.put(d);
			}
			else if (origin == "EUR") {
				double d = inb.get_int() / c_EUR[total];
				outb.put(d);
			}
			else if (origin == "GBP") {
				double d = inb.get_int() / c_GBP[total];
				outb.put(d);
			}
		}
		static void cb_old_rur(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("old", "RUR");
		}
		static void cb_old_usd(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("old", "USD");
		}
		static void cb_old_eur(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("old", "EUR");
		}
		static void cb_old_gbp(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("old", "GBP");
		}
		static void cb_new_rur(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("new", "RUR");
		}
		static void cb_new_usd(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("new", "USD");
		}
		static void cb_new_eur(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("new", "EUR");
		}
		static void cb_new_gbp(Address, Address pw) {
			reference_to<Cur_convertor>(pw).write_to_num("new", "GBP");
		}
		static void cb_do(Address, Address pw) {
			reference_to<Cur_convertor>(pw).count();
		}
		void exc_rates(string iname) 
		try
		{
			setlocale(LC_ALL, "Russian");
			ifstream ifst(iname);
			if (!ifst) error("Невозможно открыть входной файл", iname);
			char ch0;
			string st0, st1, st2, st3;
			double d1, d2, d3;
			while (ifst >> ch0)
			{
				if (ch0 == '(') {
					ifst >> ch0 >> st0 >> ch0 >> st1 >> d1 >> st2 >> d2 >> st3 >> d3 >> ch0;
					if (st0 == "RUR") {
						c_RUR.insert(make_pair(st1, d1));
						c_RUR.insert(make_pair(st2, d2));
						c_RUR.insert(make_pair(st3, d3));
					}
					if (st0 == "USD") {
						c_USD.insert(make_pair(st1, d1));
						c_USD.insert(make_pair(st2, d2));
						c_USD.insert(make_pair(st3, d3));
					}
					if (st0 == "EUR") {
						c_EUR.insert(make_pair(st1, d1));
						c_EUR.insert(make_pair(st2, d2));
						c_EUR.insert(make_pair(st3, d3));
					}
					if (st0 == "GBP") {
						c_GBP.insert(make_pair(st1, d1));
						c_GBP.insert(make_pair(st2, d2));
						c_GBP.insert(make_pair(st3, d3));
					}
				}
			}
			for (auto p : c_RUR)
				cout << p.first << " " << p.second << endl;
			for (auto p : c_USD)
				cout << p.first << " " << p.second << endl;
			for (auto p : c_EUR)
				cout << p.first << " " << p.second << endl;
			for (auto p : c_GBP)
				cout << p.first << " " << p.second << endl;
		}
		catch (exception& e) {
			cerr << "Exception: " << e.what() << endl;
			return;
		}
	};
}