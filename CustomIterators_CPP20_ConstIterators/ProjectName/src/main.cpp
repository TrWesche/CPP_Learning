// A simple program that computes the square root of a number
#include <iostream>
#include <algorithm>
#include <ranges>

#include "CPP_Iterators.hpp"
#include "EntityContainer.hpp"

template <typename T>
void print (const EntityContainer<T>& container)
{
  for (auto val : container) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}


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


  std::cout << "\n---------------- Loop Through Container with Const Iterator ----------------" << std::endl;
  std::cout << "Calling defined print function which takes a const reference to the Entity Container which requires a const iterator for printing" << std::endl;
  std::cout << "  This would not work if a const iterator was not defined" << std::endl;
  print(ec_int1);


  std::cout << "\nOne thing to note with Iterators, if your data is stored contiguously in memory a raw Pointer can meet most of your needs for an iterator without all of the additional coding" << std::endl;
  std::cout << "  However if your data is not being stored in a contiguous array (for example a binary tree) defining these iterators to be able to navigate the underlying data structures" << std::endl;
  std::cout << "  using the stl library become very important" << std::endl;

  std::cout << "END!" << std::endl;

  return 0;
}
