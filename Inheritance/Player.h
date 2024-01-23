#pragma once
#include <string>
#include <string_view>
#include <iostream>
#include "Person.h"


// class Person;

// Inheritance Levels (public Person / protected Person / private Person)
//  - public: The privacy levels from the class being inherited are retained
//  - protected: The privacy levels from the class being inherited are collapsed to protected/private
//  - private: The privacy levels from the class being inherited are collapsed to private

// Changing Protection Levels in Derived Classes
//  - Utilizes the using keyword

// Constructor Behavior
//  - Unless otherwise specified the Default constructor will be called to build the lower level components of a class
//      on the way to creating the called for class.  I.e. For Player the Person Constructor will be called before the 
//      constructor for the Player is called.
//  - To use a custom constructor you can call it from the initializer list as shown as examples in the classes implemented in this project

// Inheriting Base Constructor
//  - It is possible to tell a class to use the base constructor for building itself with the using keyword
//      (using Person::Person).  This will cause a new Player Class to be built where only the components of Person
//      are initialized during construction.  Not recommended to use.

class Player : public Person
{
friend std::ostream& operator << (std::ostream& os, const Player& a);

public:
    // using Person::Person; // Inheriting the Person constructor.  Not recommended in practice.
    Player();
    Player(std::string_view in_game, std::string_view in_char_name);
    Player(std::string_view in_game, std::string_view in_char_name, std::string_view in_first_name, std::string_view in_last_name);
    Player(const Player& src); // Copy Constructor
    ~Player();

    using Person::m_first_name; // This will pull the first name from Person from protected to public when used from the Player class

    std::string_view print_something() {
        return "Player Printing Something";
    }

protected:
    std::string m_game{"None"};
    std::string m_char_name{"New Player"};
};

