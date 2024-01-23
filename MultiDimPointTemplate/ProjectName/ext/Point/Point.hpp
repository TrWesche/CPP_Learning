#pragma once

#include <iostream>

template<typename T = int, unsigned short dimensions = 3>
class Point
{

public:
    Point();
    ~Point();

    // Methods
    void set_value(unsigned short dimension, T value);

    T get_value(unsigned short dimension) const;
    unsigned short get_dimensions() const;
    void stream_insert(std::ostream& os) const;
    void print_info() const;

private:
    T m_values[dimensions];

};

template<typename T, unsigned short dimensions>
Point<T, dimensions>::Point()
{
    
}

template<typename T, unsigned short dimensions>
Point<T, dimensions>::~Point()
{
}

template<typename T, unsigned short dimensions>
void Point<T, dimensions>::set_value(unsigned short dimension, T value)
{
    if (dimension >= dimensions) {
        std::cout << "Failed to set value, dimension " << dimension << " is out of range." << std::endl;
        return;
    }

    m_values[dimension] = value;
}

template<typename T, unsigned short dimensions>
T Point<T, dimensions>::get_value(unsigned short dimension) const
{
    if (dimension >= dimensions) {
        std::cout << "Failed to get value, dimension " << dimension << " is out of range." << std::endl;
        return 0;
    }

    return m_values[dimension];
}

template<typename T, unsigned short dimensions>
unsigned short Point<T, dimensions>::get_dimensions() const
{
    return dimensions;
}

template<typename T, unsigned short dimensions>
void Point<T, dimensions>::stream_insert(std::ostream& os) const
{
    os << "point : [ ";
    
    for (unsigned short i{}; i < dimensions; i++) {
        os << m_values[i] << " ";
    }

    os << "]";
}

template<typename T, unsigned short dimensions>
void Point<T, dimensions>::print_info() const
{
    std::cout << *this;
}

template<typename T, unsigned short dimensions>
std::ostream& operator << (std::ostream& os, const Point<T, dimensions>& operand)
{
    operand.stream_insert(os);
    return os;
}