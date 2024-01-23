#pragma once
#include "Oval.h"
#include <iostream>
#include <string_view>

class Circle : public Oval
{
private:
    /* data */
public:
// Constructor/Destructor
    Circle();
    Circle(std::string_view in_descr, double in_radius);
    virtual ~Circle();

// Getter/Setter

// Operator Overloads

// Methods
    // Marked virtual so dynamic binding will work
    // Override provides a check that a method from the base class is being overwritten
    virtual void draw() const override;  

    // This is only valid starting from there
    virtual void draw(int rgba, std::string_view color) const;

    // This is polymorphic with Oval, not with Shape
    virtual void draw(std::string_view whatever) const override;
};

