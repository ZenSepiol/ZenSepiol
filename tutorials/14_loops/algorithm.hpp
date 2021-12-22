#include <vector>
#include <numeric>
#include <execution>

double CalculateSumForEach(const std::vector<double>& vector) noexcept
{
    double sum = 0.0;
    std::for_each(vector.cbegin(), vector.cend(),
             [&sum](const auto& element)
             {
                sum += element; 
             });
    return sum;
}


double CalculateSumAccumulate(const std::vector<double>& vector) noexcept
{
    return std::accumulate(vector.cbegin(), vector.cend(), 0.0);
}


double CalculateSumForEachParallel(const std::vector<double>& vector) noexcept
{
    double sum = 0.0;
    std::for_each(std::execution::par, vector.cbegin(), vector.cend(),
             [&sum](const auto& element)
             {
                sum += element; 
             });

    return sum;
}