module;
// Global module fragment: #include, pre-processor directives go here
#include <cstring>
//#include <string>

export module math_module;

// Module preamble (import other modules?)
import <iostream>; // This is a header unit, provided by C++ 20 allowing usage of old headers as C++ modules

// Module purview
export void do_something() {
	std::cout << "Math Module Function do_something called" << std::endl;
};

export long add_two(long a, long b) {
	return a + b;
};

export double add_two(double a, double b) {
	return a + b;
};

export {
	void greet(const std::string& name) {
		std::string output;
		output = "Hello ";
		output.append(name);
		std::cout << output << std::endl;
	};

	void print_name_length(const char* c_str_name) {
		std::cout << "String Length: " << std::strlen(c_str_name) << std::endl;
	};
};