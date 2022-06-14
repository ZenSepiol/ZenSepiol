#include <crtp_extension.hpp>

class Triangle : public Origin2d<Triangle>
{
  public:
    Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c){};

    void PrintAbsoluteCoordinates()
    {
        std::cout << "A is " << a.x + origin.x << "," << a.y + origin.y << std::endl;
        std::cout << "B is " << b.x + origin.x << "," << b.y + origin.y << std::endl;
        std::cout << "C is " << c.x + origin.x << "," << c.y + origin.y << std::endl << std::endl;
    }

  private:
    Point a;
    Point b;
    Point c;
};


class Quad : public Origin2d<Quad>
{
  public:
    Quad(const Point& a, const Point& b, const Point& c, const Point& d) : a(a), b(b), c(c), d(d)
    {
    }

    void PrintAbsoluteCoordinates()
    {
        std::cout << "A is " << a.x + origin.x << "," << a.y + origin.y << std::endl;
        std::cout << "B is " << b.x + origin.x << "," << b.y + origin.y << std::endl;
        std::cout << "C is " << c.x + origin.x << "," << c.y + origin.y << std::endl;
        std::cout << "D is " << d.x + origin.x << "," << d.y + origin.y << std::endl << std::endl;
    }

  private:
    Point a;
    Point b;
    Point c;
    Point d;
};



int main(int, char**)
{
    auto a = Point(0.f, 0.f);
    auto b = Point(1.f, 0.f);
    auto c = Point(0.f, 1.f);
    auto d = Point(1.f, 1.f);

    Triangle triangle(a, b, c);
    triangle.PrintAbsoluteCoordinates();
    triangle.TranslateOrigin(Point(5.f, 5.f));
    triangle.PrintAbsoluteCoordinates();

    Quad quad(a, b, c, d);
    quad.PrintAbsoluteCoordinates();
    quad.TranslateOrigin(Point(5.f, 5.f));
    quad.PrintAbsoluteCoordinates();

    return 0;
}