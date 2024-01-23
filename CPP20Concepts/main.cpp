#include <iostream>
#include "assignment11.h"

template <typename T>
requires ConvertibleToStdString<T>
std::string convertToString(T a) {
    return std::to_string(a);
}

int main(int argc, char **argv){
    char a {8};
    int b {10};
    long c {20};
    long long d {300};
    float e {8.2f};
    double f {11.1};
    long double g {111.5};

    std::cout << convertToString(a) << std::endl;
    std::cout << convertToString(b) << std::endl;
    std::cout << convertToString(c) << std::endl;
    std::cout << convertToString(d) << std::endl;
    std::cout << convertToString(e) << std::endl;
    std::cout << convertToString(f) << std::endl;
    std::cout << convertToString(g) << std::endl;


    return 0;
}