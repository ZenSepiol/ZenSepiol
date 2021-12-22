#include <vector>

double CalculateSumRange(const std::vector<double>& vector) noexcept
{
    double sum = 0;
    for (const auto& element : vector)
    {
        sum += element;
    }
    return sum;
}

// Bad examples with one common mistake
double CalculateSumRange2(const std::vector<double>& vector) noexcept
{
    double sum = 0;
    for (auto& element : vector)
    {
        sum += element;
    }
    return sum;
}

