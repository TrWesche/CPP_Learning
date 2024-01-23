#include <iostream>

int sum_array (int values[], size_t size) 
{
    int output {};
    for (size_t i {}; i < size; i++) {
        output += values[i];
    }

    return output;
}