#include <iostream>
#include "Player.h"
#include "GameSession.h"

int main(int argc, char **argv){
    // Build Player with Default Constructor
    Player plyr1("Encounters", "Falcon");
    std::cout << plyr1 << std::endl;

    // Build Player with Custom Constructor
    Player plyr2("Firelands", "Bimp", "Edward", "Standard");
    std::cout << plyr2 << std::endl;

    // Example for the using keyword (Note: The using keyword does not work for private variables)
    plyr2.m_first_name = "NewFirstName"; 
    std::cout << plyr2 << std::endl;

    // Build Game Session showing Multiple Levels of Inheritance
    GameSession gs1("Freddy", "Session", "FNAF", "PunchingBag", 2, 4);
    std::cout << gs1 << std::endl;

    // Copy Game Session showing Copy Constructors
    GameSession gs2(gs1);
    std::cout << gs2 << std::endl;

    // You can access public members of classes by using the Scope Resolution Operator
    std::cout << gs2.print_something() << std::endl;
    std::cout << gs2.Player::print_something() << std::endl;

    return 0;
}