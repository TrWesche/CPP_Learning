#include <iostream>
#include "Rectangle.h"
#include "Circle.h"

int main(int argc, char **argv){
    // You can't make Shape class directly, it is abstract because of the virutal methods
    const Shape* rect1 = new Rectangle(5, 10, "Rectangle");
    const Shape* circle1 = new Circle(5, "Cirlce");

    std::cout << "Perimiter of Rectangle 1: " <<  rect1->perimiter() << std::endl;;
    std::cout << "Area of Rectangle 1: " <<  rect1->surface_area() << std::endl;;


    std::cout << "Perimiter of Circle 1: " <<  circle1->perimiter() << std::endl;;
    std::cout << "Area of Circle 1: " <<  circle1->surface_area() << std::endl;;

    delete rect1;
    delete circle1;

    return 0;
}