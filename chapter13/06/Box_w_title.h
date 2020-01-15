#pragma once
#include <Graph.cpp>

namespace Graph_lib {
	struct Box_w_title : Shape {
		Box_w_title(Point p, int ww, int hh, int rr, string label)
			: w{ ww }, h{ hh }, r{ rr }, lab{ label } {
			if (2 * rr > hh) error("Height more than 2*radius");
			if (2 * rr > ww) error("Width more than 2*radius");
			if (h <= 0 || w <= 0) error("Bad rectangle_with_title: non-positive side");
			add(p);
		}

		void draw_lines() const {
/*			if (fill_color().visibility()) {	// fill
				fl_color(fill_color().as_int());
				if (r > 0) {
					fl_pie(point(0).x, point(0).y, r + r, r + r, 90, 180);
					fl_pie(point(0).x, point(0).y + h - r - r, r + r, r + r, 180, 270);
					fl_pie(point(0).x + w - r - r, point(0).y, r + r, r + r, 0, 90);
					fl_pie(point(0).x + w - r - r, point(0).y + h - r - r, r + r, r + r, 270, 0);
				}
				fl_rectf(point(0).x + r, point(0).y, w - r - r, h);
				fl_rectf(point(0).x, point(0).y + r, r, h - r - r);
				fl_rectf(point(0).x + w - r, point(0).y + r, r, h - r - r);
				fl_color(color().as_int());	// reset color
			}*/
			if (color().visibility()) {	// edge on top of fill
				int ofnt = fl_font();
				int osz = fl_size();
				fl_font(fnt.as_int(), fnt_sz);
				fl_draw(lab.c_str(), point(0).x + w / 2 - lab.length() * fnt_sz / 4, point(0).y + h / 2 + fnt_sz / 3.0);
				fl_font(ofnt, osz);

				fl_color(color().as_int());
				if (r > 0) {
					fl_arc(point(0).x, point(0).y, r + r, r + r, 90, 180);
					fl_arc(point(0).x, point(0).y + h - r - r, r + r, r + r, 180, 270);
					fl_arc(point(0).x + w - r - r, point(0).y, r + r, r + r, 0, 90);
					fl_arc(point(0).x + w - r - r, point(0).y + h - r - r, r + r, r + r, 270, 0);
				}
				fl_line(point(0).x + r, point(0).y, point(0).x + w - r, point(0).y);
				fl_line(point(0).x + w, point(0).y + r, point(0).x + w, point(0).y + h - r);
				fl_line(point(0).x + r, point(0).y + h, point(0).x + w - r, point(0).y + h);
				fl_line(point(0).x, point(0).y + r, point(0).x, point(0).y + h - r);
			}
		}

		void set_radius(int rr) { r = rr; }
		void set_label(string label) { lab = label; }
		void set_height(int hh) { h = hh; }
		void set_width(int ww) { w = ww; }

		int radius() { return r; }
		string label() const { return lab; }
		int height() const { return h; }
		int width() const { return w; }

		void set_font(Font f) { fnt = f; }
		Font font() const { return Font(fnt); }

		void set_font_size(int s) { fnt_sz = s; }
		int font_size() const { return fnt_sz; }
	private:
		int h;			// height
		int w;			// width
		int r;
		string lab;
		Font fnt{ fl_font() };
		int fnt_sz{ (14 < fl_size()) ? fl_size() : 14 };	// at least 14 point
	};
}