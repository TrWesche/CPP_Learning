// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "BoxContainer.hpp"

int add_two(int x, int y) {
  return x + y;
}


void populate_box(BoxContainer<int>& box, int modifier){
	for(size_t i{0} ; i < 20 ; ++i){
		box.add((i+1)*modifier);
	}
}

BoxContainer<int> make_box(int modifier){
	BoxContainer<int> local_int_box(20);
	populate_box(local_int_box,modifier);
	return local_int_box;
}

// !!!!! Move Semantics Content - Using std::move to swap data without invoking copy constructors
//  - Note: std::move does not perform the move, a Move Constructor / Move Assigment Operator must be defined to be used
//          std::move casts the LValue being moved to an RValue causing these constructors/methods to be invoked
template <class T>
void swap_data(T& a, T& b) {
  T temp {std::move(a)}; // Invokes Move Constructor
  a = std::move(b); // Invokes Move Assigment Operator
  b = std::move(temp); // Invokes Move Assigment Operator
}


int main(int argc, char* argv[])
{
  // LValues
  int x{5};
  int y{10};
  int z{20};

  // RValues:: 
  z = x + y; // x + y results in a temporary value which is stored in memory for a short amount of time before it is assigned (copied) to z - &(x + y) will result in an error cannot get a refernce of a temporary value
  z = add_two(x, y); // the value returned by add_two is stored in a temporary variable (the function does not return by reference)
  z = 45; // Literals are also temporary values - &45 will result in an error


  // RValue References - && - This will cause the temporary value to be retained by the compiler
  int&& xy = x + y; 
  int&& addTwoXY = add_two(x, y);

  BoxContainer<int> bc1 = BoxContainer<int>();
  bc1.add(1);
  bc1.add(2);
  std::cout << "Content bc1" << std::endl;
  std::cout << bc1 << std::endl;

  BoxContainer<int> bc2 = bc1;
  bc2.add(10);
  std::cout << "Content bc2" << std::endl;
  std::cout << bc2 << std::endl;

  BoxContainer<int> bc3 = BoxContainer<int>(bc2);
  std::cout << "Content bc3" << std::endl;
  std::cout << bc3 << std::endl;

  
  BoxContainer<int> box_array[2];

    std::cout << "--------" << std::endl;

	for(size_t i{0} ; i < 2 ; ++i){
		box_array[i] = make_box(i+1); //Move assigment operator called at each iteration
	}

  std::cout << "--------" << std::endl;

  std::cout << "Swapping bc1, bc3" << std::endl;
  swap_data(bc1, bc3);
  std::cout << "Content bc1" << std::endl;
  std::cout << bc1 << std::endl;
  std::cout << "Content bc3" << std::endl;
  std::cout << bc3 << std::endl;




  // !!!! Important on the behavior of the RValue References.  If you assign it to a variable it will become an LValue and will be treated as such
  // BoxContainer&& bc_rref = get_box_container();  // If get_box_container() returns a rvalue but you assign it to a variable....
  // BoxContainer bc_rref_2;
  // bc_rref_2 = bc_rref;   // This assignment will use the copy assignment operator
  // bc_rref_2 = std::move(bc_rref); // This will behave as expected using the Move assignment operator

  return 0;
}
