#pragma once
#ifndef _ENTITY_CONTAINER_
#define _ENTITY_CONTAINER_

#include <iostream>
#include <concepts>
#include "_EC_Itr.hpp"
// #include "Iterator.hpp"

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
    void push_back(const T& input) requires std::is_copy_assignable_v<T>;
    void emplace_back(T&& input); 
    // && will provide a new address for a value passed in
    // ... would tell the compiler it can be one or more values of the specified type
    void empty();
    T at(size_t index);

    void operator+=(const EntityContainer<T>& right);
    void operator=(const EntityContainer<T>& right);

    _EC_Itr<T> begin();
    _EC_Itr<T> end();

    // Iterator<T> begin();
    // Iterator<T> end();

private:
    void expand();


private:
    size_t m_reserved;
    size_t m_size;

    T* m_data; 

};


#include "EntityContainer.cpp"

#endif