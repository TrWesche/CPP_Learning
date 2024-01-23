#include <iostream>
#include "sum_to_zero.h"
#include "sum_two.h"
#include "sum_array.h"

int global_static {100};

int main(int argc, char **argv){
    int a {5};
    int b {10};
    
    int result_sum_two = sum_two(a, b);
    std::cout << result_sum_two << std::endl;

    
    int arr_to_sum[] {10, 5, 6, 4, 5};
    int arr_sum_output = sum_array(arr_to_sum, std::size(arr_to_sum));
    std::cout << arr_sum_output << std::endl;



    int value1 = sum_to_zero(3);
    // int value2 = sum_to_zero(-2);

    std::cout << "value1 : " << value1 << std::endl;
    // std::cout << "value2 : " << value2 << std::endl;

    std::cout << "global_static : " << global_static << std::endl;

    return 0;
}