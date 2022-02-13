#include <icecream.hpp>

template <typename Scalar>
class Point {
 private:
  Scalar x;
  Scalar y;

 public:
  Point(Scalar x, Scalar y);

  void print();
};

template<typename Scalar>
Point<Scalar>::Point(Scalar x, Scalar y) : x(x), y(y) {};

template<typename Scalar>
void Point<Scalar>::print()
{
    IC(x);
    IC(y);
    IC();
};


int main() 
{
    Point<double> p_double(1.0, 2.0);
    p_double.print();
    
    Point<int> p_int(1, 2);
    p_int.print();

    return 0;
}