#include <cmath>
#include <iostream>
#include <string>

class Point {
    private:
        double m_x {1.0};
        double m_y {1.0};

    public:
        // Constructors
        Point() = default; // Default Constructor

        Point(double x, double y) {
            this->m_x = x;
            this->m_y = y;
            std::cout << "Built Point at " << this << std::endl;
        }

        // Setters
        Point& set_x(double x) {
            this->m_x = x;
            return *this;
        }

        Point& set_y(double y) {
            this->m_y = y;
            return *this;
        }

    	void print_point(Point& p) {
    	    std::cout << "Point[x : " << p.m_x <<
    	                 ", y : " << p.m_y << "]" << std::endl;
    	}

        double distance_to(Point dest) {
            return std::sqrt( std::pow((this->m_x - dest.m_x),2) + std::pow((this->m_y - dest.m_y), 2) );
        }
};