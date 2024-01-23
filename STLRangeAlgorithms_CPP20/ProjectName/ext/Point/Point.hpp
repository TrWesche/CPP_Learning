#pragma once

#include <compare>
#include <cmath>
#include <iostream>

class Point
{
    friend std::ostream& operator<< (std::ostream& os, const Point& in);
    
public:
    Point(double x, double y);
    ~Point();

    std::partial_ordering operator <=>(const Point& other) const;

    double get_x() const { return m_x; };
    double get_y() const { return m_y; };

private:
    double dist_to_origin() const;

    double m_x;
    double m_y;
};

Point::Point(double x, double y) 
: m_x(x), m_y(y)
{
}

Point::~Point()
{
}

double Point::dist_to_origin() const {
    return sqrt(pow(m_x - 0, 2) + pow(m_x - 0, 2));
}


std::partial_ordering Point::operator <=>(const Point& other) const
{
    if (dist_to_origin() > other.dist_to_origin()) {
        return std::partial_ordering::greater;
    } else if (dist_to_origin() == other.dist_to_origin()) {
        return std::partial_ordering::equivalent;
    } else if (dist_to_origin() < other.dist_to_origin()) {
        return std::partial_ordering::less;
    } else {
        return std::partial_ordering::unordered;
    }
}


std::ostream& operator<< (std::ostream& os, const Point& in)
{
    os << "{" << in.m_x << "," << in.m_y << "}";
    return os;
}