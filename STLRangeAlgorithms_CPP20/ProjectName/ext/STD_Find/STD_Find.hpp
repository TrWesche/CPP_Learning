#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <cmath>


template <typename T>
void print_collection_find (const T& collection) {
  auto itr = collection.begin();

  std::cout << "{ ";
  
  while (itr != collection.end()) {
  std::cout << *itr << " ";
  itr++;
  }

  std::cout << "}" << std::endl;;
};
 

class STD_Find
{
private:


public:
    STD_Find(/* args */);
    ~STD_Find();

    void execute();
};

STD_Find::STD_Find(/* args */)
{
}

STD_Find::~STD_Find()
{
}

void STD_Find::execute() {
  std::vector<int> vec_int01 {1, 2, 3, 4, 5, 6};
  std::deque<int> deq_int02 {10, 20, 30, 40, 50};
  std::array<int, 5> arr_int03 {2, 6, 5, 8, 9};
  

  std::cout << "======= std::ranges::find =======" << std::endl;  
  std::cout << " Note: This does not return the value, it returns an iterator which can be checked to determine if the value was found (i.e. if the iterator returns is equal to the end iteraor for the collection)." << std::endl;
  int target_value = 3;
  std::cout << "Searching for " << target_value << " in vec_int01" << std::endl;
  print_collection_find(vec_int01);
  std::vector<int>::iterator find_result_vec = std::ranges::find(std::begin(vec_int01), std::end(vec_int01), target_value);
  if (find_result_vec != std::end(vec_int01)) {
    std::cout << " Value Found: " << *find_result_vec << std::endl;
  } else {
    std::cout << " Value Not Found" << std::endl;
  }
  
  

  std::cout << "----------" << std::endl;  
  target_value = 3;
  std::cout << "Searching for " << target_value << " in deq_int02" << std::endl;
  print_collection_find(deq_int02);
  std::deque<int>::iterator find_result_deq = std::ranges::find(std::begin(deq_int02), std::end(deq_int02), target_value);
  if (find_result_deq != std::end(deq_int02)) {
    std::cout << " Value Found: " << *find_result_deq << std::endl;
  } else {
    std::cout << " Value Not Found" << std::endl;
  }


  std::cout << std::endl;
  std::cout << "======= std::find_if =======" << std::endl;  
  std::cout << " - This searches for items which meet certain conditions as defined by a callback function." << std::endl;
  std::cout << " - Returns an iterator which points to the first instance of a match from the front of the collection." << std::endl;
  
  auto matcher_func = [](int val){
    if (val % 2 != 0) {
      return true;
    } 
    return false;
  };

  std::cout << "Searching for odd values in arr_int03" << std::endl;
  print_collection_find(arr_int03);
  std::array<int, 5>::iterator find_if_result_arr = std::ranges::find_if(std::begin(arr_int03), std::end(arr_int03), matcher_func);
  if (find_if_result_arr != std::end(arr_int03)) {
    std::cout << " Value Found: " << *find_if_result_arr << std::endl;
  } else {
    std::cout << " Value Not Found" << std::endl;
  }
   

  std::cout << std::endl;
  std::cout << "======= std::find_if_not =======" << std::endl;  
  std::cout << " - No example provided, a not version of the find_if does exist" << std::endl;
}