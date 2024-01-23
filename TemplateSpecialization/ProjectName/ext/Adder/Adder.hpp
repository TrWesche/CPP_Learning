#pragma once

// Adder class implements template specialization which provides the adder class with different functionality when executing against different types. 
// For example when adding two char* strings together a standard + operation will not return the expected result.
// Note:: Specializations are full classes, so every method you want to use on a specialized class must have an implementation in order to be available.
template <typename T>
class Adder
{
public:
    Adder(/* args */);
    ~Adder();

    T add_two(T a, T b);

private:
    /* data */
};

template <typename T>
Adder<T>::Adder(/* args */)
{
}

template <typename T>
Adder<T>::~Adder()
{
}

template <typename T>
T Adder<T>::add_two(T a, T b) {
    return a + b;
}