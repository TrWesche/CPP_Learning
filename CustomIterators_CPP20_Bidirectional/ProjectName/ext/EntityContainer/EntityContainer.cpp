#include "EntityContainer.hpp"

// Constructors/Destructors
template <typename T>
requires std::is_default_constructible_v<T>
EntityContainer<T>::EntityContainer()
{
    m_data = new T[DEFAULT_RESERVATION];
	m_reserved = DEFAULT_RESERVATION;
	m_size = 0;
}

template <typename T>
requires std::is_default_constructible_v<T>
EntityContainer<T>::EntityContainer(size_t reservation) 
{
    m_data = new T[reservation];
	m_reserved = reservation;
	m_size = 0;
}

template <typename T>
requires std::is_default_constructible_v<T>
EntityContainer<T>::EntityContainer(const EntityContainer<T>& source) requires std::copyable<T>
{
    //Set up the new box
	m_data = new T[source.m_reserved];
	m_reserved = source.m_reserved;
	m_size = source.m_size;
	
	//Copy the items over from source 
	for(size_t i{} ; i < m_size; ++i){
		m_data[i] = source.m_data[i];
	}
}

template <typename T>
requires std::is_default_constructible_v<T>
EntityContainer<T>::~EntityContainer()
{
    delete(m_data);
}

template <typename T>
requires std::is_default_constructible_v<T>
size_t EntityContainer<T>::size() const
{
    return m_size;
}

template <typename T>
requires std::is_default_constructible_v<T>
size_t EntityContainer<T>::reserved() const
{
    return m_reserved;
}

template <typename T>
requires std::is_default_constructible_v<T>
T* EntityContainer<T>::data()
{
    return m_data;
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::swap(EntityContainer& right)
{
    size_t temp_size = m_size;
    size_t temp_reserved = m_reserved;

    m_size = right.m_size;
    m_reserved = right.m_reserved;

    right.m_size = temp_size;
    right.m_reserved = temp_reserved;

    std::swap(m_data, right.m_data);
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::change_reservation(size_t req)
{
    T* m_data_copy = new T[req];
    size_t offset;

    while (offset < std::min(req, m_size)) 
    {
        m_data_copy[offset] = m_data[offset];
        offset++;
    }

    m_size = offset;
    m_reserved = req;

    std::swap(m_data, m_data_copy);
    delete(m_data_copy);
}


template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::shrink_to_fit()
{
    T* m_data_copy = new T[m_size];
    size_t offset;

    while (offset < m_size) 
    {
        m_data_copy[offset] = m_data[offset];
        offset++;
    }

    m_reserved = m_size;

    std::swap(m_data, m_data_copy);
    delete(m_data_copy);
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::pop_back()
{
    if (m_size > 0) {
        --m_size;
    }
}

template <typename T>
requires std::is_default_constructible_v<T>
T EntityContainer<T>::peek() const
{
    if (m_size > 0) {
        return m_data[m_size - 1];
    }
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::push_back(const T& input) requires std::is_copy_assignable_v<T>
{
    if (m_size == m_reserved) {
        expand();
    }

    m_data[m_size] = input;
    m_size++;
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::emplace_back(T&& input)
{
    if (m_size == m_reserved) {
        expand();
    }

    std::move(input, m_data[m_size]);
    m_size++;
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::empty()
{
    m_size = 0;
}

template <typename T>
requires std::is_default_constructible_v<T>
T EntityContainer<T>::at(size_t index)
{
    if (m_size == 0 || index >= m_size) {
        return nullptr;
    }

    return m_data[index];
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::operator+=(const EntityContainer<T>& right)
{
    if (m_size + right.m_size > m_reserved) {
        change_reservation(m_size + right.m_size);
    }

    size_t offset = m_size;
    for (size_t i = 0; i < right.m_size; i++)
    {
        m_data[offset + i] = right.m_data[i];
    }
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::operator=(const EntityContainer<T>& right)
{
    delete(m_data);
    std::copy(m_data, right.m_data);
    m_size = right.m_size;
    m_reserved = right.m_reserved;
}


// template <typename T>
// requires std::is_default_constructible_v<T>
// Iterator<T> EntityContainer<T>::begin()
// {
//     return Iterator<T>(&m_data[0]);
// }

// template <typename T>
// requires std::is_default_constructible_v<T>
// Iterator<T> EntityContainer<T>::end()
// {
//     return Iterator<T>(&m_data[m_size]);
// }

template <typename T>
requires std::is_default_constructible_v<T>
_EC_Itr<T> EntityContainer<T>::begin()
{
    return _EC_Itr<T>(&m_data[0]);
}

template <typename T>
requires std::is_default_constructible_v<T>
_EC_Itr<T> EntityContainer<T>::end()
{
    return _EC_Itr<T>(&m_data[m_size]);
}

template <typename T>
requires std::is_default_constructible_v<T>
void EntityContainer<T>::expand()
{
    T* m_data_copy = new T[m_reserved + DEFAULT_INCREMENT];
    size_t idx {};

    while (idx < m_size) 
    {
        m_data_copy[idx] = m_data[idx];
        idx++;
    }

    m_reserved = m_reserved + DEFAULT_INCREMENT;

    std::swap(m_data, m_data_copy);
    delete(m_data_copy);
}


// Friend Functions
template <typename T>
std::ostream& operator<< (std::ostream& os, EntityContainer<T> in) 
{
    for (size_t i{0}; i < in.m_size; ++i)
    {
        os << in.m_data[i] << " ";
    }
    return os;
}
