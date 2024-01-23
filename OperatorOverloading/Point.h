#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include "Vector3.h"

class Point
{
    friend Point operator - (const Point& a, const Point& b);
    friend Point& operator+= (Point& a, const Point& b);
    friend Point& operator-= (Point& a, const Point& b);
    friend std::ostream& operator<< (std::ostream& os, const Point& point); // Stream Insertion
    friend std::istream& operator>> (std::istream& is, Point& point); // Stream Extraction
    friend void operator--( Point& a );
    friend Point operator--( Point& a, int);

public:
// Constructor/Destructor
    Point();
    Point(double in_x, double in_y);
    Point(double in_x, double in_y, int in_ptr_ex);
    ~Point();

// Member Operator Overload
    // Addition
    Point operator+ (const Point& b) const;
    // Subscript (Can only be a member function) - Binary Opeartor
    double& operator [](size_t index) {
        assert((index == 0) || (index == 1));
        return (index == 0) ? m_x : m_y;
    }
    // Multiplication
    Point operator* (const Point& b) const;

    // Unary Prefix Operator (i.e. the operator is prepended to the variable ++X)
    void operator++();

    // Unary Postfix Operator (i.e. the operator is added behind the variable X++)
        // Note: The dummy int tells the compiler it is a postfix
    Point operator++(int) {
        Point temp(*this);
        ++(*this);
        return temp;
    }

    // Copy Assignment Operator
        // Note: Must be a member
        // Note 2: The copy assignment will only be called on already existing objects, i.e. this will not be used at time of construction
        // The return by reference is useful because it will allow operator chaining
    Point& operator= (const Point& b) {
        std::cout << "Copy assignment operator called" << std::endl;
        if(this != &b) {
            m_x = b.m_x;
            m_y = b.m_y;
            ptr_example = new int(*b.ptr_example);
        }
        return *this;
    }

// Custom Type Conversion Overload -- Note: If in the Vector3 type a Constructor which takes a Point type is available the compiler will not know what to use and will throw errors
    explicit operator Vector3() const {
        std::cout << "Converting from Point to Vector3" << std::endl;
        return Vector3(m_x, m_y, 0);
    }


// Getter/Setters
    double get_x() const;
    double get_y() const;
    int get_ptr_example() const;

    void set_x(double in_x);
    void set_y(double in_y);
    void set_ptr_example(int in_ptr_example);

// Methods
    void print_info();

private:
// Member Variables
    double m_x;
    double m_y;
    int* ptr_example;

// Methods
    double dist_to_origin() const;
};



// Non-Member Operator Overload (Requires Friend Function Access)
inline Point operator - (const Point& a, const Point& b) {
    // return Point(a.m_x- b.m_x, a.m_y - b.m_y);
    Point temp(a.m_x, a.m_y);
    return temp-=b; // Note: This would not work if the compound Subtraction Operator was not also defined
}

// Stream Insertion
inline std::ostream& operator<< (std::ostream& os, const Point& point) {
    os << "Point [ x: " << point.m_x << ", y: " << point.m_y << " ]" << " - Ptr_Value: " << *point.ptr_example << " @ " << point.ptr_example;  
    return os;
}

// Stream Extraction
inline std::istream& operator>> (std::istream& is, Point& point) {
    double x;
    double y;

    std::cout << "Enter the coordiantes you would like to use to update the Point\n";
    std::cout << "Format [x, y] as two numbers separated by spaces" << std::endl;

    is >> x >> y;
    point.m_x = x;
    point.m_y = y;

    return is;
}

// Compound Addition Operator
inline Point& operator+=( Point& a, const Point& b) {
    a.m_x += b.m_x;
    a.m_y += b.m_y;
    return a;
}

inline Point& operator-=( Point& a, const Point& b) {
    a.m_x -= b.m_x;
    a.m_y -= b.m_y;
    return a;
}


// Unary Prefix Subtraction Operator
inline void operator--( Point& a ) {
    --a.m_x;
    --a.m_y;
}

// Unary Postfix Subtraction Operator
inline Point operator--( Point& a, int) {
    Point temp(a);
    ++a;
    return a;
}