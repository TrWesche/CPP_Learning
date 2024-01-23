#pragma once
#include "Shape.h"


class Circle : public Shape
{
public:
    Circle();
    Circle(double radius, std::string_view description);
    virtual ~Circle();

    // Pure Virtual Functions
    virtual double perimiter() const;
    virtual double surface_area() const;

protected:
    double m_radius;

private:
    
};
