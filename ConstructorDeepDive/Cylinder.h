#include <numbers>

class Cylinder {
    // Member Variables
    private:
        double radius {1};
        double height {1};

    // Constructor/Destructor
    public:
        Cylinder() = default;
        Cylinder(double in_radius, double in_height = 10.0);
        // Cylinder(double in_radius = 5.0, double in_height = 10.0); -- Invalid with a default constructor
    
    // Getter/Setter
    public:
        const double& get_radius() const;
        const double& get_height() const;

        Cylinder* set_radius(double in_radius);
        Cylinder* set_height(double in_height);

    // Methods
    public:
        double get_volume() const;
        double get_area() const;
};