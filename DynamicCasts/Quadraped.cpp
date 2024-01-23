#include "Quadraped.h"

Quadraped::Quadraped(/* args */)
{
}

Quadraped::Quadraped(std::string_view name, std::string_view description, std::string_view fur_type)
    : m_fur_type(fur_type), Animal(description, name)
{
}

Quadraped::~Quadraped()
{
}


void Quadraped::run() const {
    std::cout << "Quadraped " << m_name << " a " << m_description << " is running." << std::endl;
}

void Quadraped::walk() {
    std::cout << "Quadraped " << m_name << " a " << m_description << " is walking." << std::endl;
}