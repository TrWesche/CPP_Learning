#include <iostream>
#include "Cylinder.h"
#include "Point.h"
#include "Box.h"
#include "Dog.h"
#include "ExStructBinding.h"

void dog_func1(Dog dog) {
    dog.set_name("NewName");
    dog.print_about();
}

void dog_func2(Dog& dog) {
    dog.set_name("NewName");
    dog.print_about();
}

void dog_func3(const Dog& dog) {
    dog.print_about();
}

void dog_func4(Dog* dog) {
    dog->set_name("NewName");
    dog->print_about();
}

void dog_func5(const Dog* dog) {
    dog->print_about();
}


int main(int argc, char **argv){
    Cylinder cylinder1;
    std::cout << cylinder1.volume() << std::endl;

    Cylinder cylinder2 = Cylinder(2.0, 2.0);;
    std::cout << cylinder2.volume() << std::endl;


    Point p1;
    Point p2(2, 2);
    std::cout << p1.distance_to(p2) << std::endl;


    Point p3(21.2, 4.2);
    p3.print_point(p3);


    // To use the heap you need to access your classes using pointers
    Cylinder* cylinder3 = new Cylinder(100.1, 20.2);

    // The acessors below are functionaly equivalent the arrow is a nicer syntax
    std::cout << "volume c3 = " << (*cylinder3).volume() << std::endl;
    std::cout << "volume c3 = " << cylinder3->volume() << std::endl;
    delete cylinder3;


    // Example of Chaining Pointers
    Box* box1 = new Box();
    box1->set_x(10.0)->set_y(5.0)->set_z(2.0);
    std::cout << "box volume b1 = " << box1->volume() << std::endl;
    delete box1;

    // Example of Chaining References
    Point* p4 = new Point();
    p4->set_x(5).set_y(10);
    p4->print_point(*p4);
    delete p4;

    // Using Const with Classes
    const Dog* dog1 = new Dog("Fred", "Husky", 95.5, 4, 2);
    dog1->print_about(); // This uses the const version of print_about
    std::cout << "Dog 1's Age: " << dog1->get_age() << std::endl;

    Dog* dog2 = new Dog("Bobby", "Shepard", 78.2, 4, 3);
    dog2->print_about(); // This uses the non const version of print_about

    delete dog1;
    delete dog2;


    ExStructBinding exStB1 {1.1, 2.2};
    auto [a, b] = exStB1; // Copies value of x to a, and value of y to b

    return 0;   
}