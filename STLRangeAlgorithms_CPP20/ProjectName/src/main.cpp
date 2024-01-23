// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <functional> // This Library Includes Definitions for System Provided Functor
#include <vector>
#include <deque>
#include <array>
// #include <algorithm>

#include "STD_ContainerChecks.hpp"
#include "STD_ForEach.hpp"
#include "STD_MaxMin.hpp"
#include "STD_Find.hpp"
#include "STD_Copy.hpp"
#include "STD_Sort.hpp"
#include "STD_Transform.hpp"
#include "CPP_Projection.hpp"
#include "CPP_View.hpp"

int main(int argc, char* argv[])
{ 
  bool run_cchks = false;
  bool run_foreach = false;
  bool run_maxmin = false;
  bool run_find = false;
  bool run_copy = false;
  bool run_sort = false;
  bool run_transform = false;
  bool run_projection = false;
  bool run_view = true;

  if (run_cchks) {
    STD_ContainerChecks<int> std_chks = STD_ContainerChecks<int>();
    std_chks.execute();
  }
  
  if (run_foreach) {
    STD_ForEach std_freh = STD_ForEach();
    std_freh.execute();
  }

  if (run_maxmin) {
    STD_MaxMin std_mm = STD_MaxMin();
    std_mm.execute();
  }

  if (run_find) {
    STD_Find std_find = STD_Find();
    std_find.execute();
  }

  if (run_copy) {
    STD_Copy std_copy = STD_Copy();
    std_copy.execute();
  }

  if (run_sort) {
    STD_Sort std_sort = STD_Sort();
    std_sort.execute();
  }

  if (run_transform) {
    STD_Transform std_transform = STD_Transform();
    std_transform.execute();
  }

  if (run_projection) {
    CPP_Projection cpp_proj = CPP_Projection();
    cpp_proj.execute();
  }

  if (run_view) {
    CPP_View cpp_view = CPP_View();
    cpp_view.execute();
  }


  std::cout << "END!" << std::endl;

  return 0;
}
