#include <string>
#include <sstream>
#include <iostream>

// -----------------------
// Sample Templates 1 (Specilization and Overloads)
// -----------------------

// Dynamic generation of function Overloads created by the C++ Compiler at compile time
template <typename T> T maximum(T a, T b);
// Specialied templated of maximum for const char* type (can also feed a raw overload)
template <> 
const char* maximum<const char*>(const char* a, const char* b);
// Templates can also be overloaded, but be careful this can cause compiler errors
template <typename T> T* maximum(T* a, T* b);


// -----------------------
// Sample Templates 2 (Reference Case)
// -----------------------

template <typename T> const T& max_by_ref(const T& a, const T& b);


// -----------------------
// Sample Templates 3 (From Coding Exercise)
// -----------------------

template <typename T>
int hunt_down( T value,  T* collection, unsigned int size);

template <>
int hunt_down<const char*>(const char * value, const char ** collection, unsigned int size);


// -----------------------
// Sample Templates 4 (Multiple Template Parameters)
// -----------------------
template <typename ReturnType, typename T, typename P> ReturnType exp_ret_maximum(T a, T b);

// Option 2 - Cannot be split into declaration and definition
template <typename T, typename P> auto a_maximum(T a, T b);

// Option 3 - Decltype as Trailing Return Type, can be split into declaration and definition
template <typename T, typename P> auto dtype_maximum(T a, T b) -> decltype( (a > b) ? a : b );

// Option 4 - Decltype Auto (Cannot be split into declaration and definition)
template <typename T, typename P> decltype(auto) dtype_auto_maximum(T a, T b)
{
    return (a > b) ? a : b;
}


// -----------------------
// Sample Templates 5 (Another Exercise)
// -----------------------

template <typename A, typename B> std::string concatenate(const A& val1, const B& val2);


// -----------------------
// Sample Templates 6 (Default Arguments)
// -----------------------
template <typename ReturnType = double, typename T, typename P> ReturnType exp_ret_max_default(T a, T b);



// -----------------------
// Sample Templates 7 (None Type Template Parameters, act as placeholders for values)
// -----------------------
template <int threshold, typename T> bool is_valid(T collection[], size_t size);



// -----------------------
// Sample Templates 8 (Another Exercise)
// -----------------------
template <unsigned int size, typename T> int find_value(T collection[], T target);


