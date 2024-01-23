#pragma once
#include "Adder.hpp"
#include <cstring>


template<>
class Adder <char*>
{
private:
    /* data */
public:
    Adder(/* args */);
    ~Adder();

    char* add_two(char* a, char* b);
};

Adder<char*>::Adder(/* args */)
{
}

Adder<char*>::~Adder()
{
}

inline // Mark as inline to avoid ODR (One Definition Rule) violations
char* Adder<char*>::add_two(char* a, char* b) {
    return strcat(a, b);
}