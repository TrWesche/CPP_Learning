#pragma once
#include <map>
#include <string>
#include <iostream>
#include <functional>
#include "Book.hpp"


template<typename K, typename V>
void print_map(const std::map<K, V>& collection) {
    auto it = collection.begin();

    std::cout << "[\n";
    while (it != collection.end()) {
        std::cout << "  (" << it->first << ", " << it->second << ")\n";
        it++;
    }
    std::cout << "]" << std::endl;
}


//Comparator functor
// class IntComparator {
// public : 
//     bool operator()( int left, int right) const { 
//         return (left < right); 
//     }
// };

//Comparator function pointer
// bool compare_ints(int left, int right){
//     return (left < right);
// }


class STD_Map
{
private:
    /* data */

public:
    STD_Map(/* args */);
    ~STD_Map();

    void execute();
};

STD_Map::STD_Map(/* args */)
{
}

STD_Map::~STD_Map()
{
}


void STD_Map::execute() {
    std::map<int, int> map_int1 { {10, 20}, {30, 10}, {5, 100}, {66, 29}, {105, 33}, {1, 1000} };

    std::cout << "Note: Set Automatically will order values by the key using std::less functor" << std::endl;
    print_map(map_int1);

    std::cout << "Map provides the [] operator to access a key directly, will return the value" << std::endl;
    std::cout << "Using Key 10 in the brackets, i.e. map_int1[10] -> will return value 20" << std::endl;
    std::cout << map_int1[10] << std::endl;

    
    std::cout << "----------" << std::endl;
    std::cout << "Map provides helper functions to check contents of the set." << std::endl;
    std::cout << "Is Key 16 in Set? " << map_int1.contains(16) << std::endl;
    std::cout << "Is Key 66 in Set? " << map_int1.contains(66) << std::endl;

    std::cout << "----------" << std::endl;
    std::cout << "Map requires the operator used in comparisons to be unique." << std::endl;
    std::cout << "Trying to insert a second pair with key 10 {10, 100} into set. " << std::endl;
    std::pair<std::map<int, int>::iterator, bool> insert_result = map_int1.insert({10, 100});
    
    // std::cout << "Iterator Value: " << *insert_result.first << std::endl;
    std::cout << "Insert Result: " << insert_result.second << std::endl;
    if (insert_result.second) {
        std::cout << "Insert successful" << std::endl;
    }
    else {
        std::cout << "Insert Failed" << std::endl;
    }
    std::cout << "Trying to insert a pair with key 22 {22, 999} into set. " << std::endl;
    insert_result = map_int1.insert({22, 999});
    // std::cout << "Iterator Value: " << *insert_result.first << std::endl;
    std::cout << "Insert Result: " << insert_result.second << std::endl;
    if (insert_result.second) {
        std::cout << "Insert successful" << std::endl;
    }
    else {
        std::cout << "Insert Failed" << std::endl;
    }
    std::cout << "Printing out set contents" << std::endl;
    print_map(map_int1);



    std::cout << "----------" << std::endl;
    std::cout << "Map requires the operator used in comparisons to be unique." << std::endl;
    std::cout << "Emplace can also be used to contruct the value in place.  Emplacing {55, 555}" << std::endl;
    auto emplace_result = map_int1.emplace(55, 555);
    if (emplace_result.second) {
        std::cout << "Emplace successful: " << std::endl;
    }
    else {
        std::cout << "Emplace Failed: " << std::endl;
    }
    std::cout << "Printing out set contents" << std::endl;
    print_map(map_int1);






    std::cout << std::endl;
    std::cout << "============= Map with Custom Class Book ===============" << std::endl; 
    std::cout << "The key used must implement the < operator" << std::endl;
    //Set of custom types : Need to implement operator<
    std::map<int, Book> books {
        {0, Book(2000,"Cooking Food")},
        {100, Book(1930,"Building Computers")},
        {55, Book(1995,"Farming for Beginners")},
        {19, Book(1995,"Candle Making 101")}
    };

    // std::cout << "----------" << std::endl;
    // std::cout << "Set can find a certain book as well" << std::endl;
    // std::map<int, Book>::iterator books_itr_f = books.find(19);// Book(1995, "Farming for Beginners"));
    // std::cout << "Searched for 1995 and found: " << books.at(books_itr_f) << std::endl;
                    
    print_map(books);



    //Lambda function
    std::cout << std::endl;
    std::cout << "============= You Can Override Standard Ordering Behavior as Well ===============" << std::endl; 
    std::cout << "Ordering Using a Lambda Function to control the ordering.  Can also be a Functor/Function Pointer" << std::endl;
    std::map< int,int,std::function<bool(int,int)> > numbers2 (
        [](int left, int right){ return left > right;}
    );
    numbers2.insert({{1,11},{0,12},{4,13},{2,14},{3,15}});

    
    std::cout << "numbers2 : [\n";
    for(const auto& [key,value] : numbers2){
        std::cout << " (" << key << "," << value << ")\n";
    }
    std::cout << "]" << std::endl;

}
