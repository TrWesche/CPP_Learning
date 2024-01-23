#if !defined(UNQPTR_H)
#define UNQPTR_H

#include <iostream>
#include <string>
#include <memory>

class UnqPtr
{
private:
    std::string m_name;
public:
    UnqPtr();
    UnqPtr(std::string in_name);
    ~UnqPtr();

    void print_info() const;

    void set_name(std::string in_name);
};





#endif // UNQPTR_H
