#include <iostream>
#include <string>

class Name
{
  public:
    Name() = default;
    virtual ~Name() = default;

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


class MyClass : public Name
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