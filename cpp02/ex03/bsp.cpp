#include "Point.hpp"

float area (Point const a, Point const b, Point const c)
{
	float area = a.get_x() * (b.get_y() - c.get_y());
	area += b.get_x() * (c.get_y() - a.get_y());
	area += c.get_x() * (a.get_y() - b.get_y());
	return (0.5 * abs(area));
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float total = area(a, b, c);
	float a1 = area(a, b, point);
	float a2 = area(a, c, point);
	float a3 = area(b, c, point);

	if (!a1 || !a2 || !a3 || total != a1 + a2 + a3)
		return false;
	return true;
}