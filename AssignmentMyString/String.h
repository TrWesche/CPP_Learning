#pragma once
#include <iostream>

namespace TW {

class String
{
friend std::ostream& operator << (std::ostream& os, const String& a);
friend std::istream& operator >> (std::istream& is, String& a);
friend String& operator += (String& a, const String& b);
friend String operator + (const String& a, const String& b);
// friend String& operator + (String& a, const String& b);
// friend String& operator - (String& a, const int qty);

public:
// Constructors/Destructors
    String() = delete;
    String(const char* in_ptr);
    String(const char* in_ptr, size_t in_size);
    String(const String& a); // Copy Constructor


    ~String();

// Getters/Setters

// Operator Overloads

// Methods
    // int find(const String& b, unsigned int search_from = 0, bool search_rtol = false) const;
    // String substr(unsigned int start_idx, unsigned int end_idx = std::numeric_limits<unsigned int>::max()) const;

private:
// Variables
    static const size_t m_max_size {255};
    size_t m_size;
    char* m_ptr{nullptr};

// Methods


};


}