#ifndef MAPTWO_H
#define MAPTWO_H

#include <iostream>
#include <cstring>

template <typename T>
class MapTwo;

template <typename T>
std::ostream& operator<< (std::ostream&, const MapTwo<T>&);


template <typename T>
class MapTwo
{
public:
	friend std::ostream& operator<< <T> (std::ostream&, const MapTwo<T>&);


	T m_key;
	T m_value;
	MapTwo(T key, T value)
	 : m_key(key), m_value(value)
	{}
	bool compare_to( const MapTwo& other) const{
		return (m_key == other.m_key)&&(m_value == other.m_value);
	}
   
	void print_info() const{
		std::cout << "map [";
		std:: cout << m_key << "," << m_value;
		std::cout << "]";
	}
    
};

template<>
class MapTwo <const char*>
{
public:
    const char* m_key;
	const char* m_value;
	MapTwo(const char* key, const char* value)
	 : m_key(key), m_value(value)
	{}
	bool compare_to(const MapTwo& other) const{
		return (strcmp(m_key, other.m_key) == 0)&&(strcmp(m_value, other.m_value) == 0);
	}
   
	void print_info() const{
		std::cout << "map [";
		std:: cout << m_key << "," << m_value;
		std::cout << "]";
	}
};


template <typename T>
std::ostream& operator<< (std::ostream& os, const MapTwo<T>& op) 
{
	os << "Map : ["; 
	os << op.m_key;
	os << ",";
	os << op.m_value;
	os << "]";

	return os;
}

#endif //MAPTWO_H