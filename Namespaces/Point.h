#include <cmath>
#include <iostream>

namespace Geo {
    class Point
    {
    // Statics
    public:
        static size_t m_point_count;
        static size_t get_point_count();
        static void print_point_info(const Point& p);

    // Member Variables
    private:
        double m_x {};
        double m_y {};

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
}

