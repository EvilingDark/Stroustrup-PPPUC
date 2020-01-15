#pragma once
#include <Graph.h>
#include <Add_Graph.h>

namespace Graph_lib {
	struct Smiley : Circle {
		using Circle::Circle;
		
		void draw_lines() const {
			Circle::draw_lines();
			Circle l_eye({ point(0).x + radius() / 2,point(0).y + radius() / 3 * 2 }, radius() / 3.5);
			l_eye.set_fill_color(Color::black);
			l_eye.set_color(Color::black);
			l_eye.draw_lines();
			Circle r_eye({ point(0).x + radius() / 2 + radius(),point(0).y + radius() / 3 * 2 }, radius() / 3.5);
			r_eye.set_fill_color(Color::black);
			r_eye.set_color(Color::black);
			r_eye.draw_lines();
			Ellipse mouth({ point(0).x + radius(), point(0).y + radius() / 3 + radius() }, radius() / 2, radius() / 6);
			mouth.set_fill_color(Color::white);
			mouth.set_color(Color::black);
			mouth.draw_lines();
			Line ln({ point(0).x + radius() / 2,point(0).y + radius() / 3 + radius() }, { point(0).x + 3 * radius() / 2,point(0).y + radius() / 3 + radius() });
			ln.set_color(Color::black);
			ln.draw();
		}
	};

	struct Smiley_w_hat : Circle {
		using Circle::Circle;

		void draw_lines() const {
			Smiley sm({ point(0).x + radius(), point(0).y + radius() }, radius());
			sm.set_fill_color(Color::yellow);
			sm.draw_lines();
			Ellipse mouth({ point(0).x + radius(), point(0).y }, radius() * 1.5, radius() / 6);
			mouth.set_fill_color(Color::black);
			mouth.set_color(Color::black);
			mouth.draw_lines();
			Rectangle rec({ point(0).x + radius() / 2, point(0).y - radius() / 3 * 2 }, radius(), radius() / 3 * 2);
			rec.set_fill_color(Color::black);
			rec.draw_lines();
		}
	};
	
	struct Frowny : Circle {
		using Circle::Circle;

		void draw_lines() const {
			Circle::draw_lines();
			Circle l_eye({ point(0).x + radius() / 2,point(0).y + radius() / 3 * 2 }, radius() / 3.5);
			l_eye.set_fill_color(Color::black);
			l_eye.set_color(Color::black);
			l_eye.draw_lines();
			Circle r_eye({ point(0).x + radius() / 2 + radius(),point(0).y + radius() / 3 * 2 }, radius() / 3.5);
			r_eye.set_fill_color(Color::black);
			r_eye.set_color(Color::black);
			r_eye.draw_lines();
			Arc mouth({ point(0).x + radius(), point(0).y + radius() / 3 * 2 + radius() }, radius() / 2, 30, 150);
			mouth.set_style(Line_style(Line_style::solid));
			mouth.draw_lines();
		}
	};

	struct Frowny_w_hat : Circle {
		using Circle::Circle;

		void draw_lines() const {
			Frowny sm({ point(0).x + radius(), point(0).y + radius() }, radius());
			sm.set_fill_color(Color::yellow);
			sm.draw_lines();
			Ellipse mouth({ point(0).x + radius(), point(0).y }, radius() * 1.5, radius() / 6);
			mouth.set_fill_color(Color::black);
			mouth.set_color(Color::black);
			mouth.draw_lines();
			Rectangle rec({ point(0).x + radius() / 2, point(0).y - radius() / 3 * 2 }, radius(), radius() / 3 * 2);
			rec.set_fill_color(Color::black);
			rec.draw_lines();
		}
	};
}