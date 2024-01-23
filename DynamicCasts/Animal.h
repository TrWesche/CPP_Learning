#pragma once
#include <iostream>
#include <string>


class Animal
{
public:
// Constructor/Destructor
    Animal();
    Animal(std::string_view description, std::string_view name);
    virtual ~Animal();

// Operator Overloads

// Methods
    virtual void breathe() const;


protected:
    std::string m_description {"None"};
    std::string m_name {"None"};
};

