#include "Rectangle.h"


Rectangle::Rectangle(/* args */)
{
}

Rectangle::Rectangle(double x, double y, std::string_view description)
    : m_x(x), m_y(y), Shape(description)
{
}

Rectangle::~Rectangle()
{
}

double Rectangle::perimiter() const {
    return ((2 * m_x) + (2 * m_y));
}

double Rectangle::surface_area() const {
    return (m_x * m_y);
}