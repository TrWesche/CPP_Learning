#include <iostream>
#include "String.h"



int main(int argc, char **argv){

    TW::String s1{"TestString"};
    TW::String s2{"TestString", 4};

    std::cout << "------ Testing Start -------" << std::endl;

    std::cout << "------ String 1 Constructed From Only String Input -------" << std::endl;
    std::cout << s1 << std::endl;

    std::cout << "------ String 1 Constructed From String with Max Quantity -------" << std::endl;
    std::cout << s2 << std::endl;

    // Commented out so Prompt for Teminal Input doesn't happen
    // std::cout << "------ Overloaded Input Stream Operator -------" << std::endl;
    // std::cout << "Input New String 1 Value: " << std::endl;
    // std::cin >> s1; 
    // std::cout << "Print New String 1 Value: " << std::endl;
    // std::cout << s1 << std::endl;

    std::cout << "------ Overloaded += Operator -------" << std::endl;
    TW::String s3{"ConcatTest"};
    TW::String s4{"Attached"};
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    s3 += s4;
    std::cout << s3 << std::endl;

    std::cout << "------ Copy Constructor -------" << std::endl;
    TW::String s5{s3};
    std::cout << s5 << std::endl;

    std::cout << "------ Overloaded + Operator -------" << std::endl;
    TW::String s6{"And Adding This"};
    
    std::cout << (s5 + s6) << std::endl;

    return 0;
}