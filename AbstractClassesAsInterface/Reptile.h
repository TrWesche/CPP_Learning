#pragma once

#include "Animal.h"

class Reptile : public Animal
{
public:
    Reptile(/* args */);
    Reptile(
        std::string_view name, 
        std::string_view description, 
        std::string_view color,
        int body_temp
    );
    virtual ~Reptile();
    
    virtual void sun_bathe() const;

    virtual void breathe() const;

    virtual void stream_insert(std::ostream& os) const override;

protected:
    double m_body_temp;
};

