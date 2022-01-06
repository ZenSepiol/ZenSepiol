
#include <icecream.hpp>

void FizzBuzz(int end)
{
    for(uint32_t i = 0; i <= end; ++i)
    {
        if ((i % 15) == 0)
            IC("FizzBuzz");
        else if((i % 5) == 0)
            IC("Buzz");
        else if((i % 3) == 0)
            IC("Fizz");
        else
            IC(i);
    }
}

int main(int, char**)
{
    // 4) Fizz Buzz
    // Print all numbers from 0 to 100
    // Print Fizz if divisible by 3
    // Print Buzz if divisible by 5
    // Print FizzBuzz if both

    FizzBuzz(100);

    return 0;
}