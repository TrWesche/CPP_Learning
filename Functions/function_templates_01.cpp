#include "function_templates_01.h"

// -----------------------
// Sample Templates 1 (Specilization and Overloads)
// -----------------------
template <typename T> T maximum(T a, T b) 
{
    return (a > b) ? a : b;
}
// Specialized Template for pointer case
template <> 
const char* maximum<const char*>(const char* a, const char* b)
{
    return (std::strcmp(a, b) > 0 ? a : b);
}

// Overloaded version of template function for handling pointers
template <typename T> T* maximum(T* a, T* b)
{
    return (*a > *b) ? a : b;
}


// -----------------------
// Sample Templates 2 (Reference Case)
// -----------------------

template <typename T> const T& max_by_ref(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

// -----------------------
// Sample Templates 3 (From Coding Exercise)
// -----------------------

template <typename T>
int hunt_down( T value,  T* collection, unsigned int size)
{
	for (unsigned int i{ 0 }; i < size; i++) {
		if (collection[i] == value) {
			return i; // Found it; return the index.
		}
	}
	return -1; 
}

template <> 
int hunt_down<const char*>(const char * value, const char ** collection, unsigned int size)
{
    for (size_t i {}; i < size; i++) {
        if (std::strcmp(value, collection[i]) == 0) {
            return i;
        }
    }

    return -1;
}

// -----------------------
// Sample Templates 4 (Multiple Template Parameters)
// -----------------------

// Option 1
template <typename ReturnType, typename T, typename P> ReturnType exp_ret_maximum(T a, T b)
{
    return (a > b) ? a : b;
}
// Note: This can be called with 1, 2, or 3 parameter definitions.  I.e.:
// maximum<int, char, long> ()
// maximum<int, char> ()
// maximum<int> ()

// Option 2 - Will deduce the largest type from the types passed in (could be from explicit list or from paramters passed in)
template <typename T, typename P> auto a_maximum(T a, T b)
{
    return (a > b) ? a : b;
}


// Option 3 - Decltype as Trailing Return Type
template <typename T, typename P> auto dtype_maximum(T a, T b) -> decltype( (a > b) ? a : b ) {
    return (a > b) ? a : b;
}


// -----------------------
// Sample Templates 5 (Another Exercise)
// -----------------------
template <typename A, typename B> std::string concatenate(const A& val1, const B& val2)
{
    std::stringstream ss;
    ss << val1 << val2;
    return ss.str();
}

// -----------------------
// Sample Templates 6 (Default Arguments)
// -----------------------
template <typename ReturnType = double, typename T, typename P> ReturnType exp_ret_max_default(T a, T b)
{
    return (a > b) ? a : b;
}

// Note: Now this can be called with 0, 1, 2, or 3 parameter definitions.  I.e.:
// maximum<int, char, long> ()
// maximum<int, char> ()
// maximum<int> ()
// maximum() // This uses the default argument


// -----------------------
// Sample Templates 7 (None Type Template Parameters)
// -----------------------
template <int threshold, typename T> bool is_valid(T collection[], size_t size)
{
    T sum {};
    for (size_t i {}; i < size; i++)
    {
        sum += collection[i];
    }

    return (sum > threshold);
}

void how_to_use_7 () {
    double temperatures[] {10.0, 20.0, 30.0};
    bool valid = is_valid<50, double>(temperatures, std::size(temperatures));
}



// -----------------------
// Sample Templates 8 (Another Exercise)
// -----------------------
template <unsigned int size, typename T> int find_value(T collection[], T target)
{
    for (unsigned int i {}; i < size; i++) 
    {
        if (collection[i] == target)
        {
            return i;
        }
    }
    
    return -1;
}



// -----------------------
// 9 -Named Template Parameters for Lambdas
// -----------------------
void how_to_use_9 () 
{
    // All auto deduction, can be mixed types
    auto func = [] (auto a, auto b) 
    {
        return a + b;
    };

    func(10, 20.5); 


    // Force a specific type to be used
    auto func_expl = [] <typename T> (T a, T b) 
    {
        return a + b;
    };

    func_expl(10, 20); 

    
    // Multiple types also supported
    auto func_expl_2 = [] <typename T, typename P> (T a, P b) 
    {
        return a + b;
    };

    func_expl_2(10, 20.5); 
}



// -----------------------
// 10 - Type Traits: Used to query info about templated types at compile time
//          There are alot of these under "type_traits" in the cpp reference
// -----------------------
void how_to_use_10 () 
{
    int a {10};

    std::is_integral<int>::value;
    std::is_integral<double>::value;
    std::is_floating_point<int>::value;

    std::is_integral<decltype(a)>::value;
}

template <typename T>
void print_number (T a) 
{
    // Static Assert is checked at compile time, if an invalid type is passed in it will fail during compile
    static_assert(std::is_integral<T>::value, "Value must be integral type");
    std::cout << "a: " << a << std::endl;
}

template <typename T>
void print_number_other (T a) 
{
    // Static Assert is checked at compile time, if an invalid type is passed in it will fail during compile
    static_assert(std::is_integral_v<T>, "Value must be integral type");
    std::cout << "a: " << a << std::endl;

}


// -----------------------
// 11 - Constexpr If (Conditional Compilation)
//          Parts discarded by constexpr are not included in template instance
// -----------------------
void func_floating_point (double d) {
    std::cout << "floating point func" << std::endl;
}

void func_integral (int i) {
    std::cout << "integral func" << std::endl;
}

template <typename T>
void how_to_use_11(T t) 
{
    if (constexpr(std::is_integral_v<T>)) {
        func_integral(t);
    }
    else if (constexpr(std::is_floating_point_v<T>)) {
        func_floating_point(t);
    }
    else 
    {
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, 
                        "Argument must be integral or floating point");
    }
}