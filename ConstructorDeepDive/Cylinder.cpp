#include "Cylinder.h"

// Constructor/Destructor

// Member Wise Assignment Initialization
// About:
//      - Creation Happens in 2 Steps: Object Creation, Value Population
// Cylinder::Cylinder(double in_radius, double in_height) {
//     radius = in_radius;
//     height = in_height;
// }
    
// Initializer List Initialization
// About:
//      - Creation Happens in 1 Step: Object Creation & Value Population Simultaneous
// Benefits:
//      - Avoids Unecessary Copies
//      - In some cases they are the only way you can initialize
Cylinder::Cylinder(double in_radius, double in_height) :
    radius(in_radius), height(in_height) {};

// Getter/Setter
const double& Cylinder::get_radius() const {
    return this->radius;
}

const double& Cylinder::get_height() const {
    return this->height;
}

Cylinder* Cylinder::set_radius(double in_radius) {
    radius = in_radius;
    return this;
}

Cylinder* Cylinder::set_height(double in_height) {
    height = in_height;
    return this;
}

double Cylinder::get_volume() const {
    return std::numbers::pi * radius * radius * height;
}


double Cylinder::get_area() const {
    return 2 * std::numbers::pi * radius * (radius + height);
}
