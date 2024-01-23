// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <functional> // This Library Includes Definitions for System Provided Functors
#include <vector>
#include <array>

#include "STD_Vector.hpp"
#include "STD_Array.hpp"

// These iterators allow data to be modified
template<typename T>
void print_collection_iterator(const T& collection, size_t begin_offset = 0, size_t end_offset = 0) {
    auto it_current = collection.begin() + begin_offset;
    auto it_stop = collection.end() - end_offset;

    std::cout << "[";
    while (it_current != it_stop) {
        std::cout << " " << *it_current;
        it_current++;
    }
    std::cout << " ]" << std::endl;
}

template<typename T>
void print_collection_iterator_rev(const T& collection, size_t begin_offset = 0, size_t end_offset = 0) {
    auto it_current = collection.rbegin() + begin_offset;
    auto it_stop = collection.rend() - end_offset;

    std::cout << "[";
    while (it_current != it_stop) {
        std::cout << " " << *it_current;
        it_current++;
    }
    std::cout << " ]" << std::endl;
}

// Constant Iterators
template<typename T>
void print_collection_iterator_const(const T& collection, size_t begin_offset = 0, size_t end_offset = 0) {
    auto it_current = collection.cbegin() + begin_offset;
    auto it_stop = collection.cend() - end_offset;

    std::cout << "[";
    while (it_current != it_stop) {
        std::cout << " " << *it_current;
        it_current++;
    }
    std::cout << " ]" << std::endl;
}

template<typename T>
void print_collection_iterator_rev_const(const T& collection, size_t begin_offset = 0, size_t end_offset = 0) {
    auto it_current = collection.crbegin() + begin_offset;
    auto it_stop = collection.crend() - end_offset;

    std::cout << "[";
    while (it_current != it_stop) {
        std::cout << " " << *it_current;
        it_current++;
    }
    std::cout << " ]" << std::endl;
}


int main(int argc, char* argv[])
{ 
  
  std::cout << "================ Running Vector Execute ==================" << std::endl;
  STD_Vector run_vector = STD_Vector();
  // run_vector.execute();
  run_vector.execute_iterator();


  std::cout << "================ Running Array Execute ==================" << std::endl;
  STD_Array run_array = STD_Array();
  // run_array.execute();
  run_array.execute_iterator();

  std::cout << "================ Iterators Work Across Collection Types ==================" << std::endl;
  std::vector<int> collection_1 {1, 2, 3, 4, 5, 6, 7};
  std::array<int, 10> collection_2 {10, 20, 30, 40, 50, 60, 70};
  
  print_collection_iterator(collection_1);
  print_collection_iterator(collection_2);


  print_collection_iterator(collection_1, 2, 1);
  print_collection_iterator(collection_2, 0, 5);

  print_collection_iterator_rev(collection_1, 2, 1);
  print_collection_iterator_rev(collection_2, 0, 5);
  

  // Note: Can also mark the container as const to protect it, i.e.
  // const std::vector<int> collection_const_1 {1, 2, 3, 4, 5, 6, 7};
  print_collection_iterator_const(collection_1, 0, 2);
  print_collection_iterator_const(collection_2, 3, 0);

  print_collection_iterator_rev_const(collection_1, 0, 2);
  print_collection_iterator_rev_const(collection_2, 3, 0);


  // If you want an iterator for a raw array you can use the standard library
  // std::begin and std::end to create an iterator type for it
  std::vector<int> collection_3 {5, 6, 7, 8, 9, 10, 11, 12, 13};
  int collection_4[] {20, 21, 22, 23, 24, 25, 26, 27, 28};

  for (auto it = std::begin(collection_3); it != std::end(collection_3); it++) {
    std::cout << *it << " ";
  };
  std::cout << std::endl;


  for (auto it = std::begin(collection_4); it != std::end(collection_4); it++) {
    std::cout << *it << " ";
  };
  std::cout << std::endl;
  

  return 0;
}
