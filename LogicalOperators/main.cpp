#include <iostream>
#include "Point.h"

int main(int argc, char **argv){
    Point p1{10, 10};
    Point p2{20, 20};

    // std::cout << std::boolalpha;
    // std::cout << (p1 > p2) << "\n";
    // std::cout << (p1 < p2) << "\n";
    // std::cout << (p1 >= p2) << "\n";
    // std::cout << (p1 <= p2) << "\n";
    // std::cout << (p1 == p2) << "\n";
    // std::cout << (p1 != p2) << "\n";
    // std::cout << std::endl;


    // 3 Way Comparison Operator
    //      - Must compare to a literal 0
    int i1{100};
    int i2{200};

    std::cout << ((i1 <=> i2) > 0) << std::endl;


    return 0;
}