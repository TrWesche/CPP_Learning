#include <iostream>
#include "lib/BoxContainer.h"


int main(int argc, char **argv){
    TW::BoxContainer box1 = TW::BoxContainer();

    box1.push(1);
    box1.push(2);

    std::cout << box1 << std::endl;

    return 0;
}