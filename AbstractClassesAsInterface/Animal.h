#pragma once

#include <string>
#include <iostream>
#include "StreamInsertable.h"

class Animal : public StreamInsertable
{
public:
// Constructor/Descrutors
    Animal(/* args */);
    Animal(std::string_view name, std::string_view description, std::string_view color);
    virtual ~Animal();

    virtual void breathe() const;

    virtual void stream_insert(std::ostream& os) const override;

protected:
    std::string m_name;
    std::string m_description;
    std::string m_color;
};
