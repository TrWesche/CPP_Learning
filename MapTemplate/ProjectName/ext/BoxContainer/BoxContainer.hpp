#pragma once

#include <iostream>
#include <memory>

namespace TW {

template <typename T>
class BoxContainer
{
    static const size_t DEFAULT_CAPACITY = 10;
    static const size_t DEFAULT_INCREMENT = 5;

public:
    // Contructor/Destructor
    BoxContainer();
    BoxContainer(size_t reservation);
    BoxContainer(const BoxContainer& in);
    ~BoxContainer();

    // Operator Overloads
    void operator= (const BoxContainer& source);
    void operator+= (const BoxContainer& right);

    // Methods
    void stream_insert(std::ostream& os) const;
    void push(const T& item);
    T& pop();
    void remove_first_of(const T& item, bool rightToLeft = false);
    void remove_all_of(const T& item);
    void remove_duplicates_of(const T& item);
    void compress();

    size_t get_reserved() const;
    size_t get_allocated() const;

protected:
    size_t m_reserved {}; // Space reserved in the system
    size_t m_allocated {}; // Last m_allocated index
    bool m_empty {true}; // Array is Empty
    std::shared_ptr<T[]> m_elements;

private:
    void expand_storage(int size);
    void expand_storage();
    
    void remove_item_at(size_t index);
    void remove_item_right(const T& item);
    void remove_item_left(const T& item);
};



// ============================
// Internal Operators/Methods
// ============================
// ------ Constructor / Destructor Definitions
template <typename T>
BoxContainer<T>::BoxContainer(size_t reservation) : m_reserved(reservation)
{
    m_elements = std::make_shared<T[]>(m_reserved);
};

template <typename T>
BoxContainer<T>::BoxContainer() : BoxContainer(DEFAULT_CAPACITY)
    {};

template <typename T>
BoxContainer<T>::BoxContainer(const BoxContainer& in)
{
    m_reserved = in.m_reserved;
    m_allocated = in.m_allocated;
    m_empty = in.m_empty;

    m_elements = std::make_shared<T[]>(m_reserved);

    for (size_t i = 0; i < in.m_allocated; i++)
    {
        m_elements[i] = in.m_elements[i];
    }
};

template <typename T>
BoxContainer<T>::~BoxContainer()
{
    m_elements.reset();
};

// ------ Operator Overloads
template <typename T>
void BoxContainer<T>::operator= (const BoxContainer<T>& source) 
{
    if (this != &source) {
        m_elements.reset();

        m_reserved = source.m_reserved;
        m_allocated = source.m_allocated;
        m_empty = source.m_empty;

        m_elements = std::make_shared<T[]>(m_reserved);

        for (size_t i = 0; i < source.m_allocated; i++)
        {
            m_elements[i] = source.m_elements[i];
        }
    }

}

template <typename T>
void BoxContainer<T>::operator+= (const BoxContainer& right)
{
    size_t total_size_req = this.m_allocated + right.m_allocated;

    if (total_size_req > this.m_reserved) {
        size_t expansion_req = (this.m_allocated + right.m_allocated) - this.m_reserved;
        this.expand_storage(expansion_req);
    }


    for (size_t i{0}; i < right.m_allocated; i++) {
        this.m_elements[this.m_allocated] = right.m_elements[i];
        this.m_allocated++;
    }
};

// ------ Public Methods
template <typename T>
void BoxContainer<T>::stream_insert(std::ostream& os) const
{
    os << "[ ";
    
    for (size_t i{}; i < m_allocated; i++) {
        os << m_elements[i] << " ";
    }

    os << "]";
};

template <typename T>
void BoxContainer<T>::push(const T& item) 
{
    if (m_reserved == m_allocated) {
        this->expand_storage(DEFAULT_INCREMENT);
    }

    m_elements[m_allocated] = item;
    m_allocated++;
    m_empty = false;
};

template <typename T>
T& BoxContainer<T>::pop()  {
    BoxContainer<T>& instance = m_elements[m_allocated];
    m_allocated--;
    return instance;
};

template <typename T>
void BoxContainer<T>::remove_first_of(const T& item, bool rightToLeft) 
{
    if (rightToLeft) {
        remove_item_right(item);
    }
    else {
        remove_item_left(item);
    }
};

template <typename T>
void BoxContainer<T>::remove_all_of(const T& item)
{
    if (m_empty) {
        return;
    }

    size_t i{};
    
    while (i < m_allocated) {
        if (m_elements[i] == item) {
            remove_item_at(i);
        }
        i++;
    }
};

template <typename T>
void BoxContainer<T>::remove_duplicates_of(const T& item)
{
    if (m_allocated == -1) {
        return;
    }

    size_t i{0};
    bool found_first = false;

    while (i < m_allocated) {
        if (m_elements[i] == item && !found_first) {
            found_first = true;
        }
        else if (m_elements[i] == item && found_first) {
            remove_item_at(i);
        }
        i++;
    }
};

template <typename T>
void BoxContainer<T>::compress()
{
    m_reserved = m_allocated;
    std::shared_ptr<T[]> elements_new = std::make_shared<T[]>(m_reserved);

    for (size_t i{}; i < m_allocated; i++) {
        elements_new[i] = m_elements[i];
    }

    m_elements.swap(elements_new);
    elements_new.reset();
};

template <typename T>
size_t BoxContainer<T>::get_reserved() const {
    return m_reserved;
}

template <typename T>
size_t BoxContainer<T>::get_allocated() const {
    return m_allocated;
}

// ------ Private Methods
template <typename T>
void BoxContainer<T>::expand_storage(int size) {
    m_reserved += size;
    std::shared_ptr<T[]> elements_new = std::make_shared<T[]>(m_reserved);

    for (size_t i{}; i < m_allocated; i++) {
        elements_new[i] = m_elements[i];
    }

    m_elements.swap(elements_new);
    elements_new.reset();
};

template <typename T>
void BoxContainer<T>::expand_storage() 
{
    this->expand_storage(DEFAULT_INCREMENT);
};

template <typename T>
void BoxContainer<T>::remove_item_at(size_t index) 
{
    m_elements[index] = m_elements[m_allocated - 1];
    m_allocated--;

    if (m_allocated == 0) {
        m_empty = true;
    }
};

template <typename T>
void BoxContainer<T>::remove_item_right(const T& item)
{
    if (m_empty) {
        return;
    }

    size_t i{m_allocated};
    
    for (i; i > 0; i--) {
        if (m_elements[i] == item) {
            remove_item_at(i);
            break;
        }
    }
};

template <typename T>
void BoxContainer<T>::remove_item_left(const T& item)  
{
    if (m_empty) {
        return;
    }

    size_t i{};
    
    for (i; i < m_allocated; i++) {
        if (m_elements[i] == item) {
            remove_item_at(i);
            break;
        }
    }
}



// ============================
// External Operators/Methods
// ============================
template <typename T>
BoxContainer<T> operator+ (const BoxContainer<T>& left, const BoxContainer<T>& right)
{
    BoxContainer<T> output = BoxContainer<T>(left.m_allocated + right.m_allocated);
    output.m_allocated = left.m_allocated + right.m_allocated;
    output.m_empty = left.m_empty || right.m_empty;


    for (size_t i{0}; i < left.m_allocated; i++) {
        output.m_elements[i] = left.m_elements[i];
    }

    for (size_t i{0}; i < right.m_allocated; i++) {
        output.m_elements[i + left.m_allocated] = right.m_elements[i];
    }

    return output;
};

template <typename T>
std::ostream& operator << (std::ostream& os, const BoxContainer<T>& operand)
{
    operand.stream_insert(os);
    return os;
}

};
