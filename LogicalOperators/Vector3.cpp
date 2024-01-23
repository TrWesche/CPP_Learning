#include "Vector3.h"
#include "Point.h"


Vector3::Vector3() : m_x(0), m_y(0), m_z(0)
{
}

Vector3::Vector3(double in_x, double in_y, double in_z) : m_x(in_x), m_y(in_y), m_z(in_z)
{
}

Vector3::~Vector3()
{
}

void Vector3::print_info() {
    std::cout << "Vector3 [x: " << m_x << ", y: " << m_y << ", z: " << m_z <<  "]" << std::endl;
}


double Vector3::get_x()
{
    return m_x;
}

double Vector3::get_y()
{
    return m_y;
}

double Vector3::get_z()
{
    return m_z;
}

void Vector3::set_x(double in_x) {
    m_x = in_x;
}

void Vector3::set_y(double in_y) {
    m_y = in_y;
}

void Vector3::set_z(double in_z) {
    m_z = in_z;
}

// double Vector3::dist_to_origin() const {
//     return std::sqrt(std::pow(m_x, 2) + std::pow(m_x, 2));
// }

void Vector3::operator = (const Point& b) {
    m_x = b.get_x();
    m_y = b.get_y();
}




// Operator Overloads
Vector3& operator += (Vector3& a, const Vector3& b) {
    a.m_x += b.m_x;
    a.m_y += b.m_y;
    a.m_z += b.m_z;
    return a;
}

Vector3& operator -= (Vector3& a, const Vector3& b) {
    a.m_x -= b.m_x;
    a.m_y -= b.m_y;
    a.m_z -= b.m_z;
    return a;
}

Vector3 operator + (const Vector3& a, const Vector3& b) {
    Vector3 temp(a.m_x, a.m_y, a.m_z);
    return temp+=b;
}

Vector3 operator - (const Vector3& a, const Vector3& b) {
    Vector3 temp(a.m_x, a.m_y, a.m_z);
    return temp-=b;
}

// Stream Insertion
std::ostream& operator << (std::ostream& os, const Vector3& vector3) {
    os << "Vector3 [ x: " << vector3.m_x << ", y: " << vector3.m_y << ", z: " << vector3.m_z  << " ]"; 
    return os;
}

// Stream Extraction
std::istream& operator >> (std::istream& is, Vector3& Vector3) {
    double x;
    double y;
    double z;

    std::cout << "Enter the coordiantes you would like to use to update the Vector3\n";
    std::cout << "Format [x, y, z] as three numbers separated by spaces or returns" << std::endl;

    is >> x >> y >> z;
    Vector3.m_x = x;
    Vector3.m_y = y;
    Vector3.m_z = z;

    return is;
}
