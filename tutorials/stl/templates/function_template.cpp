#include <icecream.hpp>

template <typename Scalar>
Scalar sum(Scalar scalar_1, Scalar scalar_2) {
  return scalar_1 + scalar_2;
}

int main() {
  int number_1 = 10;
  int number_2 = 20;

  int number_3 = sum(number_1, number_2);

  double double_1 = 10.0;
  double double_2 = 20.0;

  double double_3 = sum(double_1, double_2);

  IC(number_3);
  IC(double_3);
}