#include <string>
#include <iostream>

class Dog {
    private:
        std::string name;
        std::string breed;
        double weight;
        int qty_legs;
        int age;
        mutable size_t call_count {};

    public:
        // Contructors
        Dog();
        Dog(const std::string& name, const std::string& breed, double weight, int qty_legs, int age);
    
        // Getters
        const std::string& get_name() const;
        const std::string& get_breed() const;
        const double& get_weight() const;
        const int& get_qty_legs() const;
        const int& get_age() const;

        // Setters
        Dog& set_name(const std::string& name);
        Dog& set_breed(const std::string& breed);
        Dog& set_weight(double weight);
        Dog& set_qty_legs(int qty_legs);
        Dog& set_age(int age);

        // Methods
        void print_about() const;
        void print_about();
};