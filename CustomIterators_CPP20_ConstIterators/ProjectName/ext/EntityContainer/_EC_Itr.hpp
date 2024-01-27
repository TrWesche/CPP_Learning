#pragma once
#ifndef _EC_ITERATOR_
#define _EC_ITERATOR_

#include <iterator>

// Forward declarations for friend functions
template <typename T>
class _EC_Itr;

template <typename T>
bool operator== (const _EC_Itr<T>& left, const _EC_Itr<T>& right);

template <typename T>
bool operator!= (const _EC_Itr<T>& left, const _EC_Itr<T>& right);

template <typename T>
std::ptrdiff_t operator- (const _EC_Itr<T>& left, const _EC_Itr<T>& right);

template <typename T>
_EC_Itr<T> operator+ (std::ptrdiff_t offset, const _EC_Itr<T>& right);

// Be careful when looking up documentation, a previous method with inheritance is deprecated
template <typename T>
class _EC_Itr
{
    friend bool operator== <T> (const _EC_Itr<T>& left, const _EC_Itr<T>& right);
    friend bool operator!= <T> (const _EC_Itr<T>& left, const _EC_Itr<T>& right);

    friend std::ptrdiff_t operator- <T> (const _EC_Itr<T>& left, const _EC_Itr<T>& right);
    friend _EC_Itr<T> operator+ <T> (std::ptrdiff_t offset, const _EC_Itr<T>& right);

    // friend std::ptrdiff_t operator- <T> (const _EC_Itr<T>& right) const;
    // friend _EC_Itr<T>& operator+ <T> (const _EC_Itr<T> itr, std::ptrdiff_t offset); 

    public:
        using value_type = T; // Doesn't seem like this is actually necessary based on the C++20 documentation.
        using difference_type = std::ptrdiff_t;
        using pointer = T*; // Doesn't seem like this is actually necessary based on the C++20 documentation.  It just needs a definition for the dereference operator.
        using reference = T&; // Doesn't seem like this is actually necessary based on the C++20 documentation.
        using iterator_category = std::random_access_iterator_tag;
        
        _EC_Itr() = default;
        _EC_Itr(pointer input);
        // _EC_Itr(const _EC_Itr<T>& src); // Copy Contructor
        // ~_EC_Itr() = default;

        _EC_Itr<T>& operator++(); // Allows iterator usage like ++itr
        _EC_Itr<T> operator++(int); // Allows iterator usage like itr++

        // Usage starts with Bidirectional Iterators
        _EC_Itr<T>& operator--(); // Allows iterator usage like --itr   
        _EC_Itr<T> operator--(int); // Allows iterator usage like itr--
        // Usage starts with Bidirectional Iterators


        // Used with Random Access Iterators
        _EC_Itr<T>& operator+=(const difference_type offset);
        _EC_Itr<T> operator+(const difference_type offset) const;
        _EC_Itr<T>& operator-=(const difference_type offset);
        _EC_Itr<T> operator-(const difference_type offset) const;
        reference operator[](const difference_type offset) const;
        bool operator<(const _EC_Itr& right) const;
        bool operator>(const _EC_Itr& right) const;
        bool operator<=(const _EC_Itr& right) const;
        bool operator>=(const _EC_Itr& right) const;
        // Used with Random Access Iterators

        reference operator*() const;
        pointer operator->();

    private:
        pointer m_ptr;
};

#include "_EC_Itr.cpp"

#endif