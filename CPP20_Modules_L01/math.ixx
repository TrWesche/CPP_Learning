module;
// Global module fragment: #include, pre-processor directives go here
export module math_module;

// Module preamble (import other modules?)
import <iostream>; // This is a header unit, provided by C++ 20 allowing usage of old headers as C++ modules

// Module purview
export void do_something() {
	std::cout << "Math Module Function do_something called" << std::endl;
};