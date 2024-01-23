#pragma once

#include <iostream>

class FunctionPointers
{
public:
    FunctionPointers(/* args */);
    ~FunctionPointers();

    double add_two(double, double);

    void use_func_ptr();


protected:


private:
    /* data */

};

FunctionPointers::FunctionPointers(/* args */)
{
}

FunctionPointers::~FunctionPointers()
{
}


double FunctionPointers::add_two(double a, double b) {
    return a + b;
}

void FunctionPointers::use_func_ptr() {
    // A function pointer can be defined in multiple ways:

    // return_type (variable_name) (input_type1, input_type2) = function_which_matches_definition
    double (FunctionPointers::*ex_func_ptr1) (double, double) {add_two};

    // std::cout << ex_func_ptr1(1.0, 2.0) << std::endl;


    // double use_fptr_exe = ex_func_ptr1(1.0, 2.0);
}