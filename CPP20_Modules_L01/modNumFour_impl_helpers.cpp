module modNumFour;

import <iostream>;


//Implementations
double add_v4(double a, double b) {
	return a + b;
}

void greet_v4(const std::string& name) {
	std::string dest;
	dest = "Hello ";
	dest.append(name);
	std::cout << dest << std::endl;
}
