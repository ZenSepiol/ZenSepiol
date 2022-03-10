#include <icecream.hpp>
#include <forward_list>

int main()
{
    std::forward_list<int> list = {1, 2, 3};

    IC(list);

    list.push_front(4);
    list.emplace_front(5);

    auto it = list.begin();
    list.insert_after(it, 6);

    IC(list);

    list.pop_front();

    auto it2 = list.begin();
    list.erase_after(it2);

    IC(list);

    std::forward_list<int> list2 = {1, 2, 3, 1, 2, 2};
    list2.unique();

    IC(list2);

    list2.reverse();
    IC(list2);

    list2.remove(1);
    IC(list2);

    auto it3 = list2.begin();
    std::forward_list<int> list3 = {5, 5, 5};
    list2.splice_after(it3, list3);

    IC(list2);

    return 0;
}