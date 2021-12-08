#include "stdint.h"

class Point{
    public:
    Point(float x, float y);

    float x;
    float y;
};

float GetArea(const Point& a, const Point& b, const Point& c);

class Shape{
    public:
    Shape(uint16_t id);

    virtual ~Shape() = default; 

    uint16_t GetId();

    virtual float GetArea() = 0;

    uint16_t id;
};

class Triangle : Shape{
    public:
    Triangle(const Point& a, const Point& b, const Point& c, uint16_t id);

    float GetArea() override;

    private:
    Point a;
    Point b;
    Point c;
};

class Quad : Shape{
    public:
    Quad(const Point& a, const Point& b, const Point& c, const Point& d, uint16_t id);

    float GetArea() override;

    private:
    Point a;
    Point b;
    Point c;
    Point d;
};