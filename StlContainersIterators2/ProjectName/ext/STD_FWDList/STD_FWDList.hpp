#pragma once
#include<forward_list> 
#include<string>
#include<iostream>


template<typename T>
void print_fwl_iterator(const T& collection) {
    auto it = collection.begin();

    std::cout << "[";
    while (it != collection.end()) {
        std::cout << " " << *it;
        it++;
    }
    std::cout << " ]" << std::endl;
}



class STD_FWDList
{
private:
    /* data */

public:
    STD_FWDList(/* args */);
    ~STD_FWDList();

    void execute();
};

STD_FWDList::STD_FWDList(/* args */)
{
}

STD_FWDList::~STD_FWDList()
{
}


void STD_FWDList::execute() {
    std::forward_list<int> fwl_int1 {3, 4, 5, 6, 7, 8};

    print_fwl_iterator(fwl_int1);
    std::cout << "Forward List Does Not Allow Random Element Access or Access to End" << std::endl;
    std::cout << "Element Front: " << fwl_int1.front() << std::endl;
    
    std::cout << "------------" << std::endl;
    std::cout << "Adding 2 to Front of List" << std::endl;
    fwl_int1.emplace_front(2);
    print_fwl_iterator(fwl_int1);


    std::cout << "------------" << std::endl;
    std::cout << "Erasing 1 Element After Collection Element 2 - Uses Iterator For Starting Position" << std::endl;
    std::cout << "    - Note: Since this is a linked list the iterator cannot jump to a point and instead needs to loop through the element pointers" << std::endl;
    std::forward_list<int>::iterator fwl_itr1 = fwl_int1.begin();
    for (size_t i{}; i < 2; i++) {
        fwl_itr1++;
    }
    fwl_int1.erase_after(fwl_itr1);
    print_fwl_iterator(fwl_int1);


    std::cout << "------------" << std::endl;
    std::cout << "Adding 1000 After Collection Element 3 - Uses Iterator For Starting Position" << std::endl;
    std::cout << "    - Note: Since this is a linked list the iterator cannot jump to a point and instead needs to loop through the element pointers" << std::endl;
    fwl_itr1 = fwl_int1.begin();
    for (size_t i{}; i < 3; i++) {
        fwl_itr1++;
    }
    fwl_int1.emplace_after(fwl_itr1, 1000);
    print_fwl_iterator(fwl_int1);


    std::cout << "------------" << std::endl;
    std::cout << "Erasing 1 Element After 1000" << std::endl;
    std::cout << "    - Note: If you know the element you are looking for you can use std::find to find the iterator location" << std::endl;
    fwl_itr1 = std::find(fwl_int1.begin(), fwl_int1.end(), 1000);
    if(fwl_itr1 != fwl_int1.end()) {
        fwl_int1.erase_after(fwl_itr1);
    }
    else {
        std::cout << "Unable to find 1000" << std::endl;
    }
    print_fwl_iterator(fwl_int1);

}
