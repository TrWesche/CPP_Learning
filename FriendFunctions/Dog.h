#pragma once

#include <iostream>
#include <string>
// #include "Cat.h"

class Dog
{
    private:
        std::string m_name;
        int m_age;

    public:
        Dog(std::string name, int age);
        ~Dog();

        friend void debug_dog_info(const Dog& dog);
        friend class Cat;
};

Dog::Dog(std::string name, int age) {
    m_name = name;
    m_age = age;
};

Dog::~Dog()
{
}


void debug_dog_info(const Dog& dog);