#include "Animal.h"

Animal::Animal(/* args */)
{
}

Animal::Animal(std::string_view description, std::string_view name) :
    m_description(description), m_name(name)
{
}

Animal::~Animal()
{
}


void Animal::breathe() const {
    std::cout << "Animal::breathe called for : " << m_name  << " the " << m_description << std::endl;
}