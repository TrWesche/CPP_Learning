#include <iostream>
#include "Point.h"
#include "Scores.h"
#include "Vector3.h"
#include "Print.h"


int main(int argc, char **argv){
    std::cout << "=====================================================" << std::endl;
    std::cout << "Running Addition Operation: Non-Member Implementation" << std::endl;
    Point p1(10, 10);
    Point p2(20, 20);
    Point p3{p1 + p2};
    Point p4{p2 + Point(5, 5)};

    p1.print_info();
    p2.print_info();
    p3.print_info();
    p4.print_info();

    (Point(7, 7) + Point(8,8)).print_info();

    std::cout << "=====================================================" << std::endl;
    std::cout << "Running Subtraction Operation: Non-Member Implementation" << std::endl;
    Point p5{p2 - p1};
    p5.print_info();


    std::cout << "=====================================================" << std::endl;
    std::cout << "Running Subscript Operation: Member Implementation (Must be implemented this way)" << std::endl;
    std::cout << "The x value is: " <<  p5[0] << std::endl;
    std::cout << "The y value is: " <<  p5[1] << std::endl;

    std::cout << "Updating the x value" << std::endl;
    p5[0] = 100.1;
    p5.print_info();


    std::cout << "=====================================================" << std::endl;
    std::cout << "Running Subscript Operation: Accesing Values in a Collection" << std::endl;
    Scores s1{"Biology"};

    s1[0] = 88.8;
    s1[4] = 79.5;
    s1.print_info();

    const Scores s2{"Math"};
    std::cout << "Math Score 2: " << s2[2] << std::endl;


    std::cout << "=====================================================" << std::endl;
    std::cout << "Running Steam Insertion Overload Operation: Non-Member Implementation (Typical method for this operator for ease of use)" << std::endl;
    std::cout << p5 << std::endl;


    std::cout << "=====================================================" << std::endl;
    std::cout << "Running Steam Extraction Operation: Non-Member Implementation (Typical method for this operator for ease of use)" << std::endl;
    Point p6{};
    
    // std::cin >> p6; // Works - Commented because it stops program execution and waits for input
    // std::cout << p6 << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "Custom Type Conversion Operation: Must be a memeber function" << std::endl;
    Point p7{99.9, 200.22};
    p7.print_info();

    Vector3 v1{p7};
    v1.print_info();
    std::cout << "Also have the ostream implemented " << v1 << std::endl;

    Vector3 v2{};
    v2 = static_cast<Vector3>(p5);
    std::cout << "The function is also picked up by static casts " << v2 << std::endl;

    std::cout << "=====================================================" << std::endl;
    std::cout << "Unary Prefix Operator Overload ++: As Member" << std::endl;
    std::cout << p7 << std::endl;
    ++p7;
    std::cout << p7 << std::endl;


    std::cout << "=====================================================" << std::endl;
    std::cout << "Unary Prefix Operator Overload --: As Non-Member" << std::endl;
    std::cout << p7 << std::endl;
    --p7;
    std::cout << p7 << std::endl;


    std::cout << "=====================================================" << std::endl;
    std::cout << "Unary Postfix Operator Overload ++: As Member" << std::endl;
    std::cout << p7 << std::endl;
    p7++;
    std::cout << p7 << std::endl;


    std::cout << "=====================================================" << std::endl;
    std::cout << "Unary Postfix Operator Overload --: As Non-Member" << std::endl;
    std::cout << p7 << std::endl;
    p7--;
    std::cout << p7 << std::endl;


    std::cout << "=====================================================" << std::endl;
    std::cout << "Copy Assignment Operator Overload = For Same Class Assignments: As Member (Must be a member)" << std::endl;
    std::cout << "Before Copy Assignment Operator Call" << std::endl;
    
    p4.set_ptr_example(30);
    std::cout << p7 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p4 << std::endl;


    p7 = p5 = p4;

    p4.set_ptr_example(50);
    std::cout << "After Copy Assignment Operator Call" << std::endl; // All values will be assigned the values of p4
    std::cout << p7 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p4 << std::endl;



    std::cout << "=====================================================" << std::endl;
    std::cout << "Copy Assignment Operator Overload = For Cross Class Assignments: As Member (Must be a member)" << std::endl;
    Vector3 v4{};

    std::cout << v4 << std::endl;
    v4 = p4;
    // Priority for the assignments across types
    //  1. Copy assignment Operator
    //  2. Constructor
    //  3. Type conversion operator
    std::cout << v4 << std::endl;

    // When a function is called where a class can be converted the priority is different
    //  1. Constructor
    //  2. Type conversion operator


    std::cout << "=====================================================" << std::endl;
    std::cout << "Functors - I.e. Function Call Operator Overload" << std::endl;

    Print printer;
    printer("Value 1");
    std::cout << printer("Something", "Else") << std::endl;


    return 0;
}