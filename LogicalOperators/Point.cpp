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


// Operator Overloads
Point Point::operator + (const Point& b) const
{
    return Point(m_x + b.m_x , m_y + b.m_y);
}

void Point::operator ++ () {
    ++m_x;
    ++m_y;
}

Point Point::operator ++ (int) {
    Point temp(*this);
    ++(*this);
    return temp;
}

double& Point::operator [] (size_t index) {
    assert((index == 0) || (index == 1));
    return (index == 0) ? m_x : m_y;
}

Point Point::operator * (const Point& b) const
{
    return Point(m_x * b.m_x, m_y * b.m_y);
}

Point& Point::operator = (const Point& b) {
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &b) {
        m_x = b.m_x;
        m_y = b.m_y;
        ptr_example = new int(*b.ptr_example);
    }
    return *this;
}

// bool Point::operator > (const Point& b) const {
//     return (this->dist_to_origin() > b.dist_to_origin());
// }

// bool Point::operator < (const Point& b) const {
//     return (this->dist_to_origin() < b.dist_to_origin());
// }

// bool Point::operator >= (const Point& b) const {
//     return (this->dist_to_origin() >= b.dist_to_origin());
// }

// bool Point::operator <= (const Point& b) const {
//     return (this->dist_to_origin() <= b.dist_to_origin());
// }

bool Point::operator == (const Point& b) const {
    return (this->dist_to_origin() == b.dist_to_origin());
}

std::partial_ordering Point::operator <=> (const Point& b) const {
    if (dist_to_origin() > b.dist_to_origin()) {
        return std::partial_ordering::greater;
    } else if (dist_to_origin() == b.dist_to_origin()) {
        return std::partial_ordering::equivalent;
    } else if (dist_to_origin() < b.dist_to_origin()) {
        return std::partial_ordering::less;
    } else {
        return std::partial_ordering::unordered;
    }
}

// bool Point::operator != (const Point& b) const {
//     return (this->dist_to_origin() != b.dist_to_origin());
// }


// Type Conversions
Point::operator Vector3() const {
    std::cout << "Converting from Point to Vector3" << std::endl;
    return Vector3(m_x, m_y, 0);
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

void Point::print_info() {
    std::cout << "Point [x: " << m_x << ", y: " << m_y << "]" << std::endl;
}


double Point::dist_to_origin() const {
    return std::sqrt(std::pow(m_x, 2) + std::pow(m_x, 2));
}




// Non-Member Operator Overloads
Point operator - (const Point& a, const Point& b) {
    Point temp(a.m_x, a.m_y);
    return temp-=b;
}

std::ostream& operator<< (std::ostream& os, const Point& point) {
    os << "Point [ x: " << point.m_x << ", y: " << point.m_y << " ]" << " - Ptr_Value: " << *point.ptr_example << " @ " << point.ptr_example;  
    return os;
}

std::istream& operator>> (std::istream& is, Point& point) {
    double x;
    double y;

    std::cout << "Enter the coordiantes you would like to use to update the Point\n";
    std::cout << "Format [x, y] as two numbers separated by spaces" << std::endl;

    is >> x >> y;
    point.m_x = x;
    point.m_y = y;

    return is;
}

Point& operator+=( Point& a, const Point& b) {
    a.m_x += b.m_x;
    a.m_y += b.m_y;
    return a;
}

Point& operator-=( Point& a, const Point& b) {
    a.m_x -= b.m_x;
    a.m_y -= b.m_y;
    return a;
}

void operator--( Point& a ) {
    --a.m_x;
    --a.m_y;
}

Point operator--( Point& a, int) {
    Point temp(a);
    ++a;
    return a;
}


// Old way to create all of the comparison operators before C++ 20
// bool operator > (const Point& a, const Point& b) {
//     return (a.dist_to_origin() > b.dist_to_origin());
// }

// bool operator < (const Point& a, const Point& b) {
//     return (a.dist_to_origin() < b.dist_to_origin());
// }

// bool operator >= (const Point& a, const Point& b) {
//     return (a.dist_to_origin() >= b.dist_to_origin());
// }

// bool operator <= (const Point& a, const Point& b) {
//     return (a.dist_to_origin() <= b.dist_to_origin());
// }

// bool operator == (const Point& a, const Point& b) {
//     return (a.dist_to_origin() == b.dist_to_origin());
// }

// bool operator != (const Point& a, const Point& b) {
//     return (a.dist_to_origin() != b.dist_to_origin());
// }

// // Old way to do comparisons across types before C++ 20
// bool operator < (const Point& a, const double b) {
//     return (a.dist_to_origin() < b);
// }