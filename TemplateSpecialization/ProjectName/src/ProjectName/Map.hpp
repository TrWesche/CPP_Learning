#pragma once

#include <type_traits>
#include <string>

template<typename K, typename V> 
class Map
{
public:
    static_assert(std::is_integral_v<K>, "Key value must be an integral type"); // Prior to C++ 20 type traits would be the way to do this.  C++ 20 forward <concepts> can be used.
    static_assert(std::is_same_v<V, std::string>, "Value must be of type std::string"); // Prior to C++ 20 type traits would be the way to do this.  C++ 20 forward <concepts> can be used.

    // Map();
    Map(K key, V value);
    ~Map();

    K m_key;
    V m_value;

};

template<typename K, typename V>
Map<K, V>::Map(K key, V value) 
    : m_key(key), m_value(value)
{
}

template<typename K, typename V>
Map<K, V>::~Map()
{
}
