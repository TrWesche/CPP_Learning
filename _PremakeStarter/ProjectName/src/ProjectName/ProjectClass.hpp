#pragma once
#include <iostream>
#include <memory>

namespace TW {

class ProjectClass
{
public:
    // Contructor/Destructor
    ProjectClass(); 
    ProjectClass(size_t sample); 
    ~ProjectClass();

    size_t get_m_sample() const {
        return m_sample;
    }

protected:
    size_t m_sample {}; 

private:
};


}
