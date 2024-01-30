export module modNumFour;

import <iostream>;

// Module Purview
export {
	double add_v4(double a, double b);
	void greet_v4(const std::string& name);

	class Pointv4 {
	public:
		Pointv4() = default;
		Pointv4(double x, double y);
		friend std::ostream& operator << (std::ostream& out, const Pointv4& point) {
			out << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
			return out;
		}
	private:
		double m_x;
		double m_y;
	};
};
