#pragma once
#include "Quadraped.h"

class Dog : public Quadraped
{

public:
    Dog();
    Dog(std::string_view name, std::string_view description, std::string_view fur_type);
    virtual ~Dog();

    virtual void bark() const;

private:
    
};

