#include "EntityContainer.hpp"


template <typename T>
_EC_Itr<T>::_EC_Itr(T* input) : m_ptr(input)
{
}

template <typename T>
_EC_Itr<T>::_EC_Itr(const _EC_Itr<T>& src) : m_ptr(src.m_ptr)
{
}

template <typename T>
_EC_Itr<T>& _EC_Itr<T>::operator++()
{
    ++m_ptr;
    return *this;
}


template <typename T>
_EC_Itr<T> _EC_Itr<T>::operator++(int)
{
    _EC_Itr temp(*this);
    ++temp;
    return temp;
}

template <typename T>
T& _EC_Itr<T>::operator*() {
    return *m_ptr;
}

template <typename T>
T* _EC_Itr<T>::operator->() {
    return m_ptr;
}

// Friend Functions
template <typename T>
bool operator== (const _EC_Itr<T>& left, const _EC_Itr<T>& right)
{
    return left.m_ptr == right.m_ptr;
}

template <typename T>
bool operator!= (const _EC_Itr<T>& left, const _EC_Itr<T>& right)
{
    return left.m_ptr != right.m_ptr;
}