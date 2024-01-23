// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <functional> // This Library Includes Definitions for System Provided Functors

#include "BoxContainer.hpp"
#include "EncryptFunctor.hpp"
#include "DecryptFunctor.hpp"
#include "IsInRangeFunctor.hpp"
#include "ClassWithNestedLambda.hpp"

// Template Type Alias
template <typename T>
using compare_T = bool (*) (const T&, const T&);

// Template Greatest Function
template <typename T>
T find_in_set (const BoxContainer<T>& bc, compare_T<T> comparator) 
{
  T output = bc.get_item(0);
  
  for (size_t i{}; i < bc.size(); i++) {
    if(comparator(bc.get_item(i), output)) {
      output = bc.get_item(i);
    }
  }

  return output;
}

// Callbacks which can map to the compare_T function
bool compare_string_size (const std::string& a, const std::string& b) 
{
  if (a.size() > b.size()) {
    return true;
  }

  return false;
}

bool compare_string_lex (const std::string& a, const std::string& b) 
{
  return a > b;
}

bool compare_int (const int& a, const int& b) 
{
  return a > b;
}

// Templated Callback Function
template <typename T>
bool least (const T& a, const T& b) 
{
  return a < b;
}


// Template for Function which will modify a string (Modifier can be a functor or function pointer)
template <typename Modifier>
std::string& modify(std::string& input, Modifier modifier) 
{
  for (size_t i{}; i < input.size(); i++) 
  {
    input[i] = modifier(input[i]);
  }

  return input;
}


// Template for function using Functor with Parameters (RangePicker should b e aFunctor which holds the operable range)
template <typename T ,typename RangePicker>
requires std::is_arithmetic_v<T>
T range_sum (const BoxContainer<T>& collection, RangePicker is_in_range){
    
    T sum{};
    for(size_t i{}; i < collection.size() ; ++i){
        if(is_in_range(collection.get_item(i)))
            sum += collection.get_item(i);
    }
    return sum;
}



char encrypt_std_func(const char& param) {
  return static_cast<char> (param + 3);
}


int main(int argc, char* argv[])
{ 
  std::cout << "========== Template Type Alias ============" << std::endl;
  BoxContainer<std::string> bc_str1 = BoxContainer<std::string>();
  bc_str1.add("This");
  bc_str1.add("is");
  bc_str1.add("a");
  bc_str1.add("Test");

  std::cout << "-------- String Tests --------" << std::endl;
  std::cout << "Greatest on Size: " << find_in_set(bc_str1, compare_string_size) << std::endl;
  std::cout << "Greatest Lexographically: " << find_in_set(bc_str1, compare_string_lex) << std::endl;


  BoxContainer<int> bc_int1 = BoxContainer<int>();
  bc_int1.add(100);
  bc_int1.add(500);
  bc_int1.add(20);
  bc_int1.add(399);

  std::cout << "-------- Int Tests --------" << std::endl;
  std::cout << "Greatest in Value: " << find_in_set(bc_int1, compare_int) << std::endl;
  std::cout << "Least in Value: " << find_in_set(bc_int1, least) << std::endl;


  std::cout << std::endl;
  std::cout << "========== Functors ============" << std::endl;

  EncryptFunctor encrypt;
  DecryptFunctor decrypt;

  std::string functor_test1 {"Hello"};
  std::cout << "------- Functor Encrypt/Decrypt Test -------" << std::endl;
  std::cout << "Staring Value: " << functor_test1 << std::endl;
  std::cout << "After Encryption: " << modify(functor_test1, encrypt) << std::endl;
  std::cout << "After Decryption: " << modify(functor_test1, decrypt) << std::endl;


  std::cout << "------- System Provided Functors -------" << std::endl;
  std::plus<int> adder;
  std::greater<int> compare_greater;
  std::cout << adder(100, 200) << std::endl;
  std::cout << compare_greater(10, 20) << std::endl;

  std::cout << "------- Functor With Parameters -------" << std::endl;
  IsInRangeFunctor<int> inrange1 = IsInRangeFunctor<int>(5, 20);
  std::cout << "Checking if 7 is in range 5 - 20: " << inrange1(7) << std::endl;
  std::cout << "Checking if 50 is in range 5 - 20: " << inrange1(50) << std::endl;

  BoxContainer<int> bc_int2 = BoxContainer<int>();
  bc_int2.add(100);
  bc_int2.add(500);
  bc_int2.add(20);
  bc_int2.add(399);
  IsInRangeFunctor<int> inrange2 = IsInRangeFunctor<int>(50, 400);
  std::cout << "Summing Box Container values in range 50 - 400: " << range_sum(bc_int2, inrange2) << std::endl;


  std::cout << "------- Lambda Function -> These compile to Functors behind the scenes -------" << std::endl;
  int ex_lambda1 = [] (int x, int y) -> int {return x + y;} (7, 3);
  std::cout << ex_lambda1 << std::endl;
  std::cout << "Since Lambda Functions are Functors they can be used as callbacks!" << std::endl;

  auto encrypt_lambda = [] (const char& input) {
    return static_cast<char> (input + 3);
  };

  auto decrypt_lambda = [] (const char& input) {
    return static_cast<char> (input - 3);
  };

  std::string functor_test2 {"Hello"};
  std::cout << "Staring Value: " << functor_test2 << std::endl;
  std::cout << "After Encryption: " << modify(functor_test2, encrypt_lambda) << std::endl;
  std::cout << "After Decryption: " << modify(functor_test2, decrypt_lambda) << std::endl;


  std::cout << "------- Lambda Function w/ Capture by Values -------" << std::endl;
  int ex_lambda2_in_a = 100;
  int ex_lambda2_in_b = 200;
  auto ex_lambda2 = [ex_lambda2_in_a, ex_lambda2_in_b] (int x, int y) -> int {
    std::cout << "Captured Values: " << ex_lambda2_in_a << " : " << ex_lambda2_in_b << std::endl;
    std::cout << "Input Values: " << x << " : " << y << std::endl;
    
    return ex_lambda2_in_a + ex_lambda2_in_b + x + y;
  };

  std::cout << "Executing Lambda with Caputured Values: " << ex_lambda2(-100, -100) << std::endl;
  
  // = in the capture list captures all variables by value, it only uses the values used in the lambda body but this is stupid confusing, don't use this
  // int ex_lambda_capture_all_dont_use = [=] (int x, int y) -> int {return x + y}; 

  // It is also possible to mark lambda functions as mutable which will give you the ability to modify captured values, don't do this it is confusing and will be hard to follow
  // auto ex_lambda_mutable_dont_use = [ex_lambda2_in_a, ex_lambda2_in_b] (int x, int y) mutable {
  //   ex_lambda2_in_a++;
  //   return x + y
  // };

  std::cout << "------- Lambda Function w/ Capture by Reference -------" << std::endl;
  int ex_lambda3_in_a = 100;
  int ex_lambda3_in_b = 200;
  auto ex_lambda3 = [&ex_lambda3_in_a, &ex_lambda3_in_b] (int x, int y) -> int {
    ex_lambda3_in_a++;
    std::cout << "Captured Values: " << ex_lambda3_in_a << " : " << ex_lambda3_in_b << std::endl;
    std::cout << "Input Values: " << x << " : " << y << std::endl;
    
    return ex_lambda3_in_a + ex_lambda3_in_b + x + y;
  };

  // & in the capture list captures all variables by reference, it only uses those used in the lambda body but this is stupid confusing, don't use this
  // int ex_lambda_capture_all_ref_dont_use = [&] (int x, int y) -> int {return x + y}; 


  std::cout << "------- Class With Nested Lambda -------" << std::endl;
  ClassWithNestedLambda cwnl_1 = ClassWithNestedLambda(300, 400);
  cwnl_1.do_something();


  std::cout << "------- Using std::function Abstraction -------" << std::endl;
  std::cout << "Note: This helps reduce the need for templates" << std::endl;
  // std::function<output_type(input_types)> var_name;
  std::function<char(const char&)> ex_modifier1;
  // This std::function can be used to represent any of Funtion Pointer, Functor, Lambda

  std::cout << "Assigning std::function to function pointer" << std::endl;
  char (*ex_func_point1) (const char&) = encrypt_std_func;
  ex_modifier1 = ex_func_point1;
  char ex_modifier1_char1 {'A'};
  std::cout << "Using Pointer Version: " << ex_modifier1(ex_modifier1_char1) << std::endl;

  std::cout << "Assigning std::function to functor" << std::endl;
  ex_modifier1 = encrypt;
  char ex_modifier1_char2 {'D'};
  std::cout << "Using Pointer Version: " << ex_modifier1(ex_modifier1_char2) << std::endl;


  std::cout << "Assigning std::function to lambda" << std::endl;
  auto ex_lambda_encrypt = [](const char& a) {return static_cast<char>(a + 3);};
  ex_modifier1 = ex_lambda_encrypt;
  char ex_modifier1_char3 {'G'};
  std::cout << "Using Pointer Version: " << ex_modifier1(ex_modifier1_char3) << std::endl;


  return 0;
}
