#pragma once

#include <iostream>
#include <string>
#include <cassert>

class Scores
{
public:
// Constructor/Destructor
    Scores() = delete;
    Scores(const std::string& course_name);
    ~Scores();

// Member Operator Overload
    // Subscript (Can only be a member function) - Binary Opeartor
    double& operator[] (size_t index);
    const double& operator[] (size_t index) const;

// Methods
    void print_info();

private:
// Member Variables
    std::string m_course_name;
    double m_scores[20]{};
};

