#include "Circle.h"
#include <numbers>


Circle::Circle()
{
}

Circle::Circle(double radius, std::string_view description)
    : m_radius(radius), Shape(description)
{
}

Circle::~Circle()
{
}

double Circle::perimiter() const {
    return (2 * std::numbers::pi * m_radius);
}

double Circle::surface_area() const {
    return (std::numbers::pi * m_radius * m_radius);
}