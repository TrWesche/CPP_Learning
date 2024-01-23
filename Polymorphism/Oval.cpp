#include "Oval.h"

Oval::Oval()
{
}

Oval::Oval(std::string_view in_descr, double in_radius_x, double in_radius_y) :
    Shape(in_descr), m_radius_x(in_radius_x), m_radius_y(in_radius_y)
{
}

Oval::~Oval()
{
}

void Oval::draw() const
{
    std::cout << "Oval:draw() Called. Drawing " << m_descr << 
    "Radius X: " << m_radius_x << ", Radius Y: " << m_radius_y << std::endl;
}


void Oval::draw(std::string_view whatever) const
{
    std::cout << "Oval:draw() Called. Drawing " << m_descr << 
    "Radius X: " << m_radius_x << ", Radius Y: " << m_radius_y 
    << " Whatever Value: " << whatever << std::endl;
}

void Oval::block_inherited_changes() const {
    std::cout << "Oval No Further Redefinitions Allowed (Has Final Annotation)" << std::endl;
}

void Oval::incresingly_restricted_method() const {
    std::cout << "Oval override method in private scope" << std::endl;
}


void Oval::func_with_defaults(int input) {
    std::cout << input << std::endl;
}