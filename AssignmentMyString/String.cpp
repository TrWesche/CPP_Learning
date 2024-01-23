#include "String.h"

namespace TW {

String::String(const char* in_ptr)
{
    m_size = 0;
    
    // Search for End of String
    while (*(in_ptr + m_size) != 0) {
        m_size++;
    }
    m_size++; // Increment to Caputure End of String

    // Create New Char Array Pointer & Copy in Data
    m_ptr = new char[m_size]; 
    for (size_t i = 0; i < m_size; i++)
    {
        *(m_ptr + i) = *(in_ptr + i);
    }
}

String::String(const char* in_ptr, size_t in_size)
{
    // Reserve Space for Input Value Plus Space for Null Character
    m_size = in_size + 1;
    m_ptr = new char[m_size];

    // Copy in Data and Set Last Value to Null Character
    for (size_t i = 0; i < in_size; i++) {
        *(m_ptr + i) = *(in_ptr + i);
    }
    *(m_ptr + in_size) = 0;
}

String::String(const String& a) {
    this->m_size = a.m_size;
    this->m_ptr = new char[this->m_size];

    for (size_t i = 0; i < a.m_size; i++)
    {
        *(this->m_ptr + i) = *(a.m_ptr + i);
    }
}

String::~String()
{
    delete m_ptr;
}



std::ostream& operator << (std::ostream& os, const String& a) {
    os << a.m_ptr;
    return os;
}


std::istream& operator >> (std::istream& is, String& a) {
    int temp_size{};
    char* temp_char = new char[a.m_max_size];

    // Copy Input Contents into Temporary Character Array (Limited by Max Size)
    is.getline(temp_char, a.m_max_size);

    // Release Memory Allocated to String on Heap
    delete a.m_ptr;
    a.m_size = 0;
    
    // Find New Length & Add 1 for Null Character
    while (*(temp_char + temp_size) != 0) {
        temp_size++;
    }
    temp_size++;

    // Allocate New Memory on Heap
    a.m_ptr = new char[temp_size];

    // Copy Values Over & Add Null Character
    for (size_t i = 0; i < temp_size - 1; i++)
    {
        *(a.m_ptr + i) = *(temp_char + i);
    }
    *(a.m_ptr + temp_size -1) = 0;

    // Release Memory of Allocated to Temporary Char Array
    delete temp_char;

    return is;
}


String& operator += (String& a, const String& b) {
    unsigned int new_size = a.m_size + b.m_size - 1;
    char* new_data = new char[new_size];

    for (size_t i = 0; i < a.m_size - 1; i++)
    {
        *(new_data + i) = *(a.m_ptr + i);
    }
    
    for (size_t i = 0; i < b.m_size; i++) 
    {
        *(new_data + i + a.m_size - 1) = *(b.m_ptr + i);
    }

    delete a.m_ptr;
    a.m_ptr = new_data;
    a.m_size = new_size;

    return a;
}

String operator + (const String& a, const String& b) {
    String temp{a};
    temp += b;
    return temp;
}

}