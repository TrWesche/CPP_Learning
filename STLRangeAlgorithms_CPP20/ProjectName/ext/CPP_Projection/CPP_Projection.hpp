#pragma once

#include "Point.hpp"
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
void print_projection_collection(const T& collection) {
    auto itr = collection.begin();

    std::cout << "[ ";
    
    while (itr != collection.end()) {
        std::cout << *itr << " ";
        itr++;
    }

    std::cout << "]" << std::endl;

}


class CPP_Projection
{
private:
    /* data */
public:
    CPP_Projection(/* args */);
    ~CPP_Projection();

    void execute();
};


CPP_Projection::CPP_Projection(/* args */)
{
}

CPP_Projection::~CPP_Projection()
{
}

void CPP_Projection::execute() {
    // Point p1 = Point(20.0, 30.0);
    // Point p2 = Point(50.0, 30.0);
    // Point p3 = Point(30.0, 50.0);
    // Point p4 = Point(70.0, 10.0);

    std::cout << "====== CPP Projections allow you to change the way a comparison behaves by substituting in the comparison value to your operator ======" << std::endl;
    std::vector<Point> point_vector1 { {20.0, 30.0}, {50.0, 30.0}, {30.0, 45.0}, {70.0, 10.0} };
    std::cout << "Printing point_vector1 collection before standard less than sort" << std::endl;
    print_projection_collection(point_vector1);
    std::ranges::sort(point_vector1, std::less<>{});
    std::cout << "Post Sort" << std::endl;
    print_projection_collection(point_vector1);
    std::cout << "This sort uses the standard behavior of the sort function which compares distances to the origin to order the items in the collection" << std::endl;

    std::cout << std::endl;
    std::cout << "------ Overriding the standard behavior using a Projection, ordering by the x value of the point" << std::endl;
    std::vector<Point> point_vector2 { {20.0, 30.0}, {50.0, 30.0}, {30.0, 45.0}, {70.0, 10.0} };
    std::cout << "Printing new point_vector2 initialized in the same manner as point_vector1 before projection sort by x" << std::endl;
    print_projection_collection(point_vector2);
    std::ranges::sort(
        point_vector2, 
        std::less<>{}, 
        [](auto const& p){return p.get_x();}
    );
    std::cout << "Post Sort" << std::endl;
    print_projection_collection(point_vector2);
    std::cout << "This sort is utilizing the Lambda syntax where the m_x value of the point is being passed to the std::less algorithm" << std::endl;



    std::cout << std::endl;
    std::cout << "If there is a member function / variable you would like to use for ordering you can also call that directly using the Point reference" << std::endl;
    std::vector<Point> point_vector3 { {20.0, 30.0}, {50.0, 30.0}, {30.0, 45.0}, {70.0, 10.0} };
    std::cout << "Printing new point_vector3 initialized in the same manner as point_vector1 before projection sort by y" << std::endl;
    print_projection_collection(point_vector3);
    std::ranges::sort(
        point_vector3, 
        std::less<>{}, 
        &Point::get_y
    );
    std::cout << "Post Sort" << std::endl;
    print_projection_collection(point_vector3);
    std::cout << "This sort is utilizing call to referenced function (&Point::get_y) whose result is being passed to the std::less algorithm" << std::endl;



}