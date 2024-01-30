// CPP20_Modules_L01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import <iostream>;
import math_module;
import modNumTwo;
import modNumThree;
import modNumFour;

int main()
{
    //std::cout << "Hello World!\n";
    do_something();

    long sum_longs = add_two(20L, 30L);
    std::cout << "Summed 2 Long values of 20, 30: " << sum_longs << std::endl;

    double sum_doubles = add_two(11.1, 56.2);
    std::cout << "Summed 2 Double Values of 11.1, 56.2: " << sum_doubles << std::endl;

    greet("Jimmey");

    print_name_length("Simulation");

    Point point1(100.1, 200.2);
    std::cout << "Created Point from modNumTwo (All in ixx): " << point1 << std::endl;

    Pointv3 point3(333.3, 444.4);
    std::cout << "Created Point from modNumThree (1 ixx, 1 implementation): " << point3 << std::endl;

    Pointv4 point4(444.4, 555.5);
    std::cout << "Created Point from modNumFour (1 ixx, 2 implementation): " << point4 << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
