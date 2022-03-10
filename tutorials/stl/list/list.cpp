#include <icecream.hpp>
#include <list>

int main()
{
    std::list<int> my_list_one = {1, 3, 2};

    auto it = my_list_one.begin();
    it++;

    it = my_list_one.erase(it);
    my_list_one.insert(it, 3);

    IC(my_list_one);

    return 0;
}