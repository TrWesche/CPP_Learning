#pragma once
#include <deque>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <iostream>
// #include <functional>
#include "Book.hpp"


template<typename T, typename A>
void print_stack(std::stack<T, A> contents) {
    std::cout << "[";
    while (!contents.empty()) {
        std::cout << " (" << contents.top() << ")";
        contents.pop();
    }
    std::cout << " ]" << std::endl;;
}

template<typename T, typename A>
void clear_stack(std::stack<T, A>& contents) {
    while (!contents.empty()) {
        contents.pop();
    }
}

class STD_Stack
{
private:
    /* data */

public:
    STD_Stack(/* args */);
    ~STD_Stack();

    void execute();
};

STD_Stack::STD_Stack(/* args */)
{
}

STD_Stack::~STD_Stack()
{
}


void STD_Stack::execute() {
    std::cout << "========== Creating Stack from Deque ==========" << std::endl;
    std::cout << " - Note: This is the default allocator so the std::stack doesn't require an allocator type to be passed in" << std::endl;
    std::deque<int> deque_int1 {10, 20, 30, 30, 20, 5, 200};
    std::stack<int> stack_deque {deque_int1};
    std::cout << "Stack Size: " << stack_deque.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the stack)" << std::endl;
    print_stack(stack_deque);
    std::cout << "Stack Size: " << stack_deque.size() << std::endl;
    std::cout << "Emptying Stack" << std::endl;
    clear_stack(stack_deque);
    std::cout << "Stack Size: " << stack_deque.size() << std::endl;


    std::cout << std::endl;
    std::cout << "========== Creating Stack from List ==========" << std::endl;
    std::list<int> list_int1 {10, 20, 30, 30, 20, 5, 200};
    std::stack<int, std::list<int>> stack_list {list_int1};
    std::cout << "Stack Size: " << stack_list.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the stack)" << std::endl;
    print_stack(stack_list);
    std::cout << "Stack Size: " << stack_list.size() << std::endl;


    std::cout << std::endl;
    std::cout << "========== Creating Stack from Vector ==========" << std::endl;
    std::vector<int> vector_int1 {10, 20, 30, 30, 20, 5, 200};
    std::stack<int, std::vector<int>> stack_vector {vector_int1};
    std::cout << "Stack Size: " << stack_vector.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the stack)" << std::endl;
    print_stack(stack_vector);
    std::cout << "Stack Size: " << stack_vector.size() << std::endl;


    std::cout << std::endl;
    std::cout << "- Note: Examples use an initialized deque/list, this is not necessary" << std::endl;
    std::stack<int> stack_deque2;
    stack_deque2.push(100);
    stack_deque2.emplace(200);
    print_stack(stack_deque2);
}
