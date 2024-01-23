#pragma once
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <iostream>


template<typename T, typename Container, typename Comparator>
void print_priority_queue(std::priority_queue<T, Container, Comparator> contents) {
    std::cout << "[";
    while (!contents.empty()) {
        std::cout << " (" << contents.top() << ")";
        contents.pop();
    }
    std::cout << " ]" << std::endl;;
}

template<typename T, typename Container, typename Comparator>
void clear_priority_queue(std::priority_queue<T, Container, Comparator>& contents) {
    while (!contents.empty()) {
        contents.pop();
    }
}

class STD_PriorityQueue 
{
private:
    /* data */

public:
    STD_PriorityQueue(/* args */);
    ~STD_PriorityQueue();

    void execute();
};

STD_PriorityQueue::STD_PriorityQueue(/* args */)
{
}

STD_PriorityQueue::~STD_PriorityQueue()
{
}


void STD_PriorityQueue::execute() {
    std::cout << "========== Creating Priority Queue from Deque which Prioritizes Greatest ==========" << std::endl;
    std::deque<int> deque_int1 {10, 20, 30, 30, 20, 5, 200};
    std::priority_queue<int, std::deque<int>, std::greater<int>> queue_deque_gtr{deque_int1.begin(), deque_int1.end()};
    std::cout << "Queue Size: " << queue_deque_gtr.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the priority queue, the only way to navigate is through pop)" << std::endl;
    print_priority_queue(queue_deque_gtr);
    std::cout << "Queue Size: " << queue_deque_gtr.size() << std::endl;
    std::cout << "Emptying Queue" << std::endl;
    clear_priority_queue(queue_deque_gtr);
    std::cout << "Queue Size: " << queue_deque_gtr.size() << std::endl;


    std::cout << "========== Creating Priority Queue from Deque which Prioritizes Least ==========" << std::endl;
    std::deque<int> deque_int2 {10, 20, 30, 30, 20, 5, 200};
    std::priority_queue<int, std::deque<int>, std::less<int>> queue_deque_lt{deque_int2.begin(), deque_int2.end()};
    std::cout << "Queue Size: " << queue_deque_lt.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the priority queue, the only way to navigate is through pop)" << std::endl;
    print_priority_queue(queue_deque_lt);
    std::cout << "Queue Size: " << queue_deque_lt.size() << std::endl;
    std::cout << "Emptying Queue" << std::endl;
    clear_priority_queue(queue_deque_lt);
    std::cout << "Queue Size: " << queue_deque_lt.size() << std::endl;


    std::cout << std::endl;
    std::cout << "========== Creating Priority Queue from Vector ==========" << std::endl;
    std::vector<int> vector_int1 {10, 20, 30, 30, 20, 5, 200};
    std::priority_queue<int, std::vector<int>> queue_vector {vector_int1.begin(), vector_int1.end()};
    std::cout << "Queue Size: " << queue_vector.size() << std::endl;
    std::cout << "Printing Contents (Note: This passes a copy because there are no iterators available on the priority queue, the only way to navigate is through pop)" << std::endl;
    print_priority_queue(queue_vector);
    std::cout << "Queue Size: " << queue_vector.size() << std::endl;


    std::cout << std::endl;
    std::cout << "- Note: Examples use an initialized deque/vector, this is not necessary" << std::endl;
    std::priority_queue<int> queue_deque2;
    queue_deque2.push(100);
    queue_deque2.emplace(200);
    print_priority_queue(queue_deque2);
}
