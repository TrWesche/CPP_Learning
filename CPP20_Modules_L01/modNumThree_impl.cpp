module modNumThree;

import <iostream>;


//Implementations
double add_v3(double a, double b) {
	return a + b;
}

void greet_v3(const std::string& name) {
	std::string dest;
	dest = "Hello ";
	dest.append(name);
	std::cout << dest << std::endl;
}

//Point constructor
Pointv3::Pointv3(double x, double y) : m_x(x), m_y(y) {};