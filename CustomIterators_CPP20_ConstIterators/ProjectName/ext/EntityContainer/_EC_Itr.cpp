#include "_EC_Itr.hpp"


template <typename T>
_EC_Itr<T>::_EC_Itr(T* input) : m_ptr(input)
{
}

// template <typename T>
// _EC_Itr<T>::_EC_Itr(const _EC_Itr<T>& src) : m_ptr(src.m_ptr)
// {
// }

template <typename T>
_EC_Itr<T>& _EC_Itr<T>::operator++()
{
    m_ptr++;
    return *this;
}


template <typename T>
_EC_Itr<T> _EC_Itr<T>::operator++(int)
{
    _EC_Itr temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
_EC_Itr<T>& _EC_Itr<T>::operator--()
{
    m_ptr--;
    return *this;
}


template <typename T>
_EC_Itr<T> _EC_Itr<T>::operator--(int)
{
    _EC_Itr temp = *this;
    --(*this);
    return temp;
}

template <typename T>
_EC_Itr<T>& _EC_Itr<T>::operator+=(const std::ptrdiff_t offset)
{
    m_ptr += offset;
    return *this;
}

template <typename T>
_EC_Itr<T> _EC_Itr<T>::operator+(const std::ptrdiff_t offset) const
{
    _EC_Itr temp = *this;
    temp += offset;
    return temp;
}

template <typename T>
_EC_Itr<T>& _EC_Itr<T>::operator-=(const std::ptrdiff_t offset)
{
    m_ptr -= offset;
    return *this;
}

template <typename T>
_EC_Itr<T> _EC_Itr<T>::operator-(const std::ptrdiff_t offset) const
{
    _EC_Itr temp = *this;
    temp -= offset;
    return temp;
}

template <typename T>
T& _EC_Itr<T>::operator[](const std::ptrdiff_t offset) const
{
    // Bit confusing but this calls the operator + which returns a _EC_Itr<T> 
    // which you can dereference to the the pointer because of the * operator definition
    return *(*this + offset);
}

template <typename T>
bool _EC_Itr<T>::operator<(const _EC_Itr& right) const {
    return (m_ptr < right.m_ptr);
}

template <typename T>
bool _EC_Itr<T>::operator>(const _EC_Itr& right) const {
    return (m_ptr > right.m_ptr);
}

template <typename T>
bool _EC_Itr<T>::operator<=(const _EC_Itr& right) const {
    return !(m_ptr > right.m_ptr);
}

template <typename T>
bool _EC_Itr<T>::operator>=(const _EC_Itr& right) const {
    return !(m_ptr < right.m_ptr);
}

template <typename T>
T& _EC_Itr<T>::operator*() const {
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
    return !(left == right);
}

template <typename T>
std::ptrdiff_t operator- (const _EC_Itr<T>& left, const _EC_Itr<T>& right)
{
    return left.m_ptr - right.m_ptr;
}

template <typename T>
_EC_Itr<T> operator+ (std::ptrdiff_t offset, const _EC_Itr<T>& right)
{
    return right.m_ptr + offset;
}