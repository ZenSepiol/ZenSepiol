#include <icecream.hpp>

float my_function(float parameter)
{
    IC();
    IC(parameter);
    if (parameter > 0.5F)
        return 0.F;
    else
        return 5.F;
}

int main()
{
    my_function(1.F);

    return 0;
}  