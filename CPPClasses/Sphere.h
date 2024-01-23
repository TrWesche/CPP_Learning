#include <numbers>

class Sphere {
    private :
        // Member Variables
        double radius {1};

    public : 
        // Constructors
        Sphere () = default;

        Sphere (double radius) {
            this->radius = radius;
        }

        // Getters
        double get_radius() {
            return this->radius;
        }

        double set_radius(double radius) {
            this->radius = radius;
        }

        // Methods
        double volume() {
            return (4/3) * std::numbers::pi * radius * radius;
        }
};