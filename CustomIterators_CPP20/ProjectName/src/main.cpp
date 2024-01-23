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


  std::cout << ec_int1 << std::endl;

  // // std::cout << *ec_int1.begin() << std::endl;

  // for(auto x : ec_int1) {
  //   std::cout << x << " ";
  // }

  // std::cout << std::endl;

  // auto ec_intf1_res = std::find(ec_int1.begin(), ec_int1.end(), 55);
  // if (ec_intf1_res == ec_int1.end()) {
  //   std::cout << "Failed to find 55" << std::endl;
  // } else {
  //   std::cout << "Found " << *ec_intf1_res << "!" << std::endl;
  // }

  // auto x = std::ranges::end(ec_int1);
  // auto y = std::ranges::begin(ec_int1);

  auto ec_intf2_res = std::ranges::find(ec_int1, 40);
    if (ec_intf2_res == ec_int1.end()) {
    std::cout << "Failed to find 40" << std::endl;
  } else {
    std::cout << "Found " << *ec_intf2_res << "!" << std::endl;
  }


  std::cout << "END!" << std::endl;

  return 0;
}
