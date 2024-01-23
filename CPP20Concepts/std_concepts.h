#include <concepts>

// Used to place type contraints on Template Type Parameters

// Standard Concepts
// Opt1: Integral using Concepts 
template <typename T> 
requires std::integral<T> 
T add(T a, T b) {
    return a + b;
}

// Opt2: Integral using Concept in variable definitions
template <std::integral T>
T sub(T a, T b) {
    return a - b;
}


// Opt3: For use with Auto
auto mul(std::integral auto a, std::integral auto b) {
    return a * b;
}

// Opt4: Putting the requirement after the function variable definition
template <typename T>
T div (T a, T b) requires std::integral<T> {
    return a / b;
}




// Opt5: Using Older Type Traits
template <typename T>
requires std::is_integral_v<T>  // This needs to be able to be evaulated at compile time and will return a boolean
T max(T a, T b) {
    return (a > b) ? a : b;
}


// Floating Point


// 


// Custom Concepts