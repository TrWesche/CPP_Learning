// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "ProjectName/Map.hpp"
#include "Point.hpp"
#include "Adder.hpp"
#include "AdderCharP.hpp"
#include "FriendFunction.hpp"
#include "MapTwo.hpp"
#include "BoxContainer.hpp"

// Explicit template instantiations - tells compiler to generate full templates for these
//    - Mainly used for debugging templates
template class Point<double, 3>;
template class Point<double, 2>;

int main(int argc, char* argv[])
{
  // --------------------------------------------
  Map map1{1, std::string("sometext")};
  // Map map2{"key1", 1235.0f};
  Map map2{20, std::string("constrained to string")};
  std::cout << "MAP 1" << std::endl;
  std::cout << "key : " << map1.m_key << std::endl;
  std::cout << "value : " << map1.m_value << std::endl;
  std::cout << "MAP 2" << std::endl;
  std::cout << "key : " << map2.m_key << std::endl;
  std::cout << "value : " << map2.m_value << std::endl;

  // --------------------------------------------  
  Point<int, 2> point2D_1{};
  point2D_1.set_value(0, 1);
  point2D_1.set_value(1, 2);
  point2D_1.set_value(2, 3);
  std::cout << point2D_1 << std::endl;
  std::cout << "Running Print Info" << std::endl;
  point2D_1.print_info();
  
  // --------------------------------------------
  Point<int, 3> point3D_1{};
  point3D_1.set_value(0, 1);
  point3D_1.set_value(1, 2);
  point3D_1.set_value(2, 3);
  std::cout << point3D_1 << std::endl;
  std::cout << "Running Print Info" << std::endl;
  point3D_1.print_info();
  std::cout << "Getting Individual Components" << std::endl;
  std::cout << point3D_1.get_value(0) << std::endl;
  std::cout << point3D_1.get_value(1) << std::endl;
  std::cout << point3D_1.get_value(2) << std::endl;
  
  // --------------------------------------------
  Point pointDefault{};
  pointDefault.set_value(0, 1);
  pointDefault.set_value(1, 2);
  pointDefault.set_value(2, 3);
  std::cout << pointDefault << std::endl;

  // --------------------------------------------
  Adder<int> int_adder1{};
  int int_val1{1};
  int int_val2{2};
  std::cout << int_adder1.add_two(int_val1, int_val2) << std::endl;
  Adder<char*> charp_adder1{};
  char charp_val1[] {"Hello"};
  char charp_val2[] {"World"};
  std::cout << charp_adder1.add_two(charp_val1, charp_val2) << std::endl;

  // --------------------------------------------
  FriendFunction<int> ff1;
  ff1.setup(100);
  FriendFunction<double> ff2;
  ff2.setup(202.2);
  example_friend(ff1);
  example_friend(ff2);
  std::cout << ff1 << std::endl;


  // --------------------------------------------
  // MapTwo<int> maptwo1{1, 2};
  // std::cout << maptwo1 << std::endl;

  return 0;
}
