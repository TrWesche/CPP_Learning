#pragma once

#include <iostream>
#include <string_view>


class Shape
{
protected:
    std::string m_descr{"NONE"};
    int m_rgba{0x000000FF};
public:
// Constructor/Destructor
    Shape();
    Shape(std::string_view descr);
    Shape(std::string_view descr, int rgba);
    virtual ~Shape();

// Getter/Setter

// Operator Overloads

// Methods
    virtual void draw() const; // Marked virtual so dynamic binding will work
    virtual void draw(int rgba) const;

    // Oval implements this with the final annotation which blocks further downstream overrides
    virtual void block_inherited_changes() const;

// Statics
    static int m_count;

    virtual int get_count() const;

    // This method will be overwritten private in the Oval class
    virtual void incresingly_restricted_method() const;

    // The default arguments from here will be used no matter where the shapes are in the inheritance list.
    virtual void func_with_defaults(int input = 100);
};

