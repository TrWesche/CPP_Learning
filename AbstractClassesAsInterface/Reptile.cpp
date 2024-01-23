#include "Reptile.h"

Reptile::Reptile(/* args */)
{
}

Reptile::Reptile(
    std::string_view name, 
    std::string_view description, 
    std::string_view color,
    int body_temp
) :
    m_body_temp(body_temp), Animal(name, description, color)
{
}

Reptile::~Reptile()
{
}

void Reptile::sun_bathe() const
{
    std::cout << "Reptile::sun_bathe called by " << m_name << std::endl;
}

void Reptile::breathe() const 
{
    std::cout << "Reptile::breath called by " << m_name << std::endl;
}


void Reptile::stream_insert(std::ostream& os) const
{
    os  << "Reptile [name: " << m_name 
        << ", description: " << m_description 
        << ", color: " << m_color 
        << ", body temperature: " << m_body_temp
        << "]";
    return;
}
