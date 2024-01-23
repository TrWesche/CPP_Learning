#include "Person.h"


Person::Person() :
    m_first_name("New"), m_last_name("Person")
{
}


Person::Person(std::string_view in_first_name, std::string_view in_last_name) :
    m_first_name(in_first_name), m_last_name(in_last_name)
{    
} 

Person::Person(const Person& src) :
    m_first_name{src.m_first_name},
    m_last_name{src.m_last_name}
{
}


Person::~Person()
{
}

std::ostream& operator << (std::ostream& os, const Person& a) {
    os << a.m_first_name << " " << a.m_last_name;
    return os;
}


const std::string& Person::get_first_name() const
{   
    return m_first_name;
}

const std::string& Person::get_last_name() const
{
    return m_last_name;
}