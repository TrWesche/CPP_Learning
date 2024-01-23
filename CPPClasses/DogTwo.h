#include <string>
#include <iostream>

// For Getter/Setter Pattern
// Does not seem like it supports splitting up the class between two files

class DogTwo {
    private:
        std::string name;
        std::string breed;
        double weight;
        int qty_legs;
        int age;

    public:
        // Contructors
        DogTwo() {
            this->name = "Not Named";
            this->breed = "Unknown";
            this->weight = 0.0;
            this->qty_legs = 4;
            this->age = 0;
        };
        DogTwo(const std::string& name, const std::string& breed, double weight, int qty_legs, int age){
            this->name = name;
            this->breed = breed;
            this->weight = weight;
            this->qty_legs = qty_legs;
            this->age = age;
        };
            
        // Getter/Setters
        std::string& name() {
            return this->name;
        };
        const std::string& name() const {
            return this->name;
        };
        std::string& breed() {
            return this->breed;
        };
        const std::string& breed() const {
            return this->breed;
        };
        double& weight() {
            return this->weight;
        }
        const double& weight() const {
            return this->weight;
        }
        int& qty_legs() {
            return this->qty_legs;
        }
        const int& qty_legs() const {
            return this->qty_legs;
        }
        int& age() {
            return this->age;
        }
        const int& age() const {
            return this->age;
        }

        // Methods
        void print_about() {
            age++;
            std::cout << name << " is a " << age << " year old " << breed 
                <<  " who weighs " << weight << " lb(s) "
                << " with " << qty_legs << " legs." << std::endl;
        }
        void print_about() const {
            std::cout << name << " is a " << age << " year old " << breed 
                <<  " who weighs " << weight << " lb(s) "
                << " with " << qty_legs << " legs." << std::endl;
        }
};