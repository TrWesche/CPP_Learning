#pragma once
#include<utility>
#include<string>
#include<iostream>

class STD_Pair
{
private:
    /* data */

public:
    STD_Pair(/* args */);
    ~STD_Pair();

    void execute();
};

STD_Pair::STD_Pair(/* args */)
{
}

STD_Pair::~STD_Pair()
{
}


void STD_Pair::execute() {
    std::pair<int, std::string> pair_istr1 {100, "Value"};

    std::cout << "Pair Values" << std::endl;
    std::cout << "First: " << pair_istr1.first << std::endl;
    std::cout << "Second: " << pair_istr1.second << std::endl;
}
