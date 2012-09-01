#include "lambdafunction.h"
#include <iostream>

lambdafunction::lambdafunction(const lambdafunction::function_t &func)
    : _function(func)
{
}

void lambdafunction::apply()
{
    if (_function)
    {
        std::cout << "applying" << std::endl;

        _function();
    }
}
