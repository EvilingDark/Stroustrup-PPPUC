#pragma once
#include <Add_Graph.h>

namespace Graph_lib {
	struct Octagon : Regular_polygon {
		Octagon(Point p, int rr) {
			if (rr <= 0) error("rr must be more 0");
			add(p);
			n = 8;
			r = rr;
		}
	};

}