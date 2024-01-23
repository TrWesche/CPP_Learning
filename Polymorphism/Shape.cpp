#include "Shape.h"

int Shape::m_count{0};

Shape::Shape(/* args */)
{
    m_count++;
}

Shape::Shape(std::string_view descr) :
    m_descr(descr)
{
    m_count++;
}

Shape::Shape(std::string_view descr, int rgba) :
    m_descr(descr), m_rgba(rgba)
{
    m_count++;
}

Shape::~Shape()
{
    m_count--;
}

void Shape::draw() const {
    std::cout << "Shape:draw() Called. Drawing " << m_descr << std::endl;
}

void Shape::draw(int rgba) const {
    std::cout << "Shape:draw() Called. Drawing " << m_descr << 
    " with color " << std::hex << rgba << std::endl;
}

int Shape::get_count() const {
    return m_count;
}

void Shape::block_inherited_changes() const {
    std::cout << "Shape Not Blocked (No Final Annotation)" << std::endl;
}

void Shape::incresingly_restricted_method() const {
    std::cout << "Shape method in public scope" << std::endl;
}

void Shape::func_with_defaults(int input) {
    std::cout << input << std::endl;
}