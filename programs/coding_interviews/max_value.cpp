
#include <list>
#include <icecream.hpp>

template<typename T>
constexpr T MaxValue(const std::list<T>& list)
{
    T max_value = list.front();
    for (const auto& element : list)
    {
        if (max_value < element)
            max_value = element; 
    }
    return max_value;
}

template<typename T>
constexpr T MaxValueStd(const std::list<T>& list)
{
    return *std::max_element(list.begin(), list.end());
}

int main(int, char**)
{
    // 1) Find the maximum value of a std::list 
    std::list<int> list{0, 5, 2, 8, 9};
    IC(MaxValue(list));
    IC(MaxValueStd(list));

    return 0;
}
