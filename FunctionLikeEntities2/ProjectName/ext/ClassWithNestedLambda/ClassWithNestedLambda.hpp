#pragma once
#include <iostream>

class ClassWithNestedLambda
{
public:
    ClassWithNestedLambda(int in1, int in2);
    ~ClassWithNestedLambda();
    
    void do_something() {
        std::cout << "Inside ClassWithNestedLambda do_something method" << std::endl;

        auto nested_lambda = [this] () {
            std::cout << "Inside Nested Lambda" << std::endl;
            std::cout << "Adding Member Variables (passing this pointer required or pass member variables by value): " << (m_int1 + m_int2) << std::endl;
        };

        // Capturing everything by value will also pick up the this pointer, use of the = is deprecated in C++ 20 so do not use this going forward
        // auto nested_lambda = [=] () {
        //     std::cout << "Inside Nested Lambda" << std::endl;
        //     std::cout << "Adding Member Variables (passing this pointer required or pass member variables by value): " << (m_int1 + m_int2) << std::endl;
        // };

        // Capturing everything by reference will also pick up the this pointer, this is not deprecated but will be confusing don't do this
        // auto nested_lambda = [&] () {
        //     std::cout << "Inside Nested Lambda" << std::endl;
        //     std::cout << "Adding Member Variables (passing this pointer required or pass member variables by value): " << (m_int1 + m_int2) << std::endl;
        // };

        nested_lambda();
    };

private:
    int m_int1 {100};
    int m_int2 {200};

    /* data */
};

ClassWithNestedLambda::ClassWithNestedLambda(int in1, int in2) :
    m_int1(in1), m_int2(in2)
{
}

ClassWithNestedLambda::~ClassWithNestedLambda()
{
}
