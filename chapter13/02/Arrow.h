#pragma once
#include "Graph.h"

#define PI 3.14159265
namespace Graph_lib {
	struct Arrow : Shape {
		Arrow(Point p1, Point p2, int rr = 12, double dd = 30) : r{ rr }, d{ dd } { add(p1); add(p2); }

		void draw_lines() const
		{
			if (color().visibility())	// draw sole pixel?
			{
				fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
				double a1 = point(1).x-point(0).x;
				double a2 = point(1).y-point(0).y;
				double b1 = 50;
				double b2 = 0;
				double cos_ab = (a1 * b1 + a2 * b2) / (sqrt(a1 * a1 + a2 * a2) * (sqrt(b1 * b1 + b2 * b2)));
				double degree_ab = acos(cos_ab) * 180 / PI;
				if (point(1).y > point(0).y) degree_ab = -degree_ab;
				cout << "begin"<< endl << cos_ab << endl << degree_ab << endl << endl;
				int a = r * cos((degree_ab+d) * PI / 180.0);
				int b = r * sin((degree_ab+d) * PI / 180.0);
				cout << a << endl << b << endl << "end" << endl << endl;
				fl_line(point(1).x, point(1).y, point(1).x - a, point(1).y + b);
				int a0 = r * cos((degree_ab - d) * PI / 180.0);
				int b0 = r * sin((degree_ab - d) * PI / 180.0);
				fl_line(point(1).x, point(1).y, point(1).x - a0, point(1).y + b0);
				//fl_line(point(1).x - a, point(1).y + b, point(1).x - a0, point(1).y + b0);
			}
		}
		void set_radius(int rr) { r = rr; }
		void set_degree(double dd) { d = dd; }
		int radius() { return r; }
		double degree() { return d; }
	private:
		int r;
		double d;
	};
}