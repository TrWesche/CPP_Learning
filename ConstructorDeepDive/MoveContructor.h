#include <iostream>

class MoveConstructor {
    private:
        double* x {};
        double* y {};

        void invalidate() {
            x = nullptr;
            y = nullptr;
        }
    
    public:
        //Disabling Constructors - The lines of code below would disable the
        // MoveConstructor() = delete; // Default Constructor
        // MoveConstructor(const MoveConstructor& sourceMC) = delete; // Default Copy Constructor
        // MoveConstructor(MoveConstructor&& sourceMC) = delete; // Default Move Constructor



        //Standard Constructors
        MoveConstructor() = default;
        MoveConstructor(double in_x, double in_y) :
             x(new double(in_x)), y(new double(in_y))
            {};

        //Copy Constructor
        MoveConstructor(const MoveConstructor& sourceMC) :
            x(new double(*(sourceMC.get_x()))), y(new double(*(sourceMC.get_y()))) 
            {
                std::cout << "Executing Copy" << std::endl;
            };

        // Move Constructor
        MoveConstructor(MoveConstructor&& sourceMC) 
            : x(sourceMC.get_x()), y(sourceMC.get_y()) 
            {
                std::cout << "Executing Move" << std::endl;
                sourceMC.invalidate();
            };
            
        // Destructor
        ~MoveConstructor() {
            delete x;
            delete y;
        }

    public:
        double* get_x() const {
            return x;
        }

        double* get_y() const {
            return y;
        }

        MoveConstructor* set_x(double in_x) {
            *x = in_x;
            return this;
        }
    
        MoveConstructor* set_y(double in_y) {
            *y = in_y;
            return this;
        }

        void print_info() const {
            std::cout << "Move Contructor [x : " << *x << ", y : " << *y << "]" << std::endl;
        }
};


// Note: There is a standard implementation
//          - MoveConstructor mc1(std::move(MoveConstructor(1.0, 2.0)))