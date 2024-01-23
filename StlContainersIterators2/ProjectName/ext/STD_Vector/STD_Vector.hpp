#pragma once
#include<vector>
#include<string>
#include<iostream>


// Alternative with index based loop
template<typename T>
void print_vector(const std::vector<T> input) {
    for (size_t i{}; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}


template<typename T>
void print_vector_iterator(const T& collection) {
    auto it = collection.begin();

    std::cout << "[";
    while (it != collection.end()) {
        std::cout << " " << *it;
        it++;
    }
    std::cout << " ]" << std::endl;
}



class STD_Vector
{
private:
    /* data */

public:
    STD_Vector(/* args */);
    ~STD_Vector();

    void execute();

    void execute_iterator();
};

STD_Vector::STD_Vector(/* args */)
{
}

STD_Vector::~STD_Vector()
{
}


void STD_Vector::execute() {
    std::vector<std::string> vec_str {"The", "Sky", "Is", "Blue"};

    print_vector(vec_str);

    std::vector<int> vec_int1 {1, 2, 3, 4, 5};
    print_vector(vec_int1);

    // These return copies
    std::cout << vec_int1.front() << std::endl;
    std::cout << vec_int1.back() << std::endl; 
    std::cout << vec_int1.at(3) << std::endl;
    std::cout << vec_int1[2] << std::endl;
    // vec_int1.data() // Returns raw array
    vec_int1.push_back(6);
    print_vector(vec_int1);
    
    std::cout << "Removing from back" << std::endl;
    vec_int1.pop_back(); // This does not return the value
    print_vector(vec_int1);

    std::vector<int> vec_int2(10, 2); // This is an alternative way to initialize an array.  In this case it is an array of 10 elements all initialized to 2;
    print_vector(vec_int2);
}


void STD_Vector::execute_iterator() {
    std::vector<int> vec_int1 {10, 20, 30, 40, 50};

    print_vector_iterator(vec_int1);


    // std::vector<int>::iterator it = vec_int1.begin();
    // std::vector<int>::iterator it_end = vec_int1.end(); // Points to element in memory 1 past the end element

    // std::cout << std::boolalpha;
    // std::cout << "first element : " << *it << std::endl;
    // std::cout << "it = it_ent? : " << (it == it_end) << std::endl; 

    // it++;
    // std::cout << std::endl;
    // std::cout << "second element : " << *it << std::endl;
    // std::cout << "it = it_ent? : " << (it == it_end) << std::endl; 

    // it++;
    // std::cout << std::endl;
    // std::cout << "third element : " << *it << std::endl;
    // std::cout << "it = it_ent? : " << (it == it_end) << std::endl; 

    // it++;
    // std::cout << std::endl;
    // std::cout << "fourth element : " << *it << std::endl;
    // std::cout << "it = it_ent? : " << (it == it_end) << std::endl; 

    // it++;
    // std::cout << std::endl;
    // std::cout << "fifth element : " << *it << std::endl;
    // std::cout << "it = it_ent? : " << (it == it_end) << std::endl; 

    // it++;
    // std::cout << std::endl;
    // std::cout << "it = it_ent? : " << (it == it_end) << std::endl; 
}