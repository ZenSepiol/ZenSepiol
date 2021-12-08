#include <iostream>

#include "shape.h"
#include "line.h"

int main()
{
    Point a(0.F,0.F);
    Point b(0.F,1.F);
    Point c(1.F,0.F);
    Triangle my_shape(a, b, c, 1U);

    Line my_line(0.F, 1.F);

    std::cout << "Hello Friend" << std::endl;

    return 0;
}