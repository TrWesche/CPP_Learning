#include "ShrdPtr.h"

ShrdPtr::ShrdPtr() : m_name("Default") {};

ShrdPtr::ShrdPtr(std::string in_name) : 
    m_name(in_name)
{
}

ShrdPtr::~ShrdPtr()
{
}

void ShrdPtr::print_info() const {
    std::cout << "This shared pointer has a name of " << m_name << std::endl;
}

void ShrdPtr::set_name(std::string in_name) {
    m_name = in_name;
}