// This is an include guard which protects from redefinition of variables
#ifndef CONSTANTS_H
#define CONSTANTS_H
    #include "constants.h"
#endif

#include "Box.h"
#include <iostream>

// Constructors
Box::Box() {
    this->m_x = 1.0;
    this->m_y = 1.0;
    this->m_z = 1.0;
    this->heap_variable = new double;
    *(this->heap_variable) = 100.0;
    std::cout << "Box Created at " << this << std::endl;
}

Box::Box(double x, double y, double z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
    this->heap_variable = new double;
    *(this->heap_variable) = 100.0;
    std::cout << "Box Created at " << this << std::endl;
}


// Destructor - Gets Called in the following situations
//      - When an object is passed by value to a function and that copied object goes out of scope
//      - When a local object is returned from a function (A copy of the object will be created in the higher level scope and the lower level object will be destroyed)
//      - When a local stack object goes out of scope
//      - When a heap object is released with delete
//  Behavior When Destroyed
//      - Destructors will be called in the reverse order of their construction (if not tiggered in a different way)
Box::~Box(){
    delete this->heap_variable;
    std::cout << "Box Destroyed at " << this << std::endl;
}

// Setters
Box* Box::set_x(double x){
    this->m_x = x;
    return this;
}

Box* Box::set_y(double y) {
    this->m_y = y;
    return this;
}

Box* Box::set_z(double z) {
    this->m_z = z;
    return this;
}

// Getters
double Box::get_x() {
    return m_x;
}

double Box::get_y() {
    return m_y;
}

double Box::get_z() {
    return m_z;
}


// Methods
double Box::volume() {
    return this->m_x * this->m_y * this->m_z;
}

