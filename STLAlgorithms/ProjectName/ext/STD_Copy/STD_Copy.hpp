#pragma once

#include<iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <cmath>


template <typename T>
void print_collection_copy (const T& collection) {
  auto itr = collection.begin();

  std::cout << "{ ";
  
  while (itr != collection.end()) {
  std::cout << *itr << " ";
  itr++;
  }

  std::cout << "}" << std::endl;;
};
 

class STD_Copy
{
private:


public:
    STD_Copy(/* args */);
    ~STD_Copy();

    void execute();
};

STD_Copy::STD_Copy(/* args */)
{
}

STD_Copy::~STD_Copy()
{
}

void STD_Copy::execute() {
  std::vector<int> vec_int01 {1, 2, 3, 4, 5, 6};
  std::deque<int> deq_int02 {10, 20, 30, 40, 50};
  std::array<int, 5> arr_int03 {2, 6, 5, 8, 9};
  

  std::cout << "======= std::copy =======" << std::endl;  
  std::cout << " Provides the ability to copy data between collections (does not need to be of the same type!)" << std::endl;
  std::cout << " Important: std::copy is not smart enough to expand the storage of the target collection, if you want to append the data you will need to handle it" << std::endl;
  std::cout << " Copying data from fixed length array (arr_int03) into a variable length vector (vec_int01)" << std::endl;

  std::cout << "------- Before Copy" << std::endl;
  std::cout << "arr_int03 Contents" << std::endl;
  print_collection_copy(arr_int03);
  std::cout << "vec_int01 Contents" << std::endl;
  print_collection_copy(vec_int01);

  vec_int01.resize(vec_int01.size() + arr_int03.size());
  std::copy(std::begin(arr_int03), std::end(arr_int03), std::end(vec_int01) - arr_int03.size());

  std::cout << "------- After Copy" << std::endl;
  std::cout << "arr_int03 Contents" << std::endl;
  print_collection_copy(arr_int03);
  std::cout << "vec_int01 Contents" << std::endl;
  print_collection_copy(vec_int01);
  
  
  std::cout << std::endl;
  std::cout << "======= std::copy_if =======" << std::endl;  
  std::cout << " There is also a copy_if function which can be used to filter what gets copied from one place to another." << std::endl;
  
  std::cout << " Copying all odd values from arr_int03 into deq_int02 starting from deq_int02 begining." << std::endl;

  std::cout << "------- Before Copy" << std::endl;
  std::cout << "arr_int03 Contents" << std::endl;
  print_collection_copy(arr_int03);
  std::cout << "deq_int02 Contents" << std::endl;
  print_collection_copy(deq_int02);

  auto filter = [](int val) {
    return (val % 2) != 0;
  };

  std::copy_if(std::begin(arr_int03), std::end(arr_int03), std::begin(deq_int02),filter);

  std::cout << "------- After Copy" << std::endl;
  std::cout << "arr_int03 Contents" << std::endl;
  print_collection_copy(arr_int03);
  std::cout << "deq_int02 Contents" << std::endl;
  print_collection_copy(deq_int02);
}