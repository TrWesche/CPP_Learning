#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for(T val : vec) {
        os << val << " ";
    }
    os << "]";
    return os;
};