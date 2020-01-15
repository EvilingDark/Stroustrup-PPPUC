#pragma once
#include <Graph.h>

namespace Graph_lib {
	struct bar_graph : Shape {
		bar_graph(Point p, int xmax, int ymax) {
			add(p);
			if (xmax < 1 && ymax < 1)
				error("xmax and ymax must be more 1");
			x_max = xmax;
			y_max = ymax;
		}
		void add_data(double d, string s = "", Color bar_c = Color::cyan, Color label_c = Color::black) {
			label.push_back(s);
			data.push_back(d); 
			col.push_back(bar_c); 
			lab_col.push_back(label_c);
		}
		void draw_lines() const {
			vector<double> max = data;
			sort(max.begin(), max.end());
			int y_dist = y_max / max[max.size() - 1];
			int x_dist = x_max / data.size();
			for (int i = 0; i < data.size(); ++i) {
				fl_color(col[i].as_int());
				fl_rectf(point(0).x + x_dist * i, point(0).y - y_dist * data[i], x_dist, y_dist * data[i]);
				fl_color(color().as_int());	// reset color
				int ofnt = fl_font();
				int osz = fl_size();
				fl_font(fnt.as_int(), fnt_sz);
				fl_color(lab_col[i].as_int());
				fl_draw(label[i].c_str(), point(0).x + x_dist * i, point(0).y - y_dist * data[i] - fnt_sz / 2);
				fl_color(color().as_int());	// reset color
				fl_font(ofnt, osz);
			}
		}
		void set_font(Font f) { fnt = f; }
		Font font() const { return Font(fnt); }

		void set_font_size(int s) { fnt_sz = s; }
		int font_size() const { return fnt_sz; }
	private:
		vector<string> label;
		vector<Color> lab_col;
		vector<Color> col;
		vector<double> data;
		int x_max;
		int y_max;
		Font fnt{ fl_font() };
		int fnt_sz{ (14 < fl_size()) ? fl_size() : 14 };	// at least 14 point
	};
}