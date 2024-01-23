#include "Triangle.h"

int Triangle::m_count{0};

Triangle::Triangle()
{
    m_count++;
}

Triangle::Triangle(double height, double width) :
    m_height(height), m_width(width)
{
    m_count++;
}

Triangle::~Triangle()
{
    m_count--;
}


void Triangle::draw() const
{
    std::cout << "Triangle:draw() Called. Drawing " << m_descr << 
    "Height: " << m_height << "Width: " << m_width  << std::endl;
}

int Triangle::get_count() const {
    return m_count;
}