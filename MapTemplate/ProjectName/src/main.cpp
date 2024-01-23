// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "ProjectName/Map.hpp"


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

  return 0;
}
