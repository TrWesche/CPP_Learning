#pragma once    

#include "Shape.h"
#include <iostream>
#include <string_view>

class Oval : public Shape
{
protected:
    double m_radius_x{};
    double m_radius_y{};
public:
// Constructor/Destructor
    Oval();
    Oval(std::string_view in_descr, double in_radius_x, double in_radius_y);
    
    // Marking the constructors as virtual is important to make sure memory is not leaked when utilizing the Heap
    //      - For example if delete is called on an Oval shape without the Oval destructor being tagged as virutal
    //          only the Shape destructor will be called releasing only the Shape part of the memory
    virtual ~Oval(); 

// Getter/Setter

// Operator Overloads

// Methods
    // Marked virtual so dynamic binding will work
    // Override provides a check that a method from the base class is being overwritten
    virtual void draw() const override;  


    // You can also start polymorphism at a different level (i.e. The Oval can be the start of a Polymorphism inheritance chain leaving Shape out)
    virtual void draw(std::string_view whatever) const;

    // This method cannot be overwritten from here
    virtual void block_inherited_changes() const override final;

private:
    // This is overriding amethod from Shape which was defined in the public scope and is restricting it to privateS
    virtual void incresingly_restricted_method() const override;

    // IMPORTANT: The default here will be ignored, 100 from the Shape class will be used
    virtual void func_with_defaults(int input = 10);
};

