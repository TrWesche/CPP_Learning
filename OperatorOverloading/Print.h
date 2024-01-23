#pragma once

#include <string>
#include <iostream>

class Print
{
private:
    /* data */
public:
    Print(/* args */);
    ~Print();

    // Functors - An class which overloads the Function Call Operator -- ()
    void operator() (std::string value) {
        std::cout << "The value is " << value << std::endl;
    }

    std::string operator() (std::string a, std::string b) {
        return a + " " + b;
    }
};

Print::Print(/* args */)
{
}

Print::~Print()
{
}
