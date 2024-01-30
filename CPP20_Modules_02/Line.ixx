export module Line;

export import Point;

import <iostream>;

export {
	class Line
	{
		friend std::ostream& operator<< (std::ostream& os, const Line& line) {
			os << "{ Line\na: " << line.m_a << "\nb: " << line.m_b << "\n}";
			return os;
		};

	public:
		Line(Point a, Point b) : m_a(a), m_b(b) {};
		~Line() = default;

		Point get_a() const {
			return m_a;
		};

		Point get_b() const {
			return m_b;
		};

	private:
		Point m_a;
		Point m_b;
	};
};