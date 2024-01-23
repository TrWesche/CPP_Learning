#pragma once
#include<array>
#include<string>
#include<iostream>


// Alternative with index based loop
template<typename T, size_t size>
void print_array(const std::array<T, size> input) {
    for (size_t i{}; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print_array_iterator(const T& collection) {
    auto it = collection.begin();

    std::cout << "[";
    while (it != collection.end()) {
        std::cout << " " << *it;
        it++;
    }
    std::cout << " ]" << std::endl;
}


class STD_Array
{
private:
    /* data */

public:
    STD_Array(/* args */);
    ~STD_Array();

    void execute();
    void execute_iterator();
};

STD_Array::STD_Array(/* args */)
{
}

STD_Array::~STD_Array()
{
}


void STD_Array::execute() {
    std::array<std::string, 5> arr_str {"The", "Sky", "Is", "Blue"};

    print_array(arr_str);

    std::array<int, 10> arr_int1 {1, 2, 3, 4, 5};
    print_array(arr_int1);

    // These return copies
    std::cout << arr_int1.front() << std::endl;
    std::cout << arr_int1.back() << std::endl; 
    std::cout << arr_int1.at(3) << std::endl;
    std::cout << arr_int1[2] << std::endl;
    // vec_int1.data() // Returns raw array
    std::cout << "Filling Array with 10" << std::endl;
    arr_int1.fill(10);
    print_array(arr_int1);


    std::array<int,5> arr_int2{}; // Initialize array with 0
    print_array(arr_int2);
}



void STD_Array::execute_iterator() {
    std::array<int,6> vec_int1 {550, 650, 750, 850, 950};

    print_array_iterator(vec_int1);
}