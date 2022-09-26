#define CATCH_CONFIG_MAIN

#include "limiter.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Limiter below limit", "[limiter]")
{
    auto my_limiter = Limiter(10);
    SECTION("positive number")
    {
        my_limiter.SetNumber(5);
        REQUIRE(my_limiter.GetNumber() == 5);
    }
    SECTION("negative number")
    {
        my_limiter.SetNumber(-10);
        REQUIRE(my_limiter.GetNumber() == -10);
    }
}

TEST_CASE("Limiter above limit", "[limiter]")
{
    auto my_limiter = Limiter(10);
    my_limiter.SetNumber(15);

    REQUIRE(my_limiter.GetNumber() == 10);
}
