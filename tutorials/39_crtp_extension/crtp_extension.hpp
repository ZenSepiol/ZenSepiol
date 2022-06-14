#include <iostream>
#include <string>

struct Point
{
    Point() = default;
    Point(float x, float y) : x(x), y(y)
    {
    }

    float x = 0.f;
    float y = 0.f;
};

template <typename Derived>
class Origin2d
{
  friend Derived;

  public:
    Origin2d() = default;

    void TranslateOrigin(const Point& point)
    {
        origin.x += point.x;
        origin.y += point.y;
    }

    void PrintOrigin() const
    {
        std::cout << "My origin x is " << origin.x << "." << std::endl;
        std::cout << "My origin y is " << origin.y << "." << std::endl;
    }

  private:
    Point origin;
};
