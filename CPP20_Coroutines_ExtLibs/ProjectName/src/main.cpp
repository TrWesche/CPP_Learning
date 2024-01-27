#include <iostream>
#include <coroutine>
#include <algorithm>

#include "unique_generator.h"

unique_generator<size_t> generate_numbers(size_t count = 0) {
    while (true) {
        co_yield ++count;
    }
    co_return;
}


unique_generator<size_t> generate_numbers_3() {
    co_yield 10;
    co_yield 20;
    co_yield 30;
    co_return;
}



int main(){
    std::cout << "\n Calling External Library Unique Generator - Infinite Generator w/ break at greater than 20" << std::endl;
    unique_generator<size_t> func1 = generate_numbers();
    for (size_t val : func1) {
        std::cout << val << std::endl;

        if (val > 20) {
            break;
        }
    }


    std::cout << "\n Calling External Library Unique Generator - Loop Through Defined Yields (3)" << std::endl;
    unique_generator<size_t> func2 = generate_numbers_3();
    for (auto i = func2.begin(); i != func2.end(); ++i)
    {
        std::cout << *i << std::endl;
    }

    std::cout << "\n\nEND!" << std::endl;


   return 0;
}