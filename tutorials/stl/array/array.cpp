#include <icecream.hpp>
#include <array>
#include <tuple>

int main()
{
    std::array<int, 4> my_array = {2, 2, 4, 5};

    IC(my_array.at(3));
    IC(my_array[3]);
    IC(std::get<3>(my_array));

    IC(my_array.back());
    IC(my_array.front());

    IC(my_array.size());
    IC(my_array.max_size());

    std::array<int, 4> my_second_array = {1, 1, 1, 1};

    IC(my_array);
    IC(my_second_array);

    my_array.swap(my_second_array);

    IC(my_array);
    IC(my_second_array);

    std::array<int, 0> my_empty_array;
    IC(my_empty_array.empty());

    my_second_array.fill(2);
    IC(my_second_array);


    return 0;
}