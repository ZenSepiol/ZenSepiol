#include "my_code.hpp"
#include <gtest/gtest.h>

TEST(MyCode, check_the_truth)
{
    MyClass my_object;
    EXPECT_EQ(42, my_object.TheTruth());
}