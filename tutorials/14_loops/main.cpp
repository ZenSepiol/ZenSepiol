#include <icecream.hpp>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <thread>

#include "classic.hpp"
#include "iterator.hpp"
#include "range.hpp"
#include "algorithm.hpp"

template< typename T> void benchmark(const std::vector<double>& values, T function, const std::string& name)
{
    // Get starting timepoint
    auto start = std::chrono::high_resolution_clock::now();
    
    // Execute the function
    auto sum = function(values);

    // Get ending timepoint
    auto stop = std::chrono::high_resolution_clock::now();
    
    // Calculate time and output result
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    IC(name, sum, duration.count());
}


int main()
{
    std::vector<double> values(10000000);  
    // Generate Random values
    auto f = []() -> double { return rand() / 10000.0; };  
    // Fill up the vector
    std::generate(values.begin(), values.end(), f);
  
    benchmark(values, CalculateSumClassicWrong,"CalculateSumClassicWrong");
    benchmark(values, CalculateSumClassic,"CalculateSumClassic");
    benchmark(values, CalculateSumIterator,"CalculateSumIterator");
    benchmark(values, CalculateSumRange,"CalculateSumRange");
    benchmark(values, CalculateSumForEach,"CalculateSumForEach");
    benchmark(values, CalculateSumAccumulate,"CalculateSumAccumulate");
    benchmark(values, CalculateSumForEachParallel,"CalculateSumForEachParallel");
  
    return 0;
}