#pragma once


#include <iostream>
#include <string>
#include <memory>



class ShrdPtr
{
private:
    std::string m_name;
public:
    ShrdPtr();
    ShrdPtr(std::string in_name);
    ~ShrdPtr();

    void print_info() const;

    void set_name(std::string in_name);
};

