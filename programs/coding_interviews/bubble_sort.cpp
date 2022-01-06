#include <list>
#include <icecream.hpp>

template<typename T>
void swap(T& a, T& b)
{
    T t(std::move(a));
    a = std::move(b);
    b = std::move(t);
}

template<typename T>
void BubbleSort(std::list<T>& list)
{
    for (uint32_t sorted = 0; sorted < list.size() - 1; ++sorted)
    {
        for (auto it = list.begin(); std::next(it, sorted + 1) != list.end(); ++it)
        {
            if (*it > *std::next(it,1))
            {
                swap(*it, *std::next(it,1));
            }
        }   
    }
}

int main(int, char**)
{
    // 5) Bubble Sort
    std::list<int> list{0, 5, 2, 8, 9};
    BubbleSort(list);
    IC(list);

    return 0;
}