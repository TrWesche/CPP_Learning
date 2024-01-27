// A simple program that computes the square root of a number
#include <iostream>
#include <algorithm>
#include <ranges>

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
  std::cout << "Additional Implementations Beyond those required for Bidirectional Operation are required for:";
  std::cout << "\n long long operator-(Iterator, Iterator): (Implemented as Friend) Computing the differece between two iterator pointers";
  std::cout << "\n Iterator<T> operator+(long long, Iterator): (Implemented as friend) Summing an offset and iterator where the offset is the value to the left of the + sign";
  std::cout << "\n Iterator<T> operator+(long long): (Implemented Internal) Summing an offset and iterator where the Iterator is the value to the left of the + sign";
  std::cout << "\n Iterator<T>& operator+=(long long): (Implemented Internal) Summing an offset and iterator with the += operator";
  std::cout << "\n Iterator<T> operator-(long long): (Implemented Internal) Subtracting an offset and iterator where the Iterator is the value to the left of the - sign";
  std::cout << "\n Iterator<T>& operator-=(long long): (Implemented Internal) Subtracting an offset and iterator with the -= operator";
  std::cout << "\n T& operator[](long long): (Implemented Internal) Returning a reference to a value at a specific location in the iterator by offset from iterator start";
  std::cout << "\n bool operator<(Iterator): (Implemented Internal) Checking if value at internal iterator location is less than value at right iterator location";
  std::cout << "\n bool operator>(Iterator): (Implemented Internal) Checking if value at internal iterator location is greater than value at right iterator location";
  std::cout << "\n bool operator<=(Iterator): (Implemented Internal) Checking if value at internal iterator location is less than or equal to value at right iterator location";
  std::cout << "\n bool operator>=(Iterator): (Implemented Internal) Checking if value at internal iterator location is greater than or equal to value at right iterator location" << std::endl;
  std::cout << "Before Sort: ";
  std::cout << ec_int1 << std::endl;
  std::ranges::sort(ec_int1, std::ranges::less());
  std::cout << "After Sort: ";
  std::cout << ec_int1 << std::endl;



std::cout << "\n---------------- Entity Container with Views ----------------" << std::endl;
std::cout << "1. Filter to only return even values" << std::endl;
auto evens = [](int a){
  return (a % 2) == 0;
};

std::cout << "Container Contents: " << ec_int1 << std::endl;
std::ranges::filter_view ec_int1_evens = std::ranges::views::filter(ec_int1, evens);
std::cout << "Filtered Values: ";
for (auto val : ec_int1_evens) {
  std::cout << val << " ";
}
std::cout << std::endl;



std::cout << "\n2. Transform values multiplying odd values 10 by" << std::endl;
auto mul_odd_10 = [](int a) {
  if ( (a % 2) == 0 ) {
    return a;
  }
  return a * 10;
};

std::cout << "Container Contents: " << ec_int1 << std::endl;
std::ranges::transform_view ec_int1_xfrm = std::ranges::views::transform(ec_int1, mul_odd_10);
std::cout << "Transformed Values: ";
for (auto val : ec_int1_xfrm) {
  std::cout << val << " ";
}
std::cout << std::endl;



std::cout << "\n3. Take first 3 values" << std::endl;
auto div_by_5 = [](int a) {
  return (a % 5) == 0;
};

std::cout << "Container Contents: " << ec_int1 << std::endl;
std::ranges::take_view ec_int1_take = std::ranges::views::take(ec_int1, 3);
std::cout << "Taken Values: ";
for (auto val : ec_int1_take) {
  std::cout << val << " ";
}
std::cout << std::endl;


std::cout << "\n4. Take While Not Evenly Divisible by 10" << std::endl;
auto div_by_10 = [](int a) {
  return (a % 10) != 0;
};

std::cout << "Container Contents: " << ec_int1 << std::endl;
std::ranges::take_while_view ec_int1_take_while = std::ranges::views::take_while(ec_int1, div_by_10);
std::cout << "Taken Values: ";
for (auto val : ec_int1_take_while) {
  std::cout << val << " ";
}
std::cout << std::endl;



std::cout << "\n.... Other view examples are drop and drop while" << std::endl;


std::cout << "\nWhile these example use an Entity Container with ints for simplicity you can use all of this functionality with more complex types" << std::endl;


std::cout << "END!" << std::endl;

return 0;
}
