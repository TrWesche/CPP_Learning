#pragma once
#include <cmath>

class Point{
    public:
        Point(double in_x, double in_y) : m_x(in_x), m_y(in_y) {};
        
        friend double distance(const Point& from, const Point& to);

	private : 
    	double m_x{1};
    	double m_y{1};
};


//Computes and returns the distance between to points as double
double distance(const Point& from, const Point& to);
