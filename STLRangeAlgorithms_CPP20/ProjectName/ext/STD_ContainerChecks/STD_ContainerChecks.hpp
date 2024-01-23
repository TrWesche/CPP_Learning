#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>


template <typename T>
void print_collection_cchks (const T& collection) {
    auto itr = collection.begin();

    std::cout << "{ ";
    
    while (itr != collection.end()) {
    std::cout << *itr << " ";
    itr++;
    }

    std::cout << "}" << std::endl;;
}

bool is_odd_cchks(int n) {
    return n % 2 != 0;
}


template <typename T>
class STD_ContainerChecks
{
private:


public:
    STD_ContainerChecks(/* args */);
    ~STD_ContainerChecks();

    void execute();
};

template <typename T>
STD_ContainerChecks<T>::STD_ContainerChecks(/* args */)
{
}

template <typename T>
STD_ContainerChecks<T>::~STD_ContainerChecks()
{
}

template <typename T>
void STD_ContainerChecks<T>::execute() {
  std::vector<int> vec_int01 {1, 2, 3, 4, 5, 6};
  std::deque<int> deq_int02 {2, 4, 6, 8, 10};
  std::array<int, 5> arr_int03 {1, 3, 5, 7, 9};
  

  std::cout << "======= std::ranges::all_of =======" << std::endl;
  std::cout << " all_of ands the returns for each value with one another and returns the boolean result." << std::endl;
  bool all_of_01 = std::ranges::all_of(
    vec_int01,
    [](int val){return val % 2 == 0;} // If value % 2 is equal to 0, return true.  I.e. this is an all even check
  );
  print_collection_cchks(vec_int01);
  std::cout << "Result of checking all values in vec_int01 to be even is: " << all_of_01 << std::endl;
  
  std::cout << "-------------" << std::endl;
  bool all_of_02 = std::ranges::all_of(
    deq_int02,
    [](int val){return val % 2 == 0;} // If value % 2 is equal to 0, return true.  I.e. this is an all even check
  );
  print_collection_cchks(deq_int02);
  std::cout << "Result of checking all values in deq_int02 to be even is: " << all_of_02 << std::endl;




  std::cout << std::endl;
  std::cout << "======= std::ranges::any_of =======" << std::endl;
  std::cout << " any_of ors the returns for each value with one another and returns the boolean result." << std::endl;
  bool any_of_03 = std::ranges::any_of(
    arr_int03,
    [](int val){return val % 2 == 0;} // If value % 2 is equal to 0, return true.  I.e. this is an all even check
  );
  print_collection_cchks(arr_int03);
  std::cout << "Result if any of the values in arr_int03 is even: " << any_of_03 << std::endl;

  std::cout << "-------------" << std::endl;
  bool any_of_01 = std::ranges::any_of(
    vec_int01,
    [](int val){return val % 2 == 0;} // If value % 2 is equal to 0, return false.  I.e. this is an all even check
  );
  print_collection_cchks(vec_int01);
  std::cout << "Result if any of the values in vec_int01 is even: " << any_of_01 << std::endl;




  std::cout << std::endl; 
  std::cout << "======= std::ranges::none_of =======" << std::endl;
  std::cout << " none_of and the returns for each value with one another and returns the boolean result. (True if all items in collection return false)" << std::endl;
  bool none_of_03 = std::ranges::none_of(
    arr_int03,
    [](int val){return val % 2 == 0;} // If value % 2 is equal to 0, return true.  I.e. this will return true for all even values
  );
  print_collection_cchks(arr_int03);
  std::cout << "Check if none of the values are even in arr_int03: " << none_of_03 << std::endl;


  std::cout << "-------------" << std::endl;
  bool none_of_01 = std::ranges::none_of(
    vec_int01,
    is_odd_cchks 
  );
  print_collection_cchks(vec_int01);
  std::cout << "Check if none of the values are odd in vec_int01: " << none_of_01 << std::endl;
}

