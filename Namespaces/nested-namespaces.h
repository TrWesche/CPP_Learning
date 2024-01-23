#include <iostream>

namespace hello {
    unsigned int age{34};

    namespace world {
        int weight{123};

        void do_something() {
            std::cout << "Age: " << age << std::endl; // Inner namespace has direct access
        }
    }

    void do_something_else() {
        std::cout << "The world var is: " << world::weight << std::endl; // Outer namespace needs to use the namespace to access the variable
    }
}