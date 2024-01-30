// CPP20_Modules_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm> // Depending on compiler support import might work

import <iostream>;
import Line;
//import SubModuleTop; // Brings in both SubModule.A and SubModule.B definitions.  Could be a usedful way for organizing code, letting users only bring in certain parts.
import SubModule.A; 
import ModulePartitions; // A paritioned module allows you to break up a module into smaller components, while keeping the sub-module structure hidden.  Users cannot only bring in certain parts.
import BoxContainer;

int main()
{
    Point p1{ 10.1, 20.2 };
    Point p2{ 33.2, 12.5 };

    Line line{ p1, p2 };

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << line << std::endl;


    std::cout << sm_add(23, 245) << std::endl;

    std::cout << mp_sub(245, 23) << std::endl;


    BoxContainer<int> box1;
    box1.add(5);
    box1.add(1);
    box1.add(4);
    box1.add(8);
    box1.add(5);
    box1.add(3);
    box1.add(7);
    box1.add(9);
    box1.add(6);

    std::cout << "box1 : " << box1 << std::endl;
    std::ranges::sort(box1.begin(), box1.end());
    std::cout << "box1 : " << box1 << std::endl;
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
