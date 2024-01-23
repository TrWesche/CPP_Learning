#include "Circle.h"

Circle::Circle()
{
}

Circle::Circle(std::string_view in_descr, double in_radius) :
    Oval(in_descr, in_radius, in_radius)
{
}

Circle::~Circle()
{
}

void Circle::draw() const
{
    std::cout << "Circle:draw() Called. Drawing " << m_descr << 
    "Radius: " << m_radius_x  << std::endl;
}

void Circle::draw(int rgba, std::string_view color) const
{
    std::cout << "Circle:draw() Called. Drawing " << m_descr << 
    "Radius: " << m_radius_x << " in " << color << 
    " with color code " << std::hex << rgba <<
    std::endl;
}

void Circle::draw(std::string_view whatever) const
{
    std::cout << "Circle:draw() Called. Drawing " << m_descr << 
    "Radius: " << m_radius_x << " Whatever Value: " << whatever << std::endl;
}