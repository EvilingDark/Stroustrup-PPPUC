#pragma once
#include <Graph.h>

#define PI 3.14159265

namespace Graph_lib {
	struct Regular_polygon : Shape {
		Regular_polygon(Point p, int nn, int rr) : r{ rr }, n{ nn } {
			if (rr <= 0) error("rr must be more 0");
			if (nn <= 2) error("nn must be more 2");
			add(p);
		};
		void draw_lines() const {
			vector<Point> pv;
			double angle = 360.0 / n;
			for (int i = 0; i < n; ++i)
			{
				int a = r * cos(angle * i * PI / 180.0);
				int b = r * sin(angle * i * PI / 180.0);
				pv.push_back(Point(point(0).x + a, point(0).y - b));
			}
			if (fill_color().visibility()) {
				fl_color(fill_color().as_int());
				fl_begin_complex_polygon();
				for (int i = 0; i < pv.size(); ++i)
					fl_vertex(pv[i].x, pv[i].y);
				fl_end_complex_polygon();
				fl_color(color().as_int());	// reset color
			}

			if (color().visibility())
			{
				for (int i = 0; i < pv.size() - 1; ++i)
					fl_line(pv[i].x, pv[i].y, pv[i + 1].x, pv[i + 1].y);
				fl_line(pv[pv.size() - 1].x, pv[pv.size() - 1].y, pv[0].x, pv[0].y);
			}
		}
		void set_side(int rr) { if (rr <= 0) error("rr must be more 0"); r = rr; }
		void set_num_of_sides(int nn) { if (nn <= 2) error("nn must be more 2"); n == nn; }
		int side() const { return r; }
		int num_of_sides() const { return n; }
	private:
		int r;
		int n;
	};
}