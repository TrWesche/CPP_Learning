#pragma once
#include <string>

class Shape
{
public:
    Shape();
    Shape(std::string_view description);
    virtual ~Shape();

    // Pure Virtual Functions
    virtual double perimiter() const = 0;
    virtual double surface_area() const = 0;

protected:
    std::string m_description;

private:
    
};
