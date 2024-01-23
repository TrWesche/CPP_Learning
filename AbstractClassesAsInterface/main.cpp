#include <iostream>

#include "Mammal.h"
#include "Reptile.h"

int main(int argc, char **argv){
    Animal* animal1 = new Reptile("Ricky", "Lizard", "Green", 30);
    Animal* animal2 = new Mammal("Bobby", "Leopard", "Black", 4);

    std::cout << *animal1 << std::endl;

    std::cout << *animal2 << std::endl;

    delete animal1;
    delete animal2;

    return 0;
}