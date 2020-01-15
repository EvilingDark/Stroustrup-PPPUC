#pragma once
#include <Graph.h>

namespace Direction_Graph {
	//for Rectangle
	Point n(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x + r.width() / 2, r.point(0).y }; }
	Point s(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x + r.width() / 2, r.point(0).y + r.height() }; }
	Point e(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x + r.width(), r.point(0).y + r.height() / 2 }; }
	Point w(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x, r.point(0).y + r.height() / 2 }; }

	Point center(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x + r.width() / 2, r.point(0).y + r.height() / 2 }; }

	Point ne(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x + r.width(), r.point(0).y }; }
	Point se(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x + r.width(), r.point(0).y + r.height() }; }
	Point sw(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x, r.point(0).y + r.height() }; }
	Point nw(const Graph_lib::Rectangle& r) { return Point{ r.point(0).x, r.point(0).y }; }
	//for Circle
	Point n(const Graph_lib::Circle& c) { return Point{ c.point(0).x + c.radius(), c.point(0).y }; }
	Point s(const Graph_lib::Circle& c) { return Point{ c.point(0).x + c.radius(), c.point(0).y + 2 * c.radius() }; }
	Point e(const Graph_lib::Circle& c) { return Point{ c.point(0).x + 2 * c.radius(), c.point(0).y + c.radius() }; }
	Point w(const Graph_lib::Circle& c) { return Point{ c.point(0).x, c.point(0).y + c.radius() }; }

	Point center(const Graph_lib::Circle& c) { return Point{ c.point(0).x + c.radius(), c.point(0).y + c.radius() }; }

	Point ne(const Graph_lib::Circle& c) { return Point{ c.point(0).x + 2 * c.radius(), c.point(0).y }; }
	Point se(const Graph_lib::Circle& c) { return Point{ c.point(0).x + 2 * c.radius(), c.point(0).y + 2 * c.radius() }; }
	Point sw(const Graph_lib::Circle& c) { return Point{ c.point(0).x, c.point(0).y + 2 * c.radius() }; }
	Point nw(const Graph_lib::Circle& c) { return Point{ c.point(0).x, c.point(0).y }; }
	//for Ellipse
	Point n(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x + e.major(), e.point(0).y }; }
	Point s(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x + e.major(), e.point(0).y + 2 * e.minor() }; }
	Point e(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x + 2 * e.major(), e.point(0).y + e.minor() }; }
	Point w(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x, e.point(0).y + e.minor() }; }

	Point center(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x + e.major(), e.point(0).y + e.minor() }; }

	Point ne(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x + 2 * e.major(), e.point(0).y }; }
	Point se(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x + 2 * e.major(), e.point(0).y + 2 * e.minor() }; }
	Point sw(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x, e.point(0).y + 2 * e.minor() }; }
	Point nw(const Graph_lib::Ellipse& e) { return Point{ e.point(0).x, e.point(0).y }; }
}

