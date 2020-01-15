#pragma once
#include "Graph.h"

namespace Graph_lib {
	struct Box : Shape {
		Box(Point p, int ww, int hh, int rr) 
			: w{ ww }, h{ hh }, r{ rr } {
			if (2 * rr > hh) error("Height more than 2*radius");
			if (2 * rr > ww) error("Width more than 2*radius");
			add(p);
		}
		Box() {}

		void set_radius(int rr) { r = rr; }
		void set_point(Point p) { point(0) = p; }
		void set_height(int hh) { h = hh; }
		void set_width(int ww) { w = ww; }
		int height() const { return h; }
		int width() const { return w; }
		int radius() { return r; }

		void draw_lines() const
		{
			if (fill_color().visibility()) {	// fill
				fl_color(fill_color().as_int());
				fl_pie(point(0).x, point(0).y, r + r, r + r, 90, 180);
				fl_pie(point(0).x, point(0).y + h - r - r, r + r, r + r, 180, 270);
				fl_pie(point(0).x + w - r - r, point(0).y, r + r, r + r, 0, 90);
				fl_pie(point(0).x + w - r - r, point(0).y + h - r - r, r + r, r + r, 270, 0);
				fl_rectf(point(0).x + r, point(0).y, w - r -r, h);
				fl_rectf(point(0).x, point(0).y + r, r, h - r - r);
				fl_rectf(point(0).x + w - r, point(0).y + r, r, h - r - r);
				fl_color(color().as_int());	// reset color
			}
			if (color().visibility()) {
				fl_color(color().as_int());
				fl_arc(point(0).x, point(0).y, r + r, r + r, 90, 180);
				fl_arc(point(0).x, point(0).y + h - r - r, r + r, r + r, 180, 270);
				fl_arc(point(0).x + w - r - r, point(0).y, r + r, r + r, 0, 90);
				fl_arc(point(0).x + w - r - r, point(0).y + h - r - r, r + r, r + r, 270, 0);
				fl_line(point(0).x + r, point(0).y,point(0).x + w - r, point(0).y);
				fl_line(point(0).x + w, point(0).y + r, point(0).x + w,point(0).y + h - r);
				fl_line(point(0).x + r, point(0).y + h, point(0).x + w - r, point(0).y + h);
				fl_line(point(0).x, point(0).y + r, point(0).x,point(0).y + h - r);
			}
		}
		
	private:
		int w;		//высота
		int h;		//ширина
		int r;
	};
}

