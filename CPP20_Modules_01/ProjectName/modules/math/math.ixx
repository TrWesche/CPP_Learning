module;
//Global module fragment : #include , preprocessor directives
#include <iostream>

export module ProjectMathModule;
//Module preamble: imports
// import <iostream>;

//Module purview
export void say_something() {
	std::cout << "Saying something..." << std::endl;
}