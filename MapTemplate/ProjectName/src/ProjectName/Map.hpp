#pragma once

template<typename K, typename V> 
class Map
{
public:
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
