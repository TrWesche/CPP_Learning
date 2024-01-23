#pragma once

#include <iostream>
#include <string>
#include "Dog.h"

class Cat
{
    private:
        std::string m_name;
        int m_age;
    
    public:
        Cat(std::string name, int age);
        ~Cat();

    public:
        void tell_me_about_dog(const Dog& dog) const;
};

Cat::Cat(std::string name, int age) {
    m_name = name;
    m_age = age;
};

Cat::~Cat()
{
}


void Cat::tell_me_about_dog(const Dog& dog) const 
{
    std::cout << "The dog " << dog.m_name << " is my friend." << std::endl;
}