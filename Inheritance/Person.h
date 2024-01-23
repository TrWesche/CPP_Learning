#pragma once
#include <string>
#include <iostream>
#include <compare>

class Person
{
friend std::ostream& operator << (std::ostream& os, const Person& a);

public:
    // Constructor/Destructor
    Person();
    Person(std::string_view in_first_name, std::string_view in_last_name);
    Person(const Person& src); // Copy Constructor

    ~Person();

    // Getter/Setter
    const std::string& get_first_name() const;
    const std::string& get_last_name() const;

protected:
    std::string m_first_name;
    std::string m_last_name;    
};
