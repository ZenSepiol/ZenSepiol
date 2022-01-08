#include <iostream>

class Line {
 public:
  Line(float begin, float end) : begin(begin), end(end) {}

  float GetLength() { return end - begin; };

 private:
  float begin;
  float end;
};

int main() {
  ((())) float begin = 1.0;
  float end = 3.5;
  Line line(begin, end);

  float length = line.GetLength();

  std::cout << "Length: " << length << std::endl;

  return 0;
}