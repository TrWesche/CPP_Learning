#pragma once

#include <iostream>
#include <string>

// Forward Definition
template<typename T>
class FriendFunction;

// Friend Function Declaration
template<typename T>
void example_friend( FriendFunction<T> );


template<typename T>
std::ostream& operator<<(std::ostream& os, FriendFunction<T>&);

// Class Definition
template<typename T>
class FriendFunction
{
friend void example_friend<T>( FriendFunction<T> input);
friend std::ostream& operator<<<T>(std::ostream& os, FriendFunction<T>& op);

public:
    FriendFunction(/* args */);
    ~FriendFunction();

    void setup(T input) 
    {
        m_var = input;
    }

    void internal_function_1(const T a, T b) 
    {
        std::cout << "Internal Function Called with a: " << a << " b: " << b << std::endl;
    }

private:
    T m_var;
};

template<typename T>
FriendFunction<T>::FriendFunction(/* args */)
{
}

template<typename T>
FriendFunction<T>::~FriendFunction()
{
}



template<typename T>
void example_friend( FriendFunction<T> input)
{
    std::cout << "Executing example friend on " << input.m_var << std::endl;
}

template<typename T>
std::ostream& operator <<(std::ostream& os, FriendFunction<T>& op)
{
    os << "Inserting Friend Function m_var into Stream: " << op.m_var;
    return os;
}