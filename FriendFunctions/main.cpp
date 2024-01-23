#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "Point.h"

void debug_dog_info(const Dog& dog) {
    std::cout << "Dog name : " << dog.m_name << " dog age : " << dog.m_name << std::endl;
}

double distance(const Point& from, const Point& to){
	return  std::sqrt(pow(to.m_x - from.m_x, 2) + pow(to.m_y - from.m_y, 2) * 1.0);
}


int main(int argc, char **argv){
    Point p1(1,1);
    Point p2(2,2);
    std::cout << "distance : " << distance(p2,p1) << std::endl;


    Cat c1("Juno", 1);
    Dog d1("Bruce", 3);

    c1.tell_me_about_dog(d1);

    return 0;
}