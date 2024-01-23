#pragma once

#include <string>
#include <iostream>
#include <memory>

class Person
{
private:
    std::string m_name;
    std::weak_ptr<Person> m_friend;

    // std::shared_ptr<Person> m_friend; 
    // If the friend was defined as a shared pointer there is high potential for memory leaks
    //      - Assume to Persons which reference once another Person_A & Person_B
    //              - Person_A has a shared pointer which references Person_B
    //              - Person_B has a shared pointer which references Person_A
    //              - Person_A goes out of scope and its instance of the pointer gets destroyed, however the memory is not released since Person_B still have a reference to that memory
    //              - Person_B goes out of scope and its instance of the pointer gets destroyed, however the memory is not released since the once existing Person_A still has a reference to Person_B
    //              - Person_A & Person_B are abandoned by the program with no reference to the memory in use, the memory is leaked
public:
    Person();
    Person(std::string in_name);
    ~Person();

    void set_friend(std::shared_ptr<Person> in_friend); 
};