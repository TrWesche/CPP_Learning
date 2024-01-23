#include "Person.h"

Person::Person() : m_name{"Unknown"} {}

Person::Person(std::string in_name) : m_name(in_name) {};

Person::~Person() {}

void Person::set_friend(std::shared_ptr<Person> in_friend) {
    m_friend = in_friend;
}