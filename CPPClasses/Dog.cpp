#include "Dog.h"

Dog::Dog() {
    this->name = "Not Named";
    this->breed = "Unknown";
    this->weight = 0.0;
    this->qty_legs = 4;
    this->age = 0;
};

Dog::Dog(const std::string& name, const std::string& breed, double weight, int qty_legs, int age){
    this->name = name;
    this->breed = breed;
    this->weight = weight;
    this->qty_legs = qty_legs;
    this->age = age;
};

// Getters
const std::string& Dog::get_name() const {
    return this->name;
}

const std::string& Dog::get_breed() const {
    return this->breed;
}

const double& Dog::get_weight() const {
    return this->weight;
}

const int& Dog::get_qty_legs() const {
    return this->qty_legs;
}

const int& Dog::get_age() const {
    return this->age;
}

// Setters
Dog& Dog::set_name(const std::string& name) {
    this->name = name;
    return *this;
};

Dog& Dog::set_breed(const std::string& breed) {
    this->breed = breed;
    return *this;
};

Dog& Dog::set_weight(double weight) {
    this->weight = weight;
    return *this;
};

Dog& Dog::set_qty_legs(int qty_legs) {
    this->qty_legs = qty_legs;
    return *this;
};

Dog& Dog::set_age(int age) {
    this->age = age;
    return *this;
};


// Methods
void Dog::print_about() const {
    call_count++; // This variable is marked as mutable which allows it to be modified even when the method is marked as const
    std::cout << name << " is a " << age << " year old " << breed 
                <<  " who weighs " << weight << " lb(s) "
                << " with " << qty_legs << " legs." << std::endl;
}

void Dog::print_about() {
    call_count++;
    age++;
    std::cout << name << " is a " << age << " year old " << breed 
        <<  " who weighs " << weight << " lb(s) "
        << " with " << qty_legs << " legs." << std::endl;
}
