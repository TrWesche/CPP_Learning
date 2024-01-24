// A simple program that computes the square root of a number
#include <iostream>
#include <algorithm>

#include "CPP_Iterators.hpp"
#include "EntityContainer.hpp"


int main(int argc, char* argv[])
{ 
  bool run_iterators = false;

  if (run_iterators) {
    CPP_Iterators cpp_iterators = CPP_Iterators();
    cpp_iterators.execute();
  }
  

  EntityContainer<int> ec_int1 = EntityContainer<int>();
  // ec_int1.emplace_back(100);
  ec_int1.push_back(100);
  ec_int1.push_back(200);
  ec_int1.push_back(222);
  ec_int1.push_back(137);
  ec_int1.push_back(24);
  ec_int1.push_back(55);


  std::cout << "\n---------------- Sort Function (Random Access Iterator) ----------------" << std::endl;
  // The Reverson Function is Using:
  // _EC_Itr operator == which is comparing the pointer locations to see if the targeted iterator loop end has been reached
  // _EC_Itr operator * which is returning a reference to the value at the current pointer location for both the soucre and destination which can be used to make a copy from one container to the other
  // _EC_Itr operator -- which is used to move through the iterator from end to beginning
  std::cout << "Random access requires a large number of additional operators to be defined" << std::endl;
  std::cout << "Before Sort: ";
  std::cout << ec_int1 << std::endl;
  std::ranges::sort(ec_int1, std::ranges::less());
  std::cout << "After Sort: ";
  std::cout << ec_int1 << std::endl;


  std::cout << "END!" << std::endl;

  return 0;
}
