// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "ProjectName/Map.hpp"
#include "Point.hpp"

// Explicit template instantiations - tells compiler to generate full templates for these
//    - Mainly used for debugging templates
template class Point<double, 3>;
template class Point<double, 2>;

int main(int argc, char* argv[])
{
  Map map1{1, "sometext"};

  Map map2{"key1", 1235.0f};

  std::cout << "MAP 1" << std::endl;
  std::cout << "key : " << map1.m_key << std::endl;
  std::cout << "value : " << map1.m_value << std::endl;

  std::cout << "MAP 2" << std::endl;
  std::cout << "key : " << map2.m_key << std::endl;
  std::cout << "value : " << map2.m_value << std::endl;

  
  Point<int, 2> point2D_1{};
  point2D_1.set_value(0, 1);
  point2D_1.set_value(1, 2);
  point2D_1.set_value(2, 3);
  
  std::cout << point2D_1 << std::endl;


  std::cout << "Running Print Info" << std::endl;
  point2D_1.print_info();
  


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
  


  Point pointDefault{};
  pointDefault.set_value(0, 1);
  pointDefault.set_value(1, 2);
  pointDefault.set_value(2, 3);
  
  std::cout << pointDefault << std::endl;

  return 0;
}
