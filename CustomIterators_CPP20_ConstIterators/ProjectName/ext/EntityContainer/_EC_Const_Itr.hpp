#pragma once
#ifndef _EC_CONST_ITERATOR_
#define _EC_CONST_ITERATOR_

#include <iterator>

// Forward declarations for friend functions
template <typename T>
class _EC_Const_Itr;

template <typename T>
bool operator== (const _EC_Const_Itr<T>& left, const _EC_Const_Itr<T>& right);

template <typename T>
bool operator!= (const _EC_Const_Itr<T>& left, const _EC_Const_Itr<T>& right);

template <typename T>
std::ptrdiff_t operator- (const _EC_Const_Itr<T>& left, const _EC_Const_Itr<T>& right);

template <typename T>
_EC_Const_Itr<T> operator+ (std::ptrdiff_t offset, const _EC_Const_Itr<T>& right);

// Be careful when looking up documentation, a previous method with inheritance is deprecated
template <typename T>
class _EC_Const_Itr
{
    friend bool operator== <T> (const _EC_Const_Itr<T>& left, const _EC_Const_Itr<T>& right);
    friend bool operator!= <T> (const _EC_Const_Itr<T>& left, const _EC_Const_Itr<T>& right);

    friend std::ptrdiff_t operator- <T> (const _EC_Const_Itr<T>& left, const _EC_Const_Itr<T>& right);
    friend _EC_Const_Itr<T> operator+ <T> (std::ptrdiff_t offset, const _EC_Const_Itr<T>& right);
    public:
        using value_type = T; 
        using difference_type = std::ptrdiff_t;
        using pointer = const T*; 
        using reference = const T&; 
        using iterator_category = std::random_access_iterator_tag;
        
        _EC_Const_Itr() = default;
        _EC_Const_Itr(pointer input);

        _EC_Const_Itr<T>& operator++(); // Allows iterator usage like ++itr
        _EC_Const_Itr<T> operator++(int); // Allows iterator usage like itr++

        // Usage starts with Bidirectional Iterators
        _EC_Const_Itr<T>& operator--(); // Allows iterator usage like --itr   
        _EC_Const_Itr<T> operator--(int); // Allows iterator usage like itr--
        // Usage starts with Bidirectional Iterators


        // Used with Random Access Iterators
        _EC_Const_Itr<T>& operator+=(const difference_type offset);
        _EC_Const_Itr<T> operator+(const difference_type offset) const;
        _EC_Const_Itr<T>& operator-=(const difference_type offset);
        _EC_Const_Itr<T> operator-(const difference_type offset) const;
        reference operator[](const difference_type offset) const;
        bool operator<(const _EC_Const_Itr& right) const;
        bool operator>(const _EC_Const_Itr& right) const;
        bool operator<=(const _EC_Const_Itr& right) const;
        bool operator>=(const _EC_Const_Itr& right) const;
        // Used with Random Access Iterators

        reference operator*() const;
        pointer operator->();

    private:
        pointer m_ptr;
};

#include "_EC_Const_Itr.cpp"

#endif