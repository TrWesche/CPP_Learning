#pragma once
#include<list> 
#include<string>
#include<iostream>


template<typename T>
void print_list_iterator(const T& collection) {
    auto it = collection.begin();

    std::cout << "[";
    while (it != collection.end()) {
        std::cout << " " << *it;
        it++;
    }
    std::cout << " ]" << std::endl;
}



class STD_List
{
private:
    /* data */

public:
    STD_List(/* args */);
    ~STD_List();

    void execute();
};

STD_List::STD_List(/* args */)
{
}

STD_List::~STD_List()
{
}


void STD_List::execute() {
    std::list<int> list_int1 {3, 4, 5, 6, 7, 8};

    print_list_iterator(list_int1);
    std::cout << "List Does Not Allow Random Element Access but can be navigated forward & backward (i.e. double linked list)" << std::endl;
    std::cout << "Element Front: " << list_int1.front() << std::endl;
    std::cout << "Element Front: " << list_int1.back() << std::endl;
    
    std::cout << "------------" << std::endl;
    std::cout << "Adding 2 to Front of List" << std::endl;
    list_int1.emplace_front(2);
    print_list_iterator(list_int1);

    std::cout << "------------" << std::endl;
    std::cout << "Adding 9 to End of List" << std::endl;
    list_int1.emplace_back(9);
    print_list_iterator(list_int1);
}
