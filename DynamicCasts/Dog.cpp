#include "Dog.h"

Dog::Dog()
{
}

Dog::Dog(std::string_view name, std::string_view description, std::string_view fur_type)
    : Quadraped(name, description, fur_type)
{
}

Dog::~Dog()
{
}


void Dog::bark() const {
    std::cout << "Dog::bark called : Woof!" << std::endl;
}