#include <iostream>

void print(const std::string& string)
{
    std::cout << string << std::endl;
}

void print(int number)
{
    std::cout << number << std::endl;
}


int main()
{
    print("Hello");
    print(5);

    return 0;
}  