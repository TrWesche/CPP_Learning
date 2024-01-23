#include <numbers>

class Cylinder {
    private :
        double base_radius;
        double height;

    public : 
        Cylinder () {
            base_radius = 1.0;
            height = 1.0;
        }

        Cylinder (double base_radius, double height) {
            this->base_radius = base_radius;
            this->height = height;
        }

        double area () {
            return std::numbers::pi * base_radius * base_radius;
        }

        double volume() {
            return area() * height;
        }
};