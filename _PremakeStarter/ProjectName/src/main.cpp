// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "ProjectName/ProjectClass.hpp"

int main(int argc, char* argv[])
{
  TW::ProjectClass temp = TW::ProjectClass();

  std::cout << "Main Function Called, Class Created" << std::endl;
  std::cout << temp.get_m_sample() << std::endl;

  return 0;
}
