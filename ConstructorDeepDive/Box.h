#include <string>
#include <iostream>

class Box
{
    private:
        double height {0};
        double width {0};
        double depth {0};
        std::string color {"Black"};
        

    public:
        Box() = default;
        Box(double in_side);
        Box(double in_height, double in_width, double in_depth);
        Box(double in_height, double in_width, double in_depth, std::string in_color);
        ~Box();

    public:
        void print_info();
};



Box::Box(double in_height, double in_width, double in_depth, std::string in_color) :
    height{in_height}, width{in_width}, depth{in_depth}, color{in_color}
{
}

Box::Box(double in_height, double in_width, double in_depth) : Box(in_height, in_width, in_depth, "Blue") 
{
}

Box::Box(double in_side) : Box(in_side, in_side, in_side, "Pink") 
{
    color = "Brown";
}


Box::~Box()
{
}


void Box::print_info() {
    std::cout << "The box is: " << height << " x " << width << " x " << depth << " and is " << color << std::endl;
}