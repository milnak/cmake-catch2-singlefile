#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <cstring>

#include <iostream>

unsigned int factorial(unsigned int number)
{
    return number <= 1 ? number : factorial(number - 1) * number;
}

int main(int argc, char **argv)
{
    int result = 0;

    // Note: "catch_discover_tests" passes --list-reporters and --list-test-names-only
    // To run tests, use fact.exe '*'
    if (argc > 1)
    {
        return Catch::Session().run(argc, argv);
    }

    std::cout << "factorial(5) = " << factorial(5) << std::endl;

    return result;
}
