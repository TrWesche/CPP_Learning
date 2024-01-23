#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>


template <typename T>
void print_collection_foreach (const T& collection) {
  auto itr = collection.begin();

  std::cout << "{ ";
  
  while (itr != collection.end()) {
  std::cout << *itr << " ";
  itr++;
  }

  std::cout << "}" << std::endl;;
};


void add_one_foreach(int& n) {
  n++;
};


class DoubleForEach
{
  public: 
    void operator() (int& input) {
      input = input * 2;
    }
};

class SumForEach
{
  public:
    void operator() (const int& input) {
      sum += input;
    }

    int getSum() {
      return sum;
    }
  
  private:
    int sum{};
};


class STD_ForEach
{
private:


public:
    STD_ForEach(/* args */);
    ~STD_ForEach();

    void execute();
};

STD_ForEach::STD_ForEach(/* args */)
{
}

STD_ForEach::~STD_ForEach()
{
}

void STD_ForEach::execute() {
  std::vector<int> vec_int01 {1, 2, 3, 4, 5, 6};
  std::deque<int> deq_int02 {2, 4, 6, 8, 10};
  std::array<int, 5> arr_int03 {1, 3, 5, 7, 9};
  

  std::cout << "======= std::ranges::for_each =======" << std::endl;
  std::cout << " ----- add one for each (Function Pointer): vec_int01 ------ Before" << std::endl;
  print_collection_foreach(vec_int01);
  
  std::ranges::for_each(
    vec_int01,
    add_one_foreach
  );
  std::cout << " ----- add one for each (Function Pointer): vec_int01 ------ After" << std::endl;
  print_collection_foreach(vec_int01);
  
  


  std::cout << std::endl;
  std::cout << " ----- subtract one for each (Lambda Pointer): deq_int02 ------ Before" << std::endl;
  print_collection_foreach(deq_int02);
  
  std::ranges::for_each(
    deq_int02,
    [](int& val){val--;}
  );
  std::cout << " ----- subtract one for each (Lambda Pointer): deq_int02 ------ After" << std::endl;
  print_collection_foreach(deq_int02);




  std::cout << std::endl;
  std::cout << " ----- Double each (Functor): arr_int03 ------ Before" << std::endl;
  print_collection_foreach(arr_int03);
  
  std::ranges::for_each(
    arr_int03,
    DoubleForEach()
  );
  std::cout << " ----- Double each (Functor): arr_int03 ------ After" << std::endl;
  print_collection_foreach(arr_int03);


  std::cout << std::endl;
  std::cout << " ------ For Each can also be used for accumulation, you could also do accumulation with a lambda with a value in the capture list" << std::endl;
  std::cout << "Summing Values(deq_int02): " << std::endl;
  print_collection_foreach(deq_int02);
  int lambda_sum{};
  std::ranges::for_each(deq_int02, [&lambda_sum](const int val){lambda_sum += val;});
  std::cout << "Total (deq_int02): " << lambda_sum << std::endl;
}

