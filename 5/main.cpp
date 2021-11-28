#include <iostream>

#include "shape.h"

int main()
{
    Point a(0, 0);
    Point b(1, 0);
    Point c(0, 1);
    Point d(1, 1);
    uint16_t id = 0;

    Triangle triangle(a, b, c, id);
    Quad quad(a, b, c, d, id);

    std::cout << "My triangles area is: " << triangle.GetArea() << std::endl;

    std::cout << "My quads area is: " << quad.GetArea() << std::endl;

    return 0;
}