#include "Point.h"

// Static Initializers
size_t Point::m_point_count {};
Point Point::m_origin_point {Point(0,0)};
size_t Point::get_point_count() {
    return m_point_count;
};
void Point::print_point_info(const Point& p) {
    std::cout << "Point: [x: " << p.m_x << ", y:" << p.m_y << "]" << std::endl;
};



// Constructors
Point::Point(double in_x, double in_y) : 
    m_x(in_x), m_y(in_y), p_m_origin_point(nullptr)
    {
        m_point_count++;
    };

Point::Point(double in_xy) : 
    Point(in_xy, in_xy)
    {};

Point::Point() : 
    Point(0.0, 0.0) 
    {};

Point::Point(const Point& point) : 
    Point(point.get_x(), point.get_y()) 
    {};

// Destructor
Point::~Point()
    {
        m_point_count--;
    };

// Methods
double Point::distance(const Point& dest) const {
    return sqrt( pow(m_x - dest.m_x, 2) + pow(m_y - dest.m_y, 2));
}

double Point::distance() const {
    return sqrt( pow(m_x, 2) + pow(m_y, 2));
}

void Point::print_info() const {
    std::cout << "Point Coordinates [x : " << m_x << ", y: " << m_y << "]" << std::endl;
}

void Point::print_addr() const {
    std::cout << "Point Coordinates Addresses [&x : " << &m_x << ", &y: " << &m_y << "]" << std::endl;
}