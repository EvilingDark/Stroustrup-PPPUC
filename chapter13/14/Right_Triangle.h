#pragma once
#include <Graph.h>

#define PI 3.14159265

namespace Graph_lib {
	struct Right_Triangle : Shape {
		Right_Triangle(Point p, int side_a, int side_b, double degree = 0) : a{ side_a }, b{ side_b }, d{ degree } {
			if (side_a <= 0) error("side_a must be more 0");
			if (side_b <= 0) error("side_b must be more 0");
			add(p);
		};
		void draw_lines() const {
			vector<Point> pv;
			int a0 = a * cos(d * PI / 180.0);
			int b0 = a * sin(d * PI / 180.0);
			pv.push_back(Point(point(0).x + a0, point(0).y - b0));
			a0 = b * cos((d-90) * PI / 180.0);
			b0 = b * sin((d-90) * PI / 180.0);
			pv.push_back(Point(point(0).x + a0, point(0).y - b0));
			if (fill_color().visibility()) {
				fl_color(fill_color().as_int());
				fl_begin_complex_polygon();
				for (int i = 0; i < pv.size(); ++i)
					fl_vertex(pv[i].x, pv[i].y);
				fl_vertex(point(0).x, point(0).y);
				fl_end_complex_polygon();
				fl_color(color().as_int());	// reset color
			}

			if (color().visibility())
			{
				fl_line(pv[0].x, pv[0].y, pv[1].x, pv[1].y);
				fl_line(point(0).x, point(0).y, pv[0].x, pv[0].y);
				fl_line(point(0).x, point(0).y, pv[1].x, pv[1].y);
			}
		}
		void set_side_a(int side_a) { if (side_a <= 0) error("side_a must be more 0"); a = side_a; }
		void set_side_b(int side_b) { if (side_b <= 0) error("side_b must be more 0"); b = side_b; }
		void set_degree(double degree) { d = degree; }
		int side_a() const { return a; }
		int side_b() const { return b; }
		double degree() const { return d; }
	private:
		int a;
		int b;
		double d;
	};
}