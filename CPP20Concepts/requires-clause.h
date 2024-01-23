#include <concepts>

// Types

// Simple Requirement
template <typename T>
concept SampleType1 = requires (T t) {
    sizeof(T) <= 4; // Only checks Syntax, the <= 4 is essentially ignored.
    // Important: The compiler only checks the syntax, i.e. if the value would be a valid input for the expression.  It doesn't actually run the expression.
    //              So in this case a value which is valid for the sizeof expression but is less thatn 4 in length will still satisfy the requirement.
};

// Nested Requirement
template <typename T>
concept SampleType2 = requires (T t) {
    sizeof(T);                  // Syntax Check
    requires sizeof(T) <= 4;    // Expression Check
};

// Compound Requirement
template <typename T>
concept SampleType3 = requires (T a, T b) {
    {a + b} noexcept -> std::convertible_to<int>;
    // Checks if a + b is valid syntax, that is doesn't throw exceptions, and the result is convertible to int
};


// Type Requirement -- To be convered later
