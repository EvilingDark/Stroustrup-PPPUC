#pragma once
#include <Graph.h>

namespace Graph_lib {
	struct Immobile_Circle : Circle {
		using Circle::Circle;
		void move() = delete;
	};

}