#pragma once
#include <deque>
#include <list>
#include <queue>
#include <string>
#include <iostream>


template<typename T, typename A>
void print_queue(std::queue<T, A> contents) {
    std::cout << "[";
    while (!contents.empty()) {
        std::cout << " (" << contents.front() << ")";
        contents.pop();
    }
    std::cout << " ]" << std::endl;;
}

template<typename T, typename A>
void clear_queue(std::queue<T, A>& contents) {
    while (!contents.empty()) {
        contents.pop();
    }
}

class STD_Queue 
{
private:
    /* data */

public:
    STD_Queue(/* args */);
    ~STD_Queue();

    void execute();
};

STD_Queue::STD_Queue(/* args */)
{
}

STD_Queue::~STD_Queue()
{
}


void STD_Queue::execute() {
    std::cout << "========== Creating Queue from Deque ==========" << std::endl;
    std::cout << " - Note: This is the default allocator so the std::stack doesn't require an allocator type to be passed in" << std::endl;
    std::deque<int> deque_int1 {10, 20, 30, 30, 20, 5, 200};
    std::queue<int> queue_deque {deque_int1};
    std::cout << "Queue Size: " << queue_deque.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the stack)" << std::endl;
    print_queue(queue_deque);
    std::cout << "Stack Size: " << queue_deque.size() << std::endl;
    std::cout << "Emptying Stack" << std::endl;
    clear_queue(queue_deque);
    std::cout << "Stack Size: " << queue_deque.size() << std::endl;


    std::cout << std::endl;
    std::cout << "========== Creating Queue from List ==========" << std::endl;
    std::list<int> list_int1 {10, 20, 30, 30, 20, 5, 200};
    std::queue<int, std::list<int>> queue_list {list_int1};
    std::cout << "Stack Size: " << queue_list.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the stack)" << std::endl;
    print_queue(queue_list);
    std::cout << "Stack Size: " << queue_list.size() << std::endl;


    std::cout << std::endl;
    std::cout << "- Note: Examples use an initialized deque/list, this is not necessary" << std::endl;
    std::queue<int> queue_deque2;
    queue_deque2.push(100);
    queue_deque2.emplace(200);
    print_queue(queue_deque2);
}
