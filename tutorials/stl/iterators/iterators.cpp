#include <icecream.hpp>
#include <iterator>
#include <vector>
#include <array>

template<typename T>
int sum_elements(T begin, T end)
{
    int result = 0;
    for(auto it = begin; it < end; ++it)
    {
        result += *it;
    }
    return result;
}

int main()
{
    // std::vector<int> vector = {0, 1, 2, 3, 4, 5};

    // Input Iterator 
    // IC( *std::find(vector.begin(), vector.end(), 2) );

    // Output Iterator 
    // std::vector<int> destination(6);
    // std::copy(vector.begin(), vector.end(), destination.begin());
    // IC( destination );

    // Forward Iterator 
    // std::vector<int> sequence = { 3, 4, 5 };
    // IC( *std::search(vector.begin(), vector.end(), sequence.begin(), sequence.end()) );

    // Bidirectional Iterator 
    // std::reverse(vector.begin(), vector.end());
    // IC( vector );

    // Random Access Iterator 
    // std::sort(vector.begin(), vector.end());
    // IC( vector );

    // Contiguous Iterator




    // std::vector<int> vector = {0, 1, 2, 3, 4, 5};
    // same as std::vector<int>::iterator
    // auto it = vector.begin();
    // IC(*it);

    // it++;
    // IC(*it);
    // it--;
    // IC(*it);
    // std::advance(it, 2);
    // IC(*it);

    // IC( *std::next(it, 1) );
    // IC( *std::prev(it, 1) );











    // Reason 1: Convenience
    // std::vector<int> vector = {0, 1, 2, 3, 4, 5, 6, 7};
    // int sum = 0;
    // for(auto it = vector.begin(); it < vector.end(); ++it)
    // {
    //     sum += *it;
    // }
    // IC(sum);

    // Reason 2: Reusability
    // std::vector<int> container = {0, 1, 2, 3, 4, 5};
    // int sum = sum_elements(container.begin(), container.end());
    // IC(sum);

    // Reason 3: Dynamic Insertion/Erasure
    std::vector<int> vector = {0, 1, 2, 3, 4, 5};
    for(auto it = vector.begin(); it < vector.end(); ++it)
    {
        if(*it == 3)
        {
            it = vector.insert(it, 4);
            it++;
        }
    }
    IC(vector);

    return 0;
}