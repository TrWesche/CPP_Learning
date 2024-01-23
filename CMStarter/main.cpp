#include <iostream>

#include "FlexContainer.h"

int main(int, char**){
    std::cout << "Hello, from CMStarter! Test\n";

    TW::FlexContainer container = TW::FlexContainer();
    float output = container.add_tbr(1.0f, 2.0f);
    std::cout << output << std::endl;
}
