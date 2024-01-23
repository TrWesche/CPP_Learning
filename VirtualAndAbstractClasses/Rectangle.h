#pragma once
#include "Shape.h"


class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(double x, double y, std::string_view description);
    virtual ~Rectangle();

    // Pure Virtual Functions
    virtual double perimiter() const;
    virtual double surface_area() const;

protected:
    double m_x;
    double m_y;

private:
    
};
