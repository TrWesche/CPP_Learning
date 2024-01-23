#include "Mammal.h"

Mammal::Mammal(/* args */)
{
}

Mammal::Mammal(
    std::string_view name, 
    std::string_view description, 
    std::string_view color,
    int qty_legs
) :
    m_qty_legs(qty_legs), Animal(name, description, color)
{
}

Mammal::~Mammal()
{
}

void Mammal::walk() const
{
    std::cout << "Mammal::walk called by " << m_name << std::endl;
}

void Mammal::breathe() const 
{
    std::cout << "Mammal::breath called by " << m_name << std::endl;
}


void Mammal::stream_insert(std::ostream& os) const
{
    os  << "Mammal [name: " << m_name 
        << ", description: " << m_description 
        << ", color: " << m_color 
        << ", qty legs: " << m_qty_legs
        << "]";
    return;
}
