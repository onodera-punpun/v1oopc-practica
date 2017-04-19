#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "window.hpp"
#include "line.hpp"

class rectangle {
private:
	line left, right, top, bottom;
public:
	rectangle(window &w, int start_x, int start_y, int end_x, int end_y);
	void print();
};

#endif
