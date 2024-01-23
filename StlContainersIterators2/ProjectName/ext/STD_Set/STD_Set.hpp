#pragma once
#include <set>
#include <string>
#include <iostream>
#include <functional>
#include "Book.hpp"


template<typename T>
void print_set_iterator(const T& collection) {
    auto it = collection.begin();

    std::cout << "[";
    while (it != collection.end()) {
        std::cout << " " << *it;
        it++;
    }
    std::cout << " ]" << std::endl;
}


//Comparator functor
class IntComparator {
public : 
    bool operator()( int left, int right) const { 
        return (left < right); 
    }
};

//Comparator function pointer
bool compare_ints(int left, int right){
    return (left < right);
}


class STD_Set
{
private:
    /* data */

public:
    STD_Set(/* args */);
    ~STD_Set();

    void execute();
};

STD_Set::STD_Set(/* args */)
{
}

STD_Set::~STD_Set()
{
}


void STD_Set::execute() {
    std::set<int> set_int1 {20, 30, 5, 16, 100, 9};

    std::cout << "Note: Set Automatically will order values" << std::endl;
    print_set_iterator(set_int1);
    std::cout << "Set Does Not Allow Random Access with an Index; as this is not stored in contiguous memory you need to use an iterator or a pointer to go to a specific value of the set" << std::endl;
    std::set<int>::iterator set_itr1_b = set_int1.begin();
    std::set<int>::reverse_iterator set_itr1_e = set_int1.rbegin();
    std::cout << "Element Front: " << *set_itr1_b << std::endl;
    std::cout << "Element Front: " << *set_itr1_e << std::endl;
    
    std::cout << "----------" << std::endl;
    std::cout << "Set provides helper functions to check contents of the set." << std::endl;
    std::cout << "Is 16 in Set? " << set_int1.contains(16) << std::endl;
    std::cout << "Is 22 in Set? " << set_int1.contains(22) << std::endl;

    std::cout << "----------" << std::endl;
    std::cout << "Set requires the operator used in comparisons to be unique." << std::endl;
    std::cout << "Trying to insert a second 16 into set. " << std::endl;
    std::pair<std::set<int>::iterator, bool> insert_result = set_int1.insert(16);
    std::cout << "Iterator Value: " << *insert_result.first << std::endl;
    std::cout << "Insert Result: " << insert_result.second << std::endl;
    if (insert_result.second) {
        std::cout << "Insert successful" << std::endl;
    }
    else {
        std::cout << "Insert Failed" << std::endl;
    }
    std::cout << "Trying to insert a 22 into set. " << std::endl;
    insert_result = set_int1.insert(22);
    std::cout << "Iterator Value: " << *insert_result.first << std::endl;
    std::cout << "Insert Result: " << insert_result.second << std::endl;
    if (insert_result.second) {
        std::cout << "Insert successful" << std::endl;
    }
    else {
        std::cout << "Insert Failed" << std::endl;
    }
    std::cout << "Printing out set contents" << std::endl;
    print_set_iterator(set_int1);


    // std::cout << "----------" << std::endl;
    // std::cout << "Set can find a certain element as well" << std::endl;
    // std::set<int>::iterator set_itr1_f = set_int1.find(16);
    // std::cout << "Searched for 16 and found: " << *set_itr1_f << std::endl;

    std::cout << "----------" << std::endl;
    std::cout << "Set requires the operator used in comparisons to be unique." << std::endl;
    std::cout << "Emplace can also be used to contruct the value in place.  Emplacing 55" << std::endl;
    auto emplace_result = set_int1.emplace(55);
    if (emplace_result.second) {
        std::cout << "Emplace successful: " << *emplace_result.first  << std::endl;
    }
    else {
        std::cout << "Emplace Failed: " << *emplace_result.first << std::endl;
    }
    std::cout << "Printing out set contents" << std::endl;
    print_set_iterator(set_int1);


    std::cout << std::endl;
    std::cout << "============= Set Ordering Can Be Customized with a Functor/Lambda/etc. ===============" << std::endl; 
    //std::set<int> numbers1 {11,16,2,9,12,15,6,15,2};  // Use default functor (std::less)
    //std::set<int,std::less<int>> numbers1 {11,16,2,9,12,15,6,15,2};  // Built in functor
    //std::set<int,std::greater<int>> numbers1 {11,16,2,9,12,15,6,15,2}; // Built in functor
    //std::set<int,IntComparator> numbers1 {11,16,2,9,12,15,6,15,2}; // Use Custom functor
    
    //Function pointer
    /*
    std::set<int,bool(*)(int,int)> numbers1(compare_ints) ; 
    numbers1.insert({11,16,2,9,12,15,6,15,2});
    */
   
    std::set<int,std::function<bool(int,int)>> numbers1([](int left,int right){
        return left > right;});
    numbers1.insert({11,16,2,9,12,15,6,15,2}); // Lambda function



    std::cout << std::endl;
    std::cout << "============= Set with Custom Class Book ===============" << std::endl; 
    std::cout << "This custom type must implement the Less Than (<) Operator" << std::endl;
    //Set of custom types : Need to implement operator<
    std::set<Book> books {
        Book(2000,"Cooking Food"),
        Book(1930,"Building Computers"),
        Book(1995,"Farming for Beginners")
    };

    std::cout << "----------" << std::endl;
    std::cout << "Set can find a certain book as well" << std::endl;
    std::set<Book>::iterator books_itr_f = books.find(Book(1995, "Farming for Beginners"));
    std::cout << "Searched for 1995 and found: " << *books_itr_f << std::endl;
                    
    print_set_iterator(books);

}
