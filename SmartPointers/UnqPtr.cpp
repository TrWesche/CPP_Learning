#include "UnqPtr.h"


UnqPtr::UnqPtr() {
    m_name = {"Default"};
}

UnqPtr::UnqPtr(std::string in_name) : 
    m_name(in_name)
{
}

UnqPtr::~UnqPtr()
{
}

void UnqPtr::print_info() const {
    std::cout << "This unique pointer has a name of " << m_name << std::endl;
}

void UnqPtr::set_name(std::string in_name) {
    m_name = in_name;
}