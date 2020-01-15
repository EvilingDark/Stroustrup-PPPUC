#pragma once
#include "Graph.h"

namespace Graph_lib {
	struct Arc : Shape {
		Arc(Point p, int rr, double ddb, double dde)
			: r{ rr }, db{ ddb }, de{ dde } {
			add(Point{ p.x - r, p.y - r });
		}
		Arc() {}
		Point center() const { return { point(0).x + r, point(0).y + r }; }

		void set_degree(double ddb, double dde) { db = ddb; de = dde; }
		void set_radius(int rr) { r = rr; }
		void set_point(Point p) { point(0) = p; }
		double begin_degree() const { return db; }
		double end_degree() const { return de; }
		int radius() const { return r; }

		void draw_lines() const
		{
			if (fill_color().visibility()) {	// fill
				fl_color(fill_color().as_int());
				fl_pie(point(0).x, point(0).y, r + r - 1, r + r - 1, db, de);
				fl_color(color().as_int());	// reset color
			}

			if (color().visibility()) {
				fl_color(color().as_int());
				fl_arc(point(0).x, point(0).y, r + r, r + r, db, de);
			}
		}
	private:
		int r;
		double db;
		double de;
	};
}