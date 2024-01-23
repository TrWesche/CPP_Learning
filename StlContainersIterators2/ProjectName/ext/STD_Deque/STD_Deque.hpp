#pragma once
#include<deque> 
#include<string>
#include<iostream>


template<typename T>
void print_deque_iterator(const T& collection) {
    auto it = collection.begin();

    std::cout << "[";
    while (it != collection.end()) {
        std::cout << " " << *it;
        it++;
    }
    std::cout << " ]" << std::endl;
}



class STD_Deque
{
private:
    /* data */

public:
    STD_Deque(/* args */);
    ~STD_Deque();

    void execute();
};

STD_Deque::STD_Deque(/* args */)
{
}

STD_Deque::~STD_Deque()
{
}


void STD_Deque::execute() {
    std::deque<int> dq_int1 {4, 5, 6, 7, 8, 9};


    print_deque_iterator(dq_int1);
    std::cout << "Element 5: " << dq_int1[5] << std::endl; // Note: This doesn't do a bound check.  Prefer This & Code for the Out of Bound Case : Do Not Code By Exception.
    std::cout << "Element 4: " << dq_int1.at(4) << std::endl; // This is bound checked & will throw an exception.  Prefer the unbound checked version with an if statement checking the bounds.
    std::cout << "Element Front: " << dq_int1.front() << std::endl;
    std::cout << "Element Back: " << dq_int1.back() << std::endl;

    std::cout << "----------" << std::endl;
    std::cout << "Adding Value 3 to the front of the Deque" << std::endl;
    dq_int1.emplace_front(3);
    print_deque_iterator(dq_int1);
    std::cout << "Element 5: " << dq_int1[5] << std::endl; // Note: This doesn't do a bound check.  Prefer This & Code for the Out of Bound Case : Do Not Code By Exception.
    std::cout << "Element 4: " << dq_int1.at(4) << std::endl; // This is bound checked & will throw an exception.  Prefer the unbound checked version with an if statement checking the bounds.
    std::cout << "Element Front: " << dq_int1.front() << std::endl;
    std::cout << "Element Back: " << dq_int1.back() << std::endl;


    std::cout << "----------" << std::endl;
    std::cout << "Adding Value 10 to the end of the Deque" << std::endl;
    dq_int1.emplace_back(10);
    print_deque_iterator(dq_int1);
    std::cout << "Element 5: " << dq_int1[5] << std::endl; // Note: This doesn't do a bound check.  Prefer This & Code for the Out of Bound Case : Do Not Code By Exception.
    std::cout << "Element 4: " << dq_int1.at(4) << std::endl; // This is bound checked & will throw an exception.  Prefer the unbound checked version with an if statement checking the bounds.
    std::cout << "Element Front: " << dq_int1.front() << std::endl;
    std::cout << "Element Back: " << dq_int1.back() << std::endl;


    std::cout << "----------" << std::endl;
    std::cout << "Emplace Value 333 at index 3 (Function Uses an Iterator as an input)" << std::endl;
    std::deque<int>::iterator it_pos = dq_int1.begin() + 3;
    dq_int1.emplace(it_pos, 333);
    print_deque_iterator(dq_int1);
    std::cout << "Element 5: " << dq_int1[5] << std::endl; // Note: This doesn't do a bound check.  Prefer This & Code for the Out of Bound Case : Do Not Code By Exception.
    std::cout << "Element 4: " << dq_int1.at(4) << std::endl; // This is bound checked & will throw an exception.  Prefer the unbound checked version with an if statement checking the bounds.
    std::cout << "Element Front: " << dq_int1.front() << std::endl;
    std::cout << "Element Back: " << dq_int1.back() << std::endl;


    std::cout << "----------" << std::endl;
    std::cout << "Inserting Value 555 at index 5 (Function Uses an Iterator as an input)" << std::endl;
    it_pos = dq_int1.begin() + 5;
    dq_int1.insert(it_pos, 555);
    print_deque_iterator(dq_int1);
    std::cout << "Element 5: " << dq_int1[5] << std::endl; // Note: This doesn't do a bound check.  Prefer This & Code for the Out of Bound Case : Do Not Code By Exception.
    std::cout << "Element 4: " << dq_int1.at(4) << std::endl; // This is bound checked & will throw an exception.  Prefer the unbound checked version with an if statement checking the bounds.
    std::cout << "Element Front: " << dq_int1.front() << std::endl;
    std::cout << "Element Back: " << dq_int1.back() << std::endl;


        std::cout << "----------" << std::endl;
    std::cout << "Erasing Value at index 4" << std::endl;
    it_pos = dq_int1.begin() + 4;
    dq_int1.erase(it_pos);
    print_deque_iterator(dq_int1);
    std::cout << "Element 5: " << dq_int1[5] << std::endl; // Note: This doesn't do a bound check.  Prefer This & Code for the Out of Bound Case : Do Not Code By Exception.
    std::cout << "Element 4: " << dq_int1.at(4) << std::endl; // This is bound checked & will throw an exception.  Prefer the unbound checked version with an if statement checking the bounds.
    std::cout << "Element Front: " << dq_int1.front() << std::endl;
    std::cout << "Element Back: " << dq_int1.back() << std::endl;
}
