#include <vector>

double CalculateSumIterator(const std::vector<double>& vector) noexcept
{
    double sum = 0.0;
    for (auto it = vector.cbegin(); it < vector.cend(); ++it)
    {
        sum += *it;
    }
    return sum;
}

// Bad examples with two common mistakes 
double CalculateSumIterator2(const std::vector<double>& vector) noexcept
{
    double sum = 0.0;
    for (auto it = vector.begin(); it < vector.end(); it++)
    {
        sum += *it;
    }
    return sum;
}

