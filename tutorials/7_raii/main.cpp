#include <iostream>

#include "leaky_class.h"
#include "at_least_no_leaks.h"
#include "correct_class.h"

int main()
{
    LeakyClass leaky_class;
    leaky_class.OutputText("LeakyClass: Test");
    // leaky_class.OutputText("LeakyClass: This is a longer Test");
    leaky_class.OutputText("LeakyClass: Test2");

    NotLeakyClass not_leaky_class;
    not_leaky_class.OutputText("NotLeakyClass: Test");
    // not_leaky_class.OutputText("NotLeakyClass: This is a longer Test");
    not_leaky_class.OutputText("NotLeakyClass: Test2");

    CorrectClass correct_class;
    correct_class.OutputText("CorrectClass: Test");
    correct_class.OutputText("CorrectClass: This is a longer Test");
    correct_class.OutputText("CorrectClass: Test2");

    return 0;
};