// **************
// Pessimizing move: This actually makes the code worse! 
T fn()
{
    T t;
    // Move prevents return value optimization
    return std::move(t);
}



// **************
// Redundant move: Less readable and bad style. 
struct T {
    T(const T&) = delete;
    T(T&&);
};

T fn(T t)
{
    // Move would be used implicitly
    return std::move(t); 
}