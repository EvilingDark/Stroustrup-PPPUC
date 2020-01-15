#pragma once
#include "Graph.h"

namespace Graph_lib{
	struct Group {
		Group() {}
		void add_Shape(Shape& sp) {
			shapes.push_back(sp);
		}
		void set_color(Color c) {
			for (int i = 0; i < shapes.size(); ++i)
				shapes[i].set_color(c);
		}
		void set_fill_color(Color c) {
			for (int i = 0; i < shapes.size(); ++i)
				shapes[i].set_fill_color(c);
		}
		virtual void move(int dx, int dy) {
			for (int i = 0; i < shapes.size(); ++i)
				shapes[i].move(dx, dy);
		}
	protected:
		Vector_ref<Shape> shapes;
	};
}