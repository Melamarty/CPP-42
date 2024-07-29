#include "Point.hpp"

Point::Point () : x(0), y(0)
{
}

Point::Point (const  Point &other): x(other.x), y(other.y)
{

}
Point::Point (float x, float y): x(x), y(y)
{

}

float Point::get_x() const
{
    return this->x.toFloat();
}
float Point::get_y() const
{
    return this->y.toFloat();
}

Point::~Point()
{
	// std::cout << "Default constructor called" << std::endl;
}