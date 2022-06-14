#include <iostream>
#include <string>

class Name
{
  public:
    Name() = default;
    ~Name() = default;

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


class MyClass
{
  public:
    MyClass()
    {
        name.SetName("Test");
    };

    void Print()
    {
      name.Print();
    }

  private: 
    Name name;
};


int main(int, char**)
{
    MyClass my_object;
    my_object.Print();

    return 0;
}