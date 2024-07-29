#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(float, float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();
		float get_x() const;
		float get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif