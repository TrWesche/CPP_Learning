#pragma once
#ifndef _EC_ITERATOR_
#define _EC_ITERATOR_

// Forward declarations for friend functions
template <typename T>
class _EC_Itr;

template <typename T>
bool operator== (const _EC_Itr<T>& left, const _EC_Itr<T>& right);

template <typename T>
bool operator!= (const _EC_Itr<T>& left, const _EC_Itr<T>& right);


// Be careful when looking up documentation, a previous method with inheritance is deprecated
template <typename T>
class _EC_Itr
{
    friend bool operator== <T> (const _EC_Itr<T>& left, const _EC_Itr<T>& right);
    friend bool operator!= <T> (const _EC_Itr<T>& left, const _EC_Itr<T>& right);

    public:
        using value_type = T; // Doesn't seem like this is actually necessary based on the C++20 documentation.
        using difference_type = std::ptrdiff_t;
        using pointer = T*; // Doesn't seem like this is actually necessary based on the C++20 documentation.  It just needs a definition for the dereference operator.
        using reference = T&; // Doesn't seem like this is actually necessary based on the C++20 documentation.
        using iterator_category = std::bidirectional_iterator_tag;
        
        _EC_Itr() = default;
        _EC_Itr(pointer input);
        // _EC_Itr(const _EC_Itr<T>& src); // Copy Contructor
        // ~_EC_Itr() = default;

        _EC_Itr<T>& operator++(); // Allows iterator usage like ++itr
        _EC_Itr<T> operator++(int); // Allows iterator usage like itr++
        _EC_Itr<T>& operator--(); // Allows iterator usage like --itr
        _EC_Itr<T> operator--(int); // Allows iterator usage like itr--
        reference operator*() const;
        pointer operator->();

    private:
        pointer m_ptr;
};

#include "_EC_Itr.cpp"

#endif