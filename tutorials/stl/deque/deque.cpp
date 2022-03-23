#include <icecream.hpp>
#include <deque>


int main()
{
    std::deque<int> my_deque;

    my_deque.push_back(2);
    my_deque.push_front(1);

    my_deque.emplace_front(1);

    IC(my_deque);

    my_deque.pop_back();
    my_deque.pop_front();

    IC(my_deque);

    auto it = my_deque.begin();
    my_deque.insert(it, 3);

    IC(my_deque);

    auto it2 = my_deque.begin();
    my_deque.erase(it2);

    IC(my_deque);

    IC(my_deque.size());

    return 0;
}