export module modNumThree;

import <iostream>;

// Module Purview
export {
	double add_v3(double a, double b);
	void greet_v3(const std::string& name);

	class Pointv3 {
	public:
		Pointv3() = default;
		Pointv3(double x, double y);
		friend std::ostream& operator << (std::ostream& out, const Pointv3& point) {
			out << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
			return out;
		}
	private:
		double m_x;
		double m_y;
	};
};
