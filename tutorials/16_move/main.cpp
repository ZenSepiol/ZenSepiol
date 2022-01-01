#include <icecream.hpp>
#include <vector>
#include <string>
#include <move.hpp>

uintptr_t GetDataAdress(const std::string& string)
{
    return reinterpret_cast<uintptr_t>(string.data());
}

int main()
{
    std::string my_string = "This string needs to be long enough to avoid small string optimizations."; 
    IC(GetDataAdress(my_string));

    std::string my_new_string = my_string; 
    IC(GetDataAdress(my_new_string));

    std::string my_moved_string = std::move(my_string); 
    IC(GetDataAdress(my_moved_string));

    return 0;
}

