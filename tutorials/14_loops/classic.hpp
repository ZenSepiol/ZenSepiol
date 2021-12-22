#include <vector>

double CalculateSumClassic(const std::vector<double>& vector) noexcept
{
    double sum = 0.0;
    for (std::size_t i = 0; i < vector.size(); ++i)
    {
        sum += vector[i];
    }
    return sum;
}

// Bad examples with four common mistakes 
double CalculateSumClassicWrong(const std::vector<double>& vector)
{
    double sum = 0.0;
    double i;
    for (i = 0; i < vector.size(); i++)
    // for (auto i = 0; i < vector.size(); i++)
    {
        sum += vector.at(i);
    }
    return sum;
}