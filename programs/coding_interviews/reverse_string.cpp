#include <string>
#include <icecream.hpp>

std::string ReverseString(const std::string& string)
{
    std::string result;
    for (auto it = string.crbegin(); it < string.crend(); ++it)
    {
        result += *it;
    }
    return result;
}

int main(int, char**)
{
    // 2) Reverse a string 
    std::string my_string = "Hello Friend!";
    IC(my_string);
    IC(ReverseString(my_string));

    return 0;
}