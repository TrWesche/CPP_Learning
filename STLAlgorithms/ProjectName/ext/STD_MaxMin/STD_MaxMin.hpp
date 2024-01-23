#pragma once

#include<iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <cmath>


template <typename T>
void print_collection_maxmin (const T& collection) {
  auto itr = collection.begin();

  std::cout << "{ ";
  
  while (itr != collection.end()) {
  std::cout << *itr << " ";
  itr++;
  }

  std::cout << "}" << std::endl;;
};
 

class STD_MaxMin
{
private:


public:
    STD_MaxMin(/* args */);
    ~STD_MaxMin();

    void execute();
};

STD_MaxMin::STD_MaxMin(/* args */)
{
}

STD_MaxMin::~STD_MaxMin()
{
}

void STD_MaxMin::execute() {
  std::vector<int> vec_int01 {1, 2, 3, 4, 5, 6};
  std::deque<int> deq_int02 {10, 20, 30, 40, 50};
  std::array<int, 5> arr_int03 {1, 3, 5, 7, 9};
  

  std::cout << "======= std::max_element =======" << std::endl;
  std::cout << " ----- Max Element Does not Need a Third Parameter by Default (uses less than operator by default)" << std::endl;
  std::cout << " Note: This does not return the value, it returns an iterator which can be dereferenced to the value." << std::endl;
  print_collection_maxmin(vec_int01);
  std::vector<int>::iterator loc_max01 = std::max_element(
    std::begin(vec_int01), 
    std::end(vec_int01)
  );
  std::cout << " Max Value: " << *loc_max01 << std::endl;
  
  
  std::cout << std::endl;
  std::cout << " ----- You can also pass in a custom comparator to change the default behavior if needed." << std::endl;
  int target_number {24};
  std::cout << " Note: This is going to be used to find the element in deq_int02 closest to " << target_number << std::endl;
  print_collection_maxmin(deq_int02);

  auto distance = [target_number](const int& x, const int& y) {
    return (std::abs(x - target_number) < std::abs(y - target_number));
  };

  std::deque<int>::iterator loc_max02 = std::min_element(
    std::begin(deq_int02),
    std::end(deq_int02),
    distance
  );
  std::cout << " Closest Value: " << *loc_max02 <<  " Target: " << target_number << std::endl;



  std::cout << "======= std::min_element =======" << std::endl;
  std::cout << " ----- Min Element Does not Need a Third Parameter by Default (uses less than operator by default)" << std::endl;
  std::cout << " Note: This does not return the value, it returns an iterator which can be dereferenced to the value." << std::endl;
  print_collection_maxmin(arr_int03);
  auto loc_min03 = std::min_element(
    std::begin(arr_int03), 
    std::end(arr_int03)
  );
  std::cout << " Max Value: " << *loc_min03 << std::endl;
  


  std::cout << "======= std::minmax_element =======" << std::endl;
  std::cout << " ----- There is also a minmax_element method which will allow you to capture both the min and max values at once in a pair/tuple." << std::endl;
  std::cout << " Note: This does not return values, it return a tuple of iterators which can be dereferenced to the values." << std::endl;
  print_collection_maxmin(arr_int03);
  auto[min_val, max_val] = std::minmax_element(
    std::begin(arr_int03), 
    std::end(arr_int03)
  );
  std::cout << " Min Value: " << *min_val << " Max Value: " << *max_val << std::endl;
  
}

