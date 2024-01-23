#include <iostream>
#include "Shape.h"
#include "Oval.h"
#include "Circle.h"
#include "Triangle.h"

void draw_shape(Shape * s) {
    s->draw();
}

void draw_shape_ref(const Shape& s) {
    s.draw();
}

int main(int argc, char **argv){
    Shape shape1("DefaultShape");
    Oval oval1("Oval1", 3.5, 7.5);
    Circle circle1("Circle1", 11.1);

    std::cout << "=== Calling draw method through Shape Pointer binding ===" << std::endl;

    // If the "virtual" keyword is not used this will follow Static binding.  I.e.
    // The compiler will use the type of the pointer to determine which draw method 
    // to call so the base Shape draw will be called each time here.
    Shape * shapePtr1 = &shape1;
    shapePtr1->draw();

    shapePtr1 = &oval1;
    shapePtr1->draw();

    shapePtr1 = &circle1;
    shapePtr1->draw();

    std::cout << "=== Calling draw method through Local functions by Pointer & Reference ===" << std::endl;
    draw_shape(&oval1);
    draw_shape_ref(circle1);

    std::cout << "=== Calling draw method in a collection of Shape Type ===" << std::endl;
    Shape* shapeCollection[]{&shape1, &oval1, &circle1};
    for (Shape* shape : shapeCollection) {
        shape->draw();
    }
    
    std::cout << "=== Calling overloaded draw methond on Shape Class ===" << std::endl;
    std::cout << "    -- An overload for this does not exist in the derived classes, the base Shape version will always be called" << std::endl;
    shapePtr1->draw(0xFF0000FF);

    std::cout << "=== Calling overloaded draw method on Circle Class ===" << std::endl;
    std::cout << "    -- An overload for this does not exist in the parent classes, you can't use the pointer to call it and it is only available for the Circle" << std::endl;
    circle1.draw(0x0000FFFF, "Blue");

    std::cout << "=== Overrides can also start at different levels in the inheritance chain ===" << std::endl;
    std::cout << "    -- This chain starts from Oval and is only available in Oval and Circle.  Shape does not have this." << std::endl;
    Oval * ovalPtr1 = &oval1;
    ovalPtr1->draw("WhateverOval");

    ovalPtr1 = &circle1;
    ovalPtr1->draw("WhateverCircle");


    std::cout << "=== Static Members behaivor ===" << std::endl;
    std::cout << " -- Triangle override the count static variable and getter method" << std::endl;
    std::cout << " -- Oval and Circle DO NOT override the count static variable and getter method" << std::endl;
    std::cout << "Creating a Triangle" << std::endl;
    Triangle triangle1{20.0, 30.0};
    shapePtr1 = &triangle1;
    shapePtr1->draw();

    std::cout << " Shape will return the count of all shapes including triangle: " << Shape::m_count << std::endl;
    std::cout << " Triangle will return the count of only triangles: " << Triangle::m_count << std::endl;


    return 0;
}