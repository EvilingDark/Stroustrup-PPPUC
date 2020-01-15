#pragma once
#include <Graph.h>

namespace Graph_lib {
	struct Striped_Rectangle : Rectangle {
		using Rectangle::Rectangle;
		void draw_lines() const {
			Rectangle::draw_lines();
			for (int i = 3; i < width(); i += 3) 
				fl_line(point(0).x + i, point(0).y, point(0).x + i, point(0).y + height());
		}
	};

	struct Striped_Circle : Circle {
		using Circle::Circle;
		void draw_lines() const {
			constexpr double PI = 3.14159265;
			Circle::draw_lines();
			double angle = 180.0 / radius();
			for (int i = 3; i < radius(); i += 4) {
			int a = radius() * cos(angle * i * PI / 180.0);
			int b = radius() * sin(angle * i * PI / 180.0);
			fl_line(point(0).x + radius() - a, point(0).y + radius() - b + 1, point(0).x + radius() - a, point(0).y + radius() + b - 1);
			//fl_line(point(0).x + radius() + a, point(0).y + radius() - b + 1, point(0).x + radius() + a, point(0).y + radius() + b - 1);
			}
		}
	};
}