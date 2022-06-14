#include <iostream>
#include <string>

template <typename Derived>
class Named
{
  public:
    Named() = default;

    void SetName(const std::string& new_name)
    {
        name = new_name;
    }

    std::string GetName() const
    {
        return name;
    }

    void Print() const
    {
        std::cout << "My name is " << name << "." << std::endl;
    }

  private:
    std::string name;
};


class MyClass : public Named<MyClass>
{
  public:
    MyClass()
    {
        SetName("Test");
    };
};


int main(int, char**)
{
    MyClass my_object;
    my_object.Print();

    return 0;
}