#include <concepts>
#include <string>


template <typename T>
concept SampleConcept1 = requires (T a) {
    std::to_string(a);
};


// Combine 2 Concepts with && (and)
template <typename T>
std::string SampleFunc1 (T a)
requires std::integral<T> && SampleConcept1<T>
{
    return std::to_string(a);
}



// Combine 2 Concepts with || (or)
template <typename T>
std::string SampleFunc2 (T a)
requires std::integral<T> || SampleConcept1<T>
{
    return std::to_string(a);
}