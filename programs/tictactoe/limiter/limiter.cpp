#include "limiter.hpp"

Limiter::Limiter(int limit) : limit(limit)
{
}

void Limiter::SetNumber(int input)
{
    if (limit < input)
        number = limit;
    else
        number = input;
}

int Limiter::GetNumber()
{
    return number;
}