#include "CPP_Iterators.hpp"

CPP_Iterators::CPP_Iterators(/* args */)
{
}

CPP_Iterators::~CPP_Iterators()
{
}

void CPP_Iterators::execute() {
    std::vector<int> vec_int1 {1, 5, 19, 49, 24, 11, 29, 1, 15, 17, 1};
    std::cout << vec_int1 << std::endl;

    vec_int1.emplace_back(100);
    vec_int1.push_back(100);

    std::cout << "\n-------- Find ---------" << std::endl;
    std::cout << "Find requires the Container to have read access and a forward iterator available for the std::ranges to use" << std::endl;
    std::cout << "  - Note: The iterator used for find can be a constant iterator" << std::endl;
    if ( std::ranges::find(vec_int1.cbegin(), vec_int1.cend(), 19) != vec_int1.cend() ) {
        std::cout << "vec_int1 contains: 19" << std::endl;
    } else {
        std::cout << "vec_int1 does not contain: 19" << std::endl;
    }

    std::cout << "\n-------- Copy ---------" << std::endl;
    std::cout << "Copy requires the Container to implement both the ++ operator (to move to the next object in the container) and requires the destination to be writable by reference" << std::endl;
    std::vector<int> vec_int2 = std::vector<int>(vec_int1.size());
    std::cout << "  - We are going to copy from the contant iterator of vec_int1 to the non constant iterator of vec_int2" << std::endl;
    // std::ranges::copy(vec_int1.cbegin(), vec_int1.cend(), vec_int2.cbegin()); // This is invalid because the copy is not able to write to the const iterator of vec_int2
    std::ranges::copy(vec_int1.cbegin(), vec_int1.cend(), vec_int2.begin());
    std::cout << "vec_int2 post copy: " << vec_int2 << std::endl;

    std::cout << "\n-------- Replace ---------" << std::endl;
    std::cout << "Replace requires the Container to implement both the ++ operator (to move to the next object in the container) and requires the a writeable iterator reference" << std::endl;
    std::cout << "  - We are going to replace all instances of 1 in vec_int2 with 1234.  This requires the begin iterator to be writeable (can be dereferenced)." << std::endl;
    std::ranges::replace(vec_int2.begin(), vec_int2.cend(), 1, 1234);
    std::cout << "vec_int2 post replace: " << vec_int2 << std::endl;

    std::cout << "\n-------- Reverse ---------" << std::endl;
    std::cout << "Reversing the container requires the -- operator to be implemented in the container" << std::endl;
    std::ranges::reverse(vec_int2);
    std::cout << "vec_int2 post reverse: " << vec_int2 << std::endl;

    std::cout << "\n-------- Sort ---------" << std::endl;
    std::cout << "Sort requires the random access iterator [] ()? to be implemented" << std::endl;
    std::ranges::sort(vec_int2);
    std::cout << "vec_int2 post sort: " << vec_int2 << std::endl;
}