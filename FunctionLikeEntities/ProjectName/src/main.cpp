// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "BoxContainer.hpp"

double add_two(double a, double b) {
  return a + b;
}

double sub_two(double a, double b) {
  return a - b;
}

char encrypt(const char& param) {
  return static_cast<char> (param + 3);
}

char decrypt(const char& param) {
  return static_cast<char> (param - 3);
}

std::string& enc_dec_text(std::string& text, char (*encdec) (const char&)) {
  for(size_t i{}; i < text.size(); i++) {
    text[i] = encdec(text[i]);
  }
  return text;
}

double add_1(double& input) {
  return input + 1;
}

double multiply_by_2(double & input) {
  return input * 2;
}

void modify(double input[], double (*transform) (double&), size_t length)
{
  for (size_t i{}; i < length; i++) {
      input[i] = transform(input[i]);
  }
}

// Type Alias for The Function Pointer Types
// Note: Same can be accomplished with a typedef, but typedef is a deprecated syntax that should not be used going forward
using char_mod = char (*) (const char&);
BoxContainer<std::string> encdec_box_content(BoxContainer<std::string>& box, char_mod encdec) 
{
  for (size_t i{}; i < box.size(); i++)
  {
    for (size_t j{}; j < box.get_item(i).length(); j++)
    {
      box.get_item(i)[j] = encdec(box.get_item(i)[j]);
    }
  }

  return box;
}

int main(int argc, char* argv[])
{
  std::cout << "------- Basic Definition of a Function Pointer ------" << std::endl;
  // A function pointer can be defined in multiple ways.  All of the below will work:
  // return_type (variable_name) (input_type1, input_type2) = function_which_matches_definition
  double (*ex_func_ptr1) (double, double) = add_two;
  // double (*ex_func_ptr1) (double, double) = &add_two;
  // double (*ex_func_ptr1) (double, double) {add_two};
  // double (*ex_func_ptr1) (double, double) {&add_two};
  // auto ex_func_ptr1 = add_two;
  // auto ex_func_ptr1 = &add_two;
  // auto *ex_func_ptr1 = add_two;
  // auto *ex_func_ptr1 = &add_two;
  std::cout << ex_func_ptr1(10.1, 20.2) << std::endl;

  // Can also reassign this pointer to a function with the same signature
  ex_func_ptr1 = sub_two;
  std::cout << ex_func_ptr1(10.1, 20.2) << std::endl;

  std::cout << "------- Passing a function pointer to another function as a callback ------" << std::endl;
  // Defining the function pointers
  char (*encdec_callback) (const char&) {encrypt};
  std::string testtext_1 {"abcd"};
  std::cout << "Text Before 'Encryption': " << testtext_1 << std::endl;
  enc_dec_text(testtext_1, encdec_callback);
  std::cout << "Text After 'Encryption': " << testtext_1 << std::endl;
  encdec_callback = decrypt;
  enc_dec_text(testtext_1, encdec_callback);
  std::cout << "Text After 'Decryption': " << testtext_1 << std::endl;


  std::cout << "------- Using the callback with class data ------" << std::endl;
  BoxContainer bc1 = BoxContainer<std::string>();
  bc1.add("ABC123");
  bc1.add("XYZ");

  std::cout << "Box Content Before 'Encryption': " << bc1 << std::endl;
  encdec_box_content(bc1, encrypt);
  std::cout << "Box Content After 'Encryption': " << bc1 << std::endl;


  std::cout << "------- Additional Examples ------" << std::endl;
  double scores[] {10.1,20.3,30.2,40.3};
  std::cout << "Before Processing: ";
  for (size_t i{}; i < 4; i++) {std::cout << scores[i] << " ";}
  std::cout << std::endl;

  modify(scores, add_1, 4);
  std::cout << "After Adding 1: ";
  for (size_t i{}; i < 4; i++) {std::cout << scores[i] << " ";}
  std::cout << std::endl;

  modify(scores, multiply_by_2, 4);
  std::cout << "After Multiply By 2: ";
  for (size_t i{}; i < 4; i++) {std::cout << scores[i] << " ";}
  std::cout << std::endl;

  return 0;
}
