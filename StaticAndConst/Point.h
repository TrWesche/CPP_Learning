#include <cmath>
#include <iostream>

class Point
{
// Statics
public:
    // Not tied to objects, they are with the class blueprint.  Initialized before anything gets run.
    static size_t m_point_count;
    // inline static size_t m_point_count {}; //Have to mark this variable as inline if you want the static to be initialized wiht the class
    
    static Point m_origin_point; //Can initialize a Point before main this way

    static size_t get_point_count();

    static void print_point_info(const Point& p);

// Member Variables
private:
    double m_x {};
    double m_y {};
    Point* p_m_origin_point; //If you need the point not to be a static you can't initialize it during class construction.  You can get around this by using a pointer, setting it to nullptr, and the updating it later.

// Consructor/Destructor
public:
    Point(double in_x, double in_y);
    Point(double in_xy);
    Point();
    Point(const Point& point);

    ~Point();

// Setter/Getter
public:
    double get_x() const {
        return m_x;
    }

    double get_y() const {
        return m_y;
    }

    Point* set_x(double in_x) {
        m_x = in_x;
        return this;
    }

    Point* set_y(double in_y) {
        m_y = in_y;
        return this;
    }



// Methods
public:
    double distance() const;
    double distance(const Point& dest) const;
    void print_info() const;
    void print_addr() const;
    
};


