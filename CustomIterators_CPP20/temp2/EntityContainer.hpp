#pragma once
#ifndef _ENTITY_CONTAINER_
#define _ENTITY_CONTAINER_

#include <iostream>
#include <concepts>

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
    EntityContainer()
    {
        m_data = new T[DEFAULT_RESERVATION];
        m_reserved = DEFAULT_RESERVATION;
        m_size = 0;
    }

    EntityContainer(size_t reservation)
    {
        m_data = new T[reservation];
        m_reserved = reservation;
        m_size = 0;
    }

    EntityContainer(const EntityContainer<T>& source) requires std::copyable<T>
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

    ~EntityContainer()
    {
        delete(m_data);
    }



    size_t size() const
    {
        return m_size;
    }

    size_t reserved() const
    {
        return m_reserved;
    }

    T* data()
    {
        return m_data;
    }

    void swap(EntityContainer<T>& right)
    {
        size_t temp_size = m_size;
        size_t temp_reserved = m_reserved;

        m_size = right.m_size;
        m_reserved = right.m_reserved;

        right.m_size = temp_size;
        right.m_reserved = temp_reserved;

        std::swap(m_data, right.m_data);
    }


    void change_reservation(size_t req)
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


    void shrink_to_fit()
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
    
    void pop_back()
    {
        if (m_size > 0) {
            --m_size;
        }
    }

    T peek() const
    {
        if (m_size > 0) {
            return m_data[m_size - 1];
        }
    }

    void push_back(const T& input) requires std::is_copy_constructible_v<T>
    {
        if (m_size == m_reserved) {
            expand();
        }

        m_data[m_size] = input;
        m_size++;
    }

    void emplace_back(T&& input)
    {
        if (m_size == m_reserved) {
            expand();
        }

        std::move(input, m_data[m_size]);
        m_size++;
    }


    void empty()
    {
        m_size = 0;
    }

    T at(size_t index)
    {
        if (m_size == 0 || index >= m_size) {
            return nullptr;
        }

        return m_data[index];
    }

    void operator+=(const EntityContainer<T>& right)
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

    void operator=(const EntityContainer<T>& right)
    {
        delete(m_data);
        std::copy(m_data, right.m_data);
        m_size = right.m_size;
        m_reserved = right.m_reserved;
    }


    class _EC_Itr
    {
        public:
            using value_type = T; // Doesn't seem like this is actually necessary based on the C++20 documentation.
            using difference_type = std::ptrdiff_t;
            using pointer = T*; // Doesn't seem like this is actually necessary based on the C++20 documentation.  It just needs a definition for the dereference operator.
            using reference = T&; // Doesn't seem like this is actually necessary based on the C++20 documentation.
            using iterator_category = std::input_iterator_tag;
            
            _EC_Itr() = default;
            _EC_Itr(pointer input) : m_ptr(input) {};
            // _EC_Itr(const _EC_Itr& src) : m_ptr(src.m_ptr); // Copy Contructor
            // ~_EC_Itr() = default;

            reference operator*() {
                return *m_ptr;
            }
                        
            pointer operator->() {
                return m_ptr;
            }

            _EC_Itr& operator++()
            {
                ++m_ptr;
                return *this;
            };

            _EC_Itr operator++(int)
            {
                _EC_Itr temp(*this);
                ++temp;
                return temp;
            }


            friend bool operator== (const _EC_Itr& left, const _EC_Itr& right)
            {
                return left.m_ptr == right.m_ptr;
            }

            friend bool operator!= (const _EC_Itr& left, const _EC_Itr& right)
            {
                return !(left == right);
            }


        private:
            pointer m_ptr;
    };

    _EC_Itr begin()
    {
        return _EC_Itr(&m_data[0]);
    }

    _EC_Itr end()
    {
        return _EC_Itr(&m_data[m_size]);
    }

private:
    void expand()
    {
        T* m_data_copy = new T[m_reserved + DEFAULT_INCREMENT];
        size_t offset;

        while (offset < m_size) 
        {
            m_data_copy[offset] = m_data[offset];
            offset++;
        }

        m_reserved = m_reserved + DEFAULT_INCREMENT;

        std::swap(m_data, m_data_copy);
        delete(m_data_copy);
    }

private:
    size_t m_reserved;
    size_t m_size;

    T* m_data; 
};

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



#endif