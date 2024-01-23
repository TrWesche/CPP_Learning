#pragma once

#include "Point.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

template <typename T>
void print_view_collection(const T& collection) {
    auto itr = collection.begin();

    std::cout << "[ ";
    
    while (itr != collection.end()) {
        std::cout << *itr << " ";
        itr++;
    }

    std::cout << "]" << std::endl;

}

void print_view(auto view) 
{
    for (auto i : view) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


class CPP_View
{
private:
    /* data */
public:
    CPP_View(/* args */);
    ~CPP_View();

    void execute();
};


CPP_View::CPP_View(/* args */)
{
}

CPP_View::~CPP_View()
{
}

void CPP_View::execute() {
    std::cout << "====== CPP views allow you to create inexpensive \" views \" for your collections which will show you a target subset of your collection ======" << std::endl;
    std::cout << "  There are multiple types of these which provide different functionality.  Some examples include: " << std::endl;
    std::cout << "  - fiter_view\n  - transform_view\n  - take_view\n  - take_view_while" << std::endl;
    std::vector<int> vec_int1 { 100, 20, 5, 16, 2, 33, 9, 201, 7 };
    


    std::cout << "\n Filter View Example -- Creating views for collection: " << std::endl;
    print_view_collection(vec_int1);

    std::cout << "--- A filter_view can be stored in a variable.  That view will be computed when called, in this case when the view needs to be printed." << std::endl;
    std::ranges::filter_view view_even = std::ranges::filter_view(
        vec_int1, 
        [](const int& val) { return (val % 2 == 0);}
    );

    std::cout << "View only displaying even values: " << std::endl;
    print_view(view_even);


    std::cout << "--- A filter_view can also be immediately instantiated instead of being stored in a variable." << std::endl;
    std::cout << "    In this case we are filtering for values divisible by 10." << std::endl;
    print_view(
        std::ranges::filter_view(
            vec_int1, 
            [](const int& val) {return (val % 10 == 0); }
        )
    );




    std::cout << "\n Transform View Example -- Creating views for collection: " << std::endl;
    std::vector<int> vec_int2 { 11, 15, 19, 23, 27 };
    print_view_collection(vec_int2);

    std::cout << "Transforming values, multiplying by 10: " << std::endl;
    std::ranges::transform_view vec_int2_transformed = std::ranges::transform_view(
        vec_int2, 
        [](int val) {return val * 10; }
    );
    print_view(vec_int2_transformed);

    std::cout << "Original collection after view transform" << std::endl;
    print_view_collection(vec_int2);




    std::cout << "\n Take View Example" << std::endl;
    std::cout << "  - Drop View works similarly but drops the quantity of values specified from the front of the collection and keeps the rest" << std::endl;
    std::vector<int> vec_int3 { 11, 15, 19, 23, 27 };
    print_view_collection(vec_int3);

    std::cout << "Taking first 3 values: " << std::endl;
    std::ranges::take_view vec_int3_take = std::ranges::take_view(
        vec_int3, 
        3
    );
    print_view(vec_int3_take);



    std::cout << "\n Take While View Example" << std::endl;
    std::cout << "  - Drop While View works similarly but drops values until the specified condition is met and keeps the rest" << std::endl;
    std::vector<int> vec_int4 { 11, 13, 14, 15, 16, 17, 18 };
    print_view_collection(vec_int4);

    std::cout << "Taking values until one evenly divisble by 3 is encountered: " << std::endl;
    std::ranges::take_while_view vec_int4_take_while = std::ranges::take_while_view(
        vec_int4, 
        [](int val) {return (val % 3) != 0;}
    );
    print_view(vec_int4_take_while);


    std::cout << "\n====== While the definitions above can be used it is recommended to use Range Adaptors to create your views ======" << std::endl;
    std::cout << "  - These live in the std::views namespace" << std::endl;
    std::cout << "\nExamples using std::views::keys and std::views::pairs" << std::endl;
    std::vector<std::pair<int, std::string>> pairs1 {{1, "one"}, {2, "two"}, {3, "three"}};
    auto pairs1_key_view = std::views::keys(pairs1);
    auto pairs1_value_view = std::views::values(pairs1);
    print_view(pairs1_key_view);
    print_view(pairs1_value_view);


    std::cout << "\nExample using std::views::filter filtering for even values" << std::endl;
    std::vector<int> vec_int5 { 11, 13, 14, 15, 16, 17, 18 };
    print_view_collection(vec_int5);
    auto vec_int5_filter_view = std::views::filter(vec_int5, [](const int& val) {return (val % 2) == 0;});
    print_view(vec_int5_filter_view);




    std::cout << "\n====== Views can also be chained to perform more complicated operations; this is termed View Composition ======" << std::endl;
    std::cout << "Source Collection:" << std::endl;
    std::vector<int> vec_int6 { 1, 2, 3, 4, 5, 6, 7 };
    print_view_collection(vec_int6);

    auto filter_even = [](const int& i){return (i % 2) == 0;};
    auto square_value = [](int i){return pow(i, 2);};
    auto mult_two = [](int i){return i * 2;};
    auto div_ten = [](int i){return i / 10;};

    std::cout << "Filtering collection for even values and squaring the results of the filter" << std::endl;
    auto chained_view1 = std::views::transform(std::views::filter(vec_int6, filter_even), square_value);
    print_view(chained_view1);

    std::cout << "Multiplying same input by 2 then filtering for even" << std::endl;
    auto chained_view2 = std::views::filter(std::views::transform(vec_int6, mult_two), filter_even);
    print_view(chained_view2);


    std::cout << "\n--- A Pipe Operator can also be used as syntactic sugar to make things more readable" << std::endl;
    std::vector<int> vec_int7 { 10, 20, 30, 40, 50, 60, 70 };
    print_view_collection(vec_int7);
    std::cout << "Dividing by 10 -> filtering for even -> multiplying by two" << std::endl;
    auto chained_view3 = vec_int7 | std::views::transform(div_ten) | std::views::filter(filter_even) | std::views::transform(mult_two);
    print_view(chained_view3);




    std::cout << "\n====== Range factories can also be used to generate views lazily; for example you can use a view to generate an infinite sequence of integers without needing to define a container ======" << std::endl;
    std::cout << "  - These views still work with composition & the pipe operator" << std::endl;
    // auto infinite_view = std::views::iota(1); // This view is unbounded and would loop forever / until a forced escape

    std::cout << "Using iota view to loop through 1-19 (defined as 1 - 20 in the iota range, 20 is non-inclusive)" << std::endl;
    for (auto i : std::views::iota(1, 20)) {
        std::cout << i << " ";
    } 
    std::cout << std::endl;
}