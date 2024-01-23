#include "Point.h"



Point::Point() : m_x(0), m_y(0)
{
}

Point::Point(double in_x, double in_y) : m_x(in_x), m_y(in_y), ptr_example(new int(0)) 
{
}

Point::Point(double in_x, double in_y, int in_ptr_ex) : m_x(in_x), m_y(in_y), ptr_example(new int(in_ptr_ex))
{
}

Point::~Point()
{
}

void Point::print_info() {
    std::cout << "Point [x: " << m_x << ", y: " << m_y << "]" << std::endl;
}

Point Point::operator+(const Point& b) const
{
    return Point(m_x + b.m_x , m_y + b.m_y);
}

Point Point::operator*(const Point& b) const
{
    return Point(m_x * b.m_x, m_y * b.m_y);
}

// Unary Prefix
void Point::operator++() {
    ++m_x;
    ++m_y;
}

double Point::get_x() const
{
    return m_x;
}

double Point::get_y() const
{
    return m_y;
}

int Point::get_ptr_example() const
{
    return *ptr_example;
}

void Point::set_x(double in_x) {
    m_x = in_x;
}

void Point::set_y(double in_y) {
    m_y = in_y;
}

void Point::set_ptr_example(int in_ptr_example)
{
    *ptr_example = in_ptr_example;
}

double Point::dist_to_origin() const {
    return std::sqrt(std::pow(m_x, 2) + std::pow(m_x, 2));
}

