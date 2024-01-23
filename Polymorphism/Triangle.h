#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
    double m_height{};
    double m_width{};
public:
// Constructor/Destructor
    Triangle();
    Triangle(double height, double width);
    ~Triangle();

// Getter/Setter

// Operator Overloads

// Methods
    // Marked virtual so dynamic binding will work
    // Override provides a check that a method from the base class is being overwritten
    virtual void draw() const override;  

// Statics
    static int m_count;

    virtual int get_count() const override;
};

