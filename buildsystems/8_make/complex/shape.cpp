#include <cmath>

#include "shape.h"

Point::Point(float x, float y) : x(x), y(y){};

float GetArea(const Point& a, const Point& b, const Point& c)
{
    return std::abs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x) / 2.0;
} 

Shape::Shape(uint16_t id): id(id){}

uint16_t Shape::GetId()
{
    return id;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c, uint16_t id): a(a), b(b), c(c), Shape(id){};

float Triangle::GetArea()
{
    return ::GetArea(a, b, c);
}

Quad::Quad(const Point& a, const Point& b, const Point& c, const Point& d, uint16_t id): a(a), b(b), c(c), d(d), Shape(id){};

float Quad::GetArea()
{
    return ::GetArea(a, b, d) + ::GetArea(b, d, c);
} 