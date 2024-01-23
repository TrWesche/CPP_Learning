#pragma once
#ifndef _CUSTOMER_ITERATOR_
#define _CUSTOMER_ITERATOR_

template <typename T>
class Iterator{
    public : 
            using iterator_category = std::input_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = T;
            using pointer_type           = T*;
            using reference_type         = T&;

    Iterator() = default;
    Iterator(pointer_type ptr) : m_ptr(ptr) {}

    reference_type operator*() const {
        return *m_ptr;
    }

    pointer_type operator->() {
        return m_ptr;
    }

    Iterator& operator++() {
        m_ptr++; 
        return *this;
    }  
    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    //These operators are non members, but can still access private
    //members of Iterator. Cool.
    friend bool operator== (const Iterator& a, const Iterator& b) {
        return a.m_ptr == b.m_ptr;
    }
    friend bool operator!= (const Iterator& a, const Iterator& b) {
        //return a.m_ptr != b.m_ptr; 
        return !(a == b);
    } 

    private : 
        pointer_type m_ptr;
};

#endif