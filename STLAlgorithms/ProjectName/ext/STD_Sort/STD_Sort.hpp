#pragma once

#include<iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <cmath>


template <typename T>
void print_collection_sort (const T& collection) {
  auto itr = collection.begin();

  std::cout << "{ ";
  
  while (itr != collection.end()) {
  std::cout << *itr << " ";
  itr++;
  }

  std::cout << "}" << std::endl;;
};
 

class STD_Sort
{
private:


public:
    STD_Sort(/* args */);
    ~STD_Sort();

    void execute();
};

STD_Sort::STD_Sort(/* args */)
{
}

STD_Sort::~STD_Sort()
{
}

void STD_Sort::execute() {
  std::vector<int> vec_int01 {21, 2, 33, 14, 95, 16};
  std::deque<int> deq_int02 {910, 20, 130, 540, 50};
  std::array<int, 5> arr_int03 {2, 6, 5, 8, 9};
  

  std::cout << "======= std::sort =======" << std::endl;  
  std::cout << " Provides the ability to sort data in a collection" << std::endl;
  std::cout << " Important: The collection must support random iterator (i.e. [] operator should be there) as well as the comparison operator(s) needed to accomplish the sort" << std::endl;

  std::cout << "Sorting vec_int01 with default sort (lowest to highest)" << std::endl;
  std::cout << "------- Before Sort" << std::endl;
  print_collection_sort(vec_int01);

  std::sort(std::begin(vec_int01), std::end(vec_int01));

  std::cout << "------- After Sort" << std::endl;
  print_collection_sort(vec_int01);
  
 
  std::cout << std::endl;
  std::cout << "Sorting deq_int02 highest to lowest" << std::endl;
  std::cout << "------- Before Sort" << std::endl;
  print_collection_sort(deq_int02);

  std::sort(std::begin(deq_int02), std::end(deq_int02), std::greater<int>());

  std::cout << "------- After Sort" << std::endl;
  print_collection_sort(deq_int02);
}