#include <iostream>
#include "Point.h"


int main(int argc, char **argv){
    std::cout << "Quantity Points: " << Point::m_point_count << std::endl;

    Point p1{10.0, 5.0};
    Point p2{20.0, 0.0};

    p1.print_addr();
    p2.print_addr();
    std::cout << "Quantity Points: " << Point::m_point_count << std::endl;

    Point p3{8.0, 4.0};
    p3.print_addr();
    std::cout << "Quantity Points: " << Point::m_point_count << std::endl;

    Point::print_point_info(p3);

    return 0;
}