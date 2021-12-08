#include <iostream>

int main()
{
    int my_integer = 5;
    // * means: Declaration of a pointer
    int* pointer_to_integer = nullptr;
    
    std::cout << "My integer " << my_integer << std::endl;
    std::cout << "My pointer_to_integer " << pointer_to_integer << std::endl;

    // & means: Operator that returns the adress of 
    pointer_to_integer = &my_integer;

    std::cout << "My pointer_to_integer " << pointer_to_integer << std::endl;
    // * means: Operator that is accessing what is stored at the pointer
    std::cout << "What is stored at pointer_to_integer " << *pointer_to_integer << std::endl;

    // & means: Declaration of a reference
    int& reference_to_integer = my_integer;

    std::cout << "My reference_to_integer " << reference_to_integer << std::endl;

    my_integer = 7;

    std::cout << "My pointer_to_integer " << pointer_to_integer << std::endl;
    std::cout << "What is stored at pointer_to_integer " << *pointer_to_integer << std::endl;
    std::cout << "My reference_to_integer " << reference_to_integer << std::endl;

    return 0;
}