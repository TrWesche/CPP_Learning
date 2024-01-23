#pragma once
#ifndef _ENTITY_CONTAINER_
#define _ENTITY_CONTAINER_

#include <iostream>
#include <concepts>

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
        using iterator_category = std::input_iterator_tag;
        
        _EC_Itr() = default;
        _EC_Itr(pointer x);
        _EC_Itr(const _EC_Itr<T>& src); // Copy Contructor
        ~_EC_Itr() = default;

        _EC_Itr<T>& operator++(); // Allows iterator usage like ++itr
        _EC_Itr<T> operator++(int); // Allows iterator usage like itr++
        reference operator*();
        pointer operator->();

    private:
        pointer m_ptr;
};


// Forward declarations for friend functions
template <typename T>
requires std::is_default_constructible_v<T>
class EntityContainer;
 
template <typename T>
std::ostream& operator<< (std::ostream& os, EntityContainer<T> in);


template <typename T>
requires std::is_default_constructible_v<T>
class EntityContainer
{
static const size_t DEFAULT_RESERVATION {5};
static const size_t DEFAULT_INCREMENT {5};

friend std::ostream& operator<< <T> (std::ostream& os, EntityContainer<T> in);


public:
    EntityContainer();
    EntityContainer(size_t reservation);
    EntityContainer(const EntityContainer<T>& source) requires std::copyable<T>;
    ~EntityContainer();


    size_t size() const;
    size_t reserved() const;
    T* data();

    void swap(EntityContainer<T>& right);
    void change_reservation(size_t req);
    void shrink_to_fit();
    
    void pop_back();
    T peek() const;
    void push_back(const T& input) requires std::is_copy_constructible_v<T>;
    void emplace_back(T&& input); 
    // && will provide a new address for a value passed in
    // ... would tell the compiler it can be one or more values of the specified type
    void empty();
    T at(size_t index);

    void operator+=(const EntityContainer<T>& right);
    void operator=(const EntityContainer<T>& right);


    _EC_Itr<T> begin();
    _EC_Itr<T> end();

private:
    void expand();

private:
    size_t m_reserved;
    size_t m_size;

    T* m_data; 
};

// Include definitions
#include "_EC_Itr.cpp"
#include "EntityContainer.cpp"

#endif