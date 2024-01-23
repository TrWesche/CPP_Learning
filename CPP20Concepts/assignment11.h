#include <concepts>
#include <string>

template <typename T>
concept ConvertibleToStdString = requires (T a) 
{
    std::to_string(a);
};