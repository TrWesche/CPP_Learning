export module Point;

import <iostream>;


export {
	class Point {
		friend std::ostream& operator<< (std::ostream& os, const Point& point) {
			os << "[Point x: " << point.m_x << " y: " << point.m_y << "]";
			return os;
		};

	public:
		Point(double x, double y) :
			m_x(x), m_y(y) {};
		~Point() = default;

		double get_x() {
			return m_x;
		};

		double get_y() {
			return m_y;
		};

	private:
		double m_x;
		double m_y;
	};
};