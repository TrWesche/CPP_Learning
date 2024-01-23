#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <cmath>


template <typename T>
void print_collection_transform (const T& collection) {
  auto itr = collection.begin();

  std::cout << "{ ";
  
  while (itr != collection.end()) {
  std::cout << *itr << " ";
  itr++;
  }

  std::cout << "}" << std::endl;;
};
 

class STD_Transform
{
private:


public:
    STD_Transform(/* args */);
    ~STD_Transform();

    void execute();
};

STD_Transform::STD_Transform(/* args */)
{
}

STD_Transform::~STD_Transform()
{
}

void STD_Transform::execute() {
  std::vector<int> vec_int01 {21, 2, 33, 14, 95, 16};
  std::deque<int> deq_int02 {910, 20, 130, 540, 50};
  std::array<int, 5> arr_int03 {2, 6, 5, 8, 9};
  

  std::cout << "======= std::ranges::transform =======" << std::endl;  
  std::cout << " Provides the ability to transform data from a source collection and pipe it to a different destination collection" << std::endl;
  std::cout << " This also will not increase the capacity of the destination collection, you need to handle for the size of the collection changing if needed" << std::endl;
  std::cout << " Dividing values in vec_int01 by 2 and storing them in deq_int02" << std::endl;
  std::cout << "------- Before Transform" << std::endl;
  std::cout << "vec_int01: ";
  print_collection_transform(vec_int01);
  std::cout << "deq_int02: ";
  print_collection_transform(deq_int02);

  auto div_by_2 = [](int val) {
    return val/2;
  };

  std::ranges::transform(vec_int01.begin(), vec_int01.end(), deq_int02.begin(), div_by_2);

  std::cout << "------- After Transform" << std::endl;
  std::cout << "vec_int01: ";
  print_collection_transform(vec_int01);
  std::cout << "deq_int02: ";
  print_collection_transform(deq_int02);
 



  std::cout << std::endl;
  std::cout << "---------" << std::endl;
  std::cout << "Using the std::back_inserter to dynamically extend the destination container" << std::endl;

  std::cout << " Multiplying values in arr_int03 by 2 and appending them to vec_int01" << std::endl;
  std::cout << "------- Before Transform" << std::endl;
  std::cout << "vec_int01: ";
  print_collection_transform(vec_int01);
  std::cout << "arr_int03: ";
  print_collection_transform(arr_int03);

  auto mul_by_2 = [](int val) {
    return val * 2;
  };

  std::ranges::transform(arr_int03.begin(), arr_int03.end(), std::back_inserter(vec_int01), mul_by_2);

  std::cout << "------- After Transform" << std::endl;
  std::cout << "vec_int01: ";
  print_collection_transform(vec_int01);
  std::cout << "arr_int03: ";
  print_collection_transform(arr_int03);
}