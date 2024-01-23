#include "Animal.h"


Animal::Animal(/* args */)
{
}

Animal::Animal(std::string_view name, std::string_view description, std::string_view color)
: m_name(name), m_description(description), m_color(color)
{
}

Animal::~Animal()
{
}

void Animal::breathe() const 
{
    std::cout << "Animal::breath called by " << m_name << std::endl;
}


void Animal::stream_insert(std::ostream& os) const
{
    os  << "Animal [name: " << m_name 
        << ", description: " << m_description 
        << ", color: " << m_color 
        << "]";
    return;
}
