#include "Point.hpp"


int main( void ) {
    const Point a = Point(0, 0);
    const Point b = Point(0, 4);
    const Point c = Point(4, 0);
    const Point p = Point(0.5, 0.5);

    bool res = bsp(a, b, c, p);

    if (res)
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    return 0;
}

