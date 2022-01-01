template<typename T>
void swap_old(T& a, T& b)
{
    // Copy construction
    T t = a;
    // Copy
    a = b;
    // Copy
    b = t;
}


template<typename T>
void swap_new(T& a, T& b)
{
    // Move construction
    T t(std::move(a));
    // Move
    a = std::move(b);
    // Move
    b = std::move(t);
}

