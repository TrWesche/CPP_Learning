#include <iostream>

consteval int get_value(){
    return 3;
}

int main(int argc, char **argv){
    constexpr int value = get_value();
    std::cout << "value : " << value << std::endl;
    return 0;
}