#pragma once

#include "Animal.h"

class Mammal : public Animal
{
public:
    Mammal(/* args */);
    Mammal(
        std::string_view name, 
        std::string_view description, 
        std::string_view color,
        int qty_legs
    );
    virtual ~Mammal();
    
    virtual void walk() const;

    virtual void breathe() const;

    virtual void stream_insert(std::ostream& os) const override;

protected:
    double m_qty_legs;
};

