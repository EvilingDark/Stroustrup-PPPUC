#pragma once
#include <Graph.h>
#include <cmath>
#include <Add_Graph.h>

namespace Graph_lib {
	struct Binary_Tree : Shape {
		Binary_Tree(Point p, int level, int ww = 50, int hh = 50, int rr = 5)
			: l{ level }, w{ ww }, h{ hh }, r{ rr } {
			add(p);
			set_binary_points();
		}
		Binary_Tree() {}
	protected:
		int w;
		int h;
		int l;
		Color acolor{ fl_color() };
		vector<Point> vrp;
		Vector_ref<Text> vtx;
		void set_binary_points() {
			for (int i = 0; i <= l; ++i) {
				if (i == 1) {
					vrp.push_back(point(0));
					vtx.push_back(new Text({ point(0).x + r + r + 3, point(0).y + r + r }, ""));
				}
				if (i > 1) {
					int n = i - 1;
					n = pow(2, n);
					n /= 2;
					double ratio = l / i;
					for (int j = -n; j <= n; ++j)
						if (j != 0) {
							vrp.push_back({ point(0).x + int(ratio * w * j), point(0).y + h * (i - 1) });
							vtx.push_back(new Text({ point(0).x + int(ratio * w * j) + r + r + 3, point(0).y + h * (i - 1) + r + r }, ""));
						}
				}
			}
		}
		virtual void draw_text() const {
			for (int i = 0; i < vtx.size(); ++i) {
				if (vtx[i].label() != "") {
					int ofnt = fl_font();
					int osz = fl_size();
					fl_font(vtx[i].font().as_int(), vtx[i].font_size());
					fl_draw(vtx[i].label().c_str(), vtx[i].point(0).x, vtx[i].point(0).y);
					fl_font(ofnt, osz);
				}
			}
		}
		virtual void draw_arrowhead(Point p0, Point p1) const {
			if (acolor.visibility()) {
				fl_color(acolor.as_int());
				double a1 = p1.x - p0.x;
				double a2 = p1.y - p0.y;
				double b1 = 50;
				double b2 = 0;
				double cos_ab = (a1 * b1 + a2 * b2) / (sqrt(a1 * a1 + a2 * a2) * (sqrt(b1 * b1 + b2 * b2)));
				double degree_ab = acos(cos_ab) * 180 / PI;
				if (p1.y > p0.y) degree_ab = -degree_ab;
				int a = al * cos((degree_ab + d) * PI / 180.0);
				int b = al * sin((degree_ab + d) * PI / 180.0);
				fl_line(p1.x, p1.y, p1.x - a, p1.y + b);
				int a0 = al * cos((degree_ab - d) * PI / 180.0);
				int b0 = al * sin((degree_ab - d) * PI / 180.0);
				fl_line(p1.x, p1.y, p1.x - a0, p1.y + b0);
			}
		}
		virtual void draw_figure() const {
			for (Point p : vrp) {
				if (fill_color().visibility()) {	// fill
					fl_color(fill_color().as_int());
					fl_pie(p.x, p.y, r + r - 1, r + r - 1, 0, 360);
					fl_color(color().as_int());	// reset color
				}

				if (color().visibility()) {
					fl_color(color().as_int());
					fl_arc(p.x, p.y, r + r, r + r, 0, 360);

				}
			}
		}
		virtual void draw_arrow() const {
			for (int i = 1; i < vrp.size(); ++i) {
				if (acolor.visibility()) {
					fl_color(acolor.as_int());
					if (i > 2) {
						if (i % 2 == 0) {
							int n = i - 2;
							n /= 2;
							fl_line(vrp[n].x + r, vrp[n].y + r + r + 1, vrp[i].x + r, vrp[i].y - 1);
							if (ah == "UP")
								draw_arrowhead({ vrp[i].x + r, vrp[i].y - 1 }, { vrp[n].x + r, vrp[n].y + r + r + 1 });
							else if (ah == "DOWN")
								draw_arrowhead({ vrp[n].x + r, vrp[n].y + r + r + 1 }, { vrp[i].x + r, vrp[i].y - 1 });
						}
						else {
							int n = i - 1;
							n /= 2;
							fl_line(vrp[n].x + r, vrp[n].y + r + r + 1, vrp[i].x + r, vrp[i].y - 1);
							if (ah == "UP")
								draw_arrowhead({ vrp[i].x + r, vrp[i].y - 1 }, { vrp[n].x + r, vrp[n].y + r + r + 1 });
							else if (ah == "DOWN")
								draw_arrowhead({ vrp[n].x + r, vrp[n].y + r + r + 1 }, { vrp[i].x + r, vrp[i].y - 1 });
						}
					}

					else if (i == 1 || i == 2) {
						fl_line(vrp[0].x + r, vrp[0].y + r + r + 1, vrp[i].x + r, vrp[i].y - 1);
						if (ah == "UP")
							draw_arrowhead({ vrp[i].x + r, vrp[i].y - 1 }, { vrp[0].x + r, vrp[0].y + r + r + 1 });
						else if (ah == "DOWN")
							draw_arrowhead({ vrp[0].x + r, vrp[0].y + r + r + 1 }, { vrp[i].x + r, vrp[i].y - 1 });
					}

				}
			}
		}
	public:
		void set_arrowhead(string arrowhead, int arrow_length = 5, double degree = 30) {
			if (arrowhead == "UP" || arrowhead == "DOWN")
				ah = arrowhead;
			else
				error("arrowhead must be \"UP\" or \"DOWN\"");
			if (arrow_length <= 0)
				error("arrow_length <= 0");
			al = arrow_length;
			d = degree;
		}
		void draw_lines() const {
			draw_figure();
			draw_arrow();
			draw_text();
		}
		void set_text(int point_numb, string text) { vtx[point_numb].set_label(text); }
		void set_color_arrows(Color col) { acolor = col; }
		Color color_arrows() { return acolor; }
	private:
		int r;
		string ah;
		int al = 0;
		double d = 0;
	};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	struct Binary_Tree_Triangle : Binary_Tree {
		Binary_Tree_Triangle(Point p, int level, int ww = 50, int hh = 50, int side = 10) 
			: s{ side }  {
			add(p);
			w = ww;
			h = hh;
			l = level;
			set_binary_points();
		}
		void draw_figure() const {
			for (Point p : vrp) {
				vector<Point> pv;
				double d = -45;
				int a0 = s * cos(d * PI / 180.0);
				int b0 = s * sin(d * PI / 180.0);
				pv.push_back(Point(p.x + a0, p.y - b0));
				a0 = s * cos((d - 90) * PI / 180.0);
				b0 = s * sin((d - 90) * PI / 180.0);
				pv.push_back(Point(p.x + a0, p.y - b0));
				if (fill_color().visibility()) {
					fl_color(fill_color().as_int());
					fl_begin_complex_polygon();
					for (int i = 0; i < pv.size(); ++i)
						fl_vertex(pv[i].x, pv[i].y);
					fl_vertex(p.x, p.y);
					fl_end_complex_polygon();
					fl_color(color().as_int());	// reset color
				}

				if (color().visibility())
				{
					fl_line(pv[0].x, pv[0].y, pv[1].x, pv[1].y);
					fl_line(p.x, p.y, pv[0].x, pv[0].y);
					fl_line(p.x, p.y, pv[1].x, pv[1].y);
				}

			}
		}
		void draw_arrow() const {
			for (int i = 1; i < vrp.size(); ++i) {
				if (acolor.visibility()) {
					fl_color(acolor.as_int());
					int h = sqrt(pow(s, 2) / 2);
					if (i > 2) {
						if (i % 2 == 0) {
							int n = i - 2;
							n /= 2;
							fl_line(vrp[n].x, vrp[n].y + h + 1, vrp[i].x, vrp[i].y - 1);
							draw_arrowhead(vrp[n], vrp[i]);
						}
						else {
							int n = i - 1;
							n /= 2;
							fl_line(vrp[n].x, vrp[n].y + h + 1, vrp[i].x, vrp[i].y - 1);
							draw_arrowhead(vrp[n], vrp[i]);
						}
					}

					else if (i == 1 || i == 2) {
						fl_line(vrp[0].x, vrp[0].y + h + 1, vrp[i].x, vrp[i].y - 1);
						draw_arrowhead(vrp[i], vrp[0]);
					}
				}
			}
		}
	private:
		int s;
	};
}