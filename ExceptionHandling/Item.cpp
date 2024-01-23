#include "Item.h"
#include <iostream>


Item::Item(/* args */)
{
    std::cout << "Item Constructor Called" << std::endl;
}

Item::~Item()
{
    std::cout << "Item Destructor Called" << std::endl;
}
