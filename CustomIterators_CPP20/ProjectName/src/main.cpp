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

  std::cout << "\n---------------- Find Function (Input Iterator) ----------------" << std::endl;
  // Find Function is Using:
  // _EC_Itr operator != which is comparing the actual values of the left and right iterators
  // _EC_Itr operator * which is returning a reference to the value at the current pointer location
  // _EC_Itr operator ++ which is used to move through the iterator from beginning to end
  // _EC_Itr operator == which is comparing the pointer locations to see if the end of the conatiner has been reached
  auto ec_intf2_res = std::ranges::find(ec_int1, 40);
    if (ec_intf2_res == ec_int1.end()) {
    std::cout << "Failed to find 40" << std::endl;
  } else {
    std::cout << "Found " << *ec_intf2_res << "!" << std::endl;
  }

  std::cout << "\n---------------- Copy Function (Output Iterator) ----------------" << std::endl;
  // The Copy Function is Using:
  // _EC_Itr operator == which is comparing the pointer locations to see if the targeted iterator loop end has been reached
  // _EC_Itr operator * which is returning a reference to the value at the current pointer location for both the soucre and destination which can be used to make a copy from one container to the other
  // _EC_Itr operator ++ which is used to move through the iterator from beginning to end
  EntityContainer<int> ec_int2 = EntityContainer<int>(10);
  std::cout << "While the copy will bring the data over to the new container it won't updated the m_size or m_reservation so we are going to initialize the target container with 0s" << std::endl;
  for (size_t i{}; i < ec_int1.size(); ++i) {
    ec_int2.push_back(0);
  }
  std::cout << "Initialized: ";
  std::cout << ec_int2 << std::endl;
  // std::ranges::copy(ec_int1.begin(), ec_int1.end(), ec_int2.begin());
  std::ranges::copy(ec_int1, ec_int2.begin());
  std::cout << "After Copy: ";
  std::cout << ec_int2 << std::endl;


  std::cout << "\n---------------- Replace Function (Forward Iterator) ----------------" << std::endl;
  // The Replace Function is Using:
  // _EC_Itr operator == which is comparing the pointer locations to see if the targeted iterator loop end has been reached
  // _EC_Itr operator != which is comparing the pointer values to see if there is a match
  // _EC_Itr operator * which is returning a reference to the value at the current pointer location which allows the new value to be written in when a match is found
  // _EC_Itr operator ++ which is used to move through the iterator from beginning to end
  ec_int2.push_back(100);
  ec_int2.push_back(45);
  ec_int2.push_back(67);
  ec_int2.push_back(100);
  ec_int2.push_back(100);

  std::cout << "Before Replace (Replacing 100 with 999): ";
  std::cout << ec_int2 << std::endl;
  std::ranges::replace(ec_int2, 100, 999);
  std::cout << "After Replace: ";
  std::cout << ec_int2 << std::endl;

  std::cout << "END!" << std::endl;

  return 0;
}
