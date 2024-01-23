#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

class Point;

class Vector3
{
    friend Vector3 operator - (const Vector3& a, const Vector3& b);
    friend Vector3 operator + (const Vector3& a, const Vector3& b);
    friend Vector3& operator += (Vector3& a, const Vector3& b);
    friend Vector3& operator -= (Vector3& a, const Vector3& b);
    friend std::ostream& operator << (std::ostream& os, const Vector3& Vector3); // Stream Insertion
    friend std::istream& operator >> (std::istream& is, Vector3& Vector3); // Stream Extraction

public:
// Constructor/Destructor
    Vector3();
    Vector3(double in_x, double in_y, double in_z);
    ~Vector3();

// Member Operator Overload
    double& operator [] (size_t index) {
        assert((index >= 0) && (index < 3));
        switch (index)
        {
        case 1:
            return m_x;
            break;
        case 2:
            return m_y;
            break;
        case 3:
            return m_z;
            break;
        }
    }

// Copy Assignment Operator for Point Types
    void operator = (const Point& b);
 

// Getter/Setters
    double get_x();
    double get_y();
    double get_z();

    void set_x(double in_x);
    void set_y(double in_y);
    void set_z(double in_z);

// Methods
    void print_info();

private:
// Member Variables
    double m_x;
    double m_y;
    double m_z;

// Methods
    // double dist_to_origin() const;
};
