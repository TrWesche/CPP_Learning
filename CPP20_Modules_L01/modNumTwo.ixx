//module;
// Global Module Fragment.  If no #includes are necessary do not need the module predeclaration

export module modNumTwo;

import <iostream>;

// Module Purview
export {
	double add_v2(double a, double b);
	void greet_v2(const std::string& name);

	class Point {
	public:
		Point() = default;
		Point(double x, double y);
		friend std::ostream& operator << (std::ostream& out, const Point& point) {
			out << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
			return out;
		}
	private:
		double m_x;
		double m_y;
	};
};


//Implementations
double add_v2(double a, double b) {
	return a + b;
}

void greet_v2(const std::string& name) {
	std::string dest;
	dest = "Hello ";
	dest.append(name);
	std::cout << dest << std::endl;
}

//Point constructor
Point::Point(double x, double y) : m_x(x), m_y(y) {};