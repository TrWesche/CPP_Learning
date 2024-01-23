#include <iostream>
#include "Cylinder.h"
#include "Box.h"
#include "CopyConstructor.h"
#include "MoveContructor.h"
#include "Reverser.h"
#include "DesignatedInit.h"


int main(int argc, char **argv){
    Cylinder* c1 = new Cylinder(100.0, 200.0);

    std::cout << c1->get_volume() << std::endl;

    delete c1;
    c1 = nullptr;


    Box* b1 = new Box(10.0);
    b1->print_info();

    Box* b2 = new Box(5, 4, 3);
    b2->print_info();

    delete b1;
    delete b2;


    CopyConstructor* cc1 = new CopyConstructor("String 1A", "String 1B", 100);
    CopyConstructor* cc2 = new CopyConstructor(*cc1);

    std::string temp_str {"Updated Str1 Val"};

    cc2->set_str_val1(temp_str);
    cc2->set_num_val1(1);

    cc1->print_about();
    cc2->print_about();

    delete cc1;
    delete cc2;



    MoveConstructor* mc1 = new MoveConstructor(1.0, 2.0);
    mc1->print_info();

    MoveConstructor mc2(std::move(MoveConstructor(3.3, 4.5)));
    mc2.print_info();



    // Initializer List Contructor
    Reverser rvsr1{1, 2, 3, 4, 5};
    rvsr1.print();



    // Designated List Consructor - New for CPP 20, allows you to skip initilizing variables, but they still must be in order
    DesignatedInit di1 {.x = 10, .y = 20, .z = 30};
    DesignatedInit di2 {.x = 5, .z = 50};
    DesignatedInit di3 {.y = 8, .z = 40};



    return 0;
}