#include <icecream.hpp>
#include <vector>

int main()
{
    std::vector<int> my_vector;

    my_vector.push_back(2);
    my_vector.push_back(3);

    IC(my_vector);

    auto it = my_vector.begin();
    my_vector.insert(it, 4);

    IC(my_vector);

    my_vector.pop_back();

    auto it2 = my_vector.begin();
    my_vector.erase(it2);

    IC(my_vector);

    IC(my_vector.size());
    IC(my_vector.capacity());

    my_vector.shrink_to_fit();
    my_vector.resize(10);

    my_vector.reserve(10);

    return 0;
}