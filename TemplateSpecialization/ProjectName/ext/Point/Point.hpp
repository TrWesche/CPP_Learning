#pragma once

#include <iostream>
// #include <type_traits>
#include <concepts>

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
class Point;

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
std::ostream& operator<<(std::ostream&, const Point<T, dimensions>&);


template<typename T = int, unsigned short dimensions = 3>
requires std::is_arithmetic_v<T>
class Point
{
    // Prior to C++ 20 type traits would be the way to do this.  C++ 20 forward <concepts> can be used.
    // static_assert(std::is_arithmetic_v<T>, "Coordinates of the Point Type must be arithmetic.");

friend std::ostream& operator<< <T, dimensions> (std::ostream&, const Point<T, dimensions>&);

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
requires std::is_arithmetic_v<T>
Point<T, dimensions>::Point()
{
    
}

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
Point<T, dimensions>::~Point()
{
}

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
void Point<T, dimensions>::set_value(unsigned short dimension, T value)
{
    if (dimension >= dimensions) {
        std::cout << "Failed to set value, dimension " << dimension << " is out of range." << std::endl;
        return;
    }

    m_values[dimension] = value;
}

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
T Point<T, dimensions>::get_value(unsigned short dimension) const
{
    if (dimension >= dimensions) {
        std::cout << "Failed to get value, dimension " << dimension << " is out of range." << std::endl;
        return 0;
    }

    return m_values[dimension];
}

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
unsigned short Point<T, dimensions>::get_dimensions() const
{
    return dimensions;
}

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
void Point<T, dimensions>::stream_insert(std::ostream& os) const
{
    os << "point : [ ";
    
    for (unsigned short i{}; i < dimensions; i++) {
        os << m_values[i] << " ";
    }

    os << "]";
}

template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
void Point<T, dimensions>::print_info() const
{
    std::cout << *this;
}

// template<typename T, unsigned short dimensions>
// std::ostream& operator << (std::ostream& os, const Point<T, dimensions>& operand)
// {
//     operand.stream_insert(os);
//     return os;
// }


template<typename T, unsigned short dimensions>
requires std::is_arithmetic_v<T>
std::ostream& operator<<(std::ostream& os, const Point<T, dimensions>& op) {
    size_t dim = sizeof(op.m_values)/sizeof(op.m_values[0]);
    
    os << "Point : [ dimension : ";
    os << dim;
    os << ", components : ";
    
    for (size_t i = 0; i < dim; i++)
    {
        os << op.m_values[i];
        os << " ";
    }
    
    os << "]";
    return os;
}