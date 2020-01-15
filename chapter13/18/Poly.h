#pragma once
#include "Graph.h"

#define PI 3.14159265
namespace Graph_lib {
	struct Poly : Polygon {
		Poly() {}
		void add(Point p)
		{
			if (number_of_points() >= 3)
			{
				int max_x = point(0).x;
				int min_x = point(0).x;
				int max_y = point(0).y;
				int min_y = point(0).y;
				for (int i = 0; i < number_of_points(); ++i)  //ищем центр фигуры
				{
					if (max_x < point(i).x)
						max_x = point(i).x;
					if (min_x > point(i).x)
						min_x = point(i).x;
					if (max_y < point(i).y)
						max_y = point(i).y;
					if (min_y < point(i).y)
						min_y = point(i).y;
				}
				int poly_x = min_x + max_x / 2;
				int poly_y = min_y + max_y / 2;
				for (int i = 0; i < number_of_points() - 2; ++i)
				{
					int a1 = point(i).x - point(i + 1).x;
					int a2 = point(i).y - point(i + 1).y;
					int b1 = poly_x - point(i + 1).x;
					int b2 = poly_y - point(i + 1).y;
					int c1 = point(i + 2).x - point(i + 1).x;
					int c2 = point(i + 2).y - point(i + 1).y;
					double cos_ab = (a1 * b1 + a2 * b2) / (sqrt(a1 * a1 + a2 * a2) * (sqrt(b1 * b1 + b2 * b2)));
					double degree_ab = acos(cos_ab) * 180 / PI;
					double cos_bc = (c1 * b1 + c2 * b2) / (sqrt(c1 * c1 + c2 * c2) * (sqrt(b1 * b1 + b2 * b2)));
					double degree_bc = acos(cos_bc) * 180 / PI;
					cout << i << " " << " a1= " << a1 << " ,a2= " << a2 << " ,b1= " << b1 << " ,b2= " << b2
						<< " ,c1= " << c1 << " ,c2= " << c2 << "  " << degree_ab << "  " << degree_bc << endl << endl;
					//if (degree_ab + degree_bc > 180) error("Not a poly");
				}
			}
			Polygon::add(p);
		}
		void draw_lines() const
		{
			Polygon::draw_lines();
		}
	};
}