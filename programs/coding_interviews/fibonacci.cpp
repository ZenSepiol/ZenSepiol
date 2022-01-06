#include <icecream.hpp>

void Fibonacci(uint32_t number)
{
    if (number == 0)
        return;

    uint32_t first_number = 0;
    IC(first_number);
    if (number == 1)
        return;
    
    uint32_t second_number = 1;    
    IC(second_number);

    for (uint32_t i = 2; i < number; ++i)
    {
        uint32_t new_number = first_number + second_number;
        IC(new_number);

        first_number = second_number;
        second_number = new_number;
    }
}

int main(int, char**)
{
    // 3) Fibonacci Sequence: 0, 1, 1, 2, 3, 5 ... 
    Fibonacci(10);

    return 0;
}