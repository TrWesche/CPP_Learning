#pragma once

#include <iostream>
#include <string>

#include "Animal.h"


class Quadraped : public Animal
{

public:
    Quadraped();
    Quadraped(std::string_view name, std::string_view description, std::string_view fur_type);
    virtual ~Quadraped();

    virtual void run() const;
    void walk();

protected:
    std::string m_fur_type {"Unknown"};
};

