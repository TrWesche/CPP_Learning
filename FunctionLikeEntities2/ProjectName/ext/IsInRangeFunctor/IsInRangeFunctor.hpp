#pragma once

#include <concepts>

template <typename T>
requires std::is_arithmetic_v<T>
class IsInRangeFunctor
{

public:
    IsInRangeFunctor(T min, T max) : m_min(min), m_max(max) {};

    bool operator() (T input) const 
    {
        return ((input >= m_min) && (input < m_max));
    }

private:
    T m_min;
    T m_max;
};

// IsInRangeFunctor::IsInRangeFunctor(/* args */)
// {
// }

// IsInRangeFunctor::~IsInRangeFunctor()
// {
// }
