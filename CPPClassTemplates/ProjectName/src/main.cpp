// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "ProjectName/ProjectClass.hpp"
#include "ProjectName/Point.hpp"
#include "BoxContainer.hpp"


int main(int argc, char* argv[])
{
  TW::ProjectClass temp = TW::ProjectClass();

  std::cout << "Main Function Called, Class Created" << std::endl;
  std::cout << temp.get_m_sample() << std::endl;

  TW::BoxContainer intContainer1 = TW::BoxContainer<int>();
  intContainer1.push(1);

  std::cout << intContainer1 << std::endl;



  TW::BoxContainer stringContainer1 = TW::BoxContainer<std::string>();
  stringContainer1.push("ABC123");

  std::cout << stringContainer1 << std::endl;



  TW::BoxContainer floatContainer1 = TW::BoxContainer<float>();
  floatContainer1.push(1001.01f);
  floatContainer1.push(2002.02f);

  std::cout << floatContainer1 << std::endl;


  Point point1 = Point(1.0, 2.0);
  Point point2 = Point(2.0, 3.0);
  TW::BoxContainer pointContainer1 = TW::BoxContainer<Point>();
  pointContainer1.push(point1);
  pointContainer1.push(point2);

  std::cout << pointContainer1 << std::endl;


  return 0;
}
