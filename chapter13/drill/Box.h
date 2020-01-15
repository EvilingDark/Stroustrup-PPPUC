#pragma once
#include "Graph.h"
#include "Arc.h"

namespace Graph_lib {
	struct Box : Shape {
		Box(Point p, int ww, int hh, int rr) 
			: w{ ww }, h{ hh }, r{ rr } {
			if (2 * rr > hh) error("Height more than 2*radius");
			if (2 * rr > ww) error("Width more than 2*radius");
			add(p);
			//arc0 = Graph_lib::Arc(Point{ p.x + r,p.y + r }, r, 90, 180);
//			arc0.to_assign(Graph_lib::Arc(Point{ p.x + r,p.y + r }, r, 90, 180));
//			arc1.to_assign(Graph_lib::Arc(Point{ p.x + r,h - r }, r, 180, 270));
//			arc2.to_assign(Graph_lib::Arc(Point{ w - r,p.y + r }, r, 0, 90));
//			arc3.to_assign(Graph_lib::Arc(Point{ w - r,h - r }, r, 270, 0));
			ln.add({ p.x + r,p.y }, { w - r,p.y });
			ln.add({ w,p.y + r }, { w,h - r });
			ln.add({ p.x + r,h - r }, { w - r,h - r });
			ln.add({ p.x,p.y + r }, { p.x,h - r });
		}
		void set_color(Graph_lib::Color c)
		{
			ln.set_color(c);
			arc0.set_color(c);
			arc1.set_color(c);
			arc2.set_color(c);
			arc3.set_color(c);
		}
		void draw_lines() const { 
			arc0.draw_lines(); arc1.draw_lines(); arc2.draw_lines(); arc3.draw_lines();
		}
		
	private:
		int w;
		int h;
		int r;
		Graph_lib::Arc arc0;
		Graph_lib::Arc arc1;
		Graph_lib::Arc arc2;
		Graph_lib::Arc arc3;
		Lines ln;
	};
}

