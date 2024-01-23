#include <iostream>
#include "math_funcs.h"
#include "enum_classes.h"
#include "function_templates_01.h"

// Example of Type Alias
using HugeInt = unsigned long long int;

// This has the potential to be evaulated at compile time
constexpr int compile_time_capable_func(int multiplier) {
    return 5 * multiplier;
}

// This MUST be evaluated at compile time (will throw a compiler error otherwise)
consteval int get_value(){
    return 3;
}

// Compilation - Happens in 3 Stages
//  1. Preprocessing -> Output is Translation Units
//  2. Compilation -> Output is Objects
//  3. Linking -> Output is a single Binary
//      - Notes on Behavior:
//          - Only a single definition of a function may exist (not including overrloads) otherwise linker will not be able to determine what to import
//          - The linker will search all translation units for a function definition, i.e. the cpp file name does not need to match the header


//Function Declarations (Also known as Prototypes) - Must come before the main
int test_function (int val1, int val2);

int test_function (int val1, int val2, int val3);

void test_function_ref (int val1, int val2, int& out_val);


int main(){
    constexpr int value = get_value();

    // Need to mark this as constexpr to evaluate it at compile time
    constexpr int compile_time_expr_val1 = compile_time_capable_func(3);
    // This will still be executed at runtime
    int not_compile_time_expr_val1 = compile_time_capable_func(4);

    int reusable_int {};

    std::cout << "value : " << value << std::endl;

    std::cout << "value 1: " << test_function(1, 2) << std::endl;

    std::cout << "value 1 overload" << test_function(1, 3, 3) << std::endl;
 
    test_function_ref(4, 5, reusable_int);
    std::cout << "value ref: " << reusable_int << std::endl;

    std::cout << "calling imported multiplier " << multiplier(3.5, 10.0) << std::endl;

    std::cout << "calling imported divider " << divider(5, 2) << std::endl;


    int * p_val1{nullptr};
    p_val1 = new int {9}; // Memory is dynamically allocated

    int * p_val2{nullptr};
    p_val2 = new int {4}; // Memory is dynamically allocated

    int * p_val3{nullptr};
    p_val3 = new int {20}; // Memory is dynamically allocated

    std::cout << "calling pointer pass stuff 1 " << pointer_pass_stuff_1(p_val1, p_val2) << " pval1: " << *p_val1 << " pval2: " << *p_val2 <<  std::endl;

    std::cout << "calling pointer pass stuff 2 " << cpointer_pass_stuff_2(p_val1, p_val2) << " pval1: " << *p_val1 << " pval2: " << *p_val2 <<  std::endl;
    
    std::cout << "calling pointer pass stuff 3 " << cpointerc_pass_stuff_3(p_val1, p_val2, p_val3) << " pval1: " << *p_val1 << " pval2: " << *p_val2 << " pval3: " << *p_val3 << std::endl;


    delete p_val1; // Memory is deallocated
    p_val1 = nullptr;

    delete p_val2; // Memory is deallocated
    p_val2 = nullptr;

    delete p_val3; // Memory is deallocated
    p_val3 = nullptr;


    int val_pbref_int1 {3};
    int val_pbref_int2 {7};

    std::cout << "Using integer references with pointer pass stuff 1 " << pointer_pass_stuff_1(&val_pbref_int1, &val_pbref_int2) << std::endl;


    std::cout << "Using pass by reference 1 " << pass_by_ref_1(val_pbref_int1, val_pbref_int2) << std::endl;


    std::cout << "Using pass by const reference 1 " << pass_by_cref_1(val_pbref_int1, val_pbref_int2) << std::endl;


    double arr_of_10[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Using sum 10 array: " << sum_10(arr_of_10) << std::endl;


    double matrix_2dim[][3] {
        {1, 2, 3},
        {3, 4, 5}, 
        {7, 8, 9}
    };
    std::cout << "Using sum_2dim_matrix: " << sum_2dim_matrix(matrix_2dim, 3) << std::endl;

    std::string some_string {"Just some string"};
    function_with_str(some_string);


    Month month {Month::May};

    // Using Template Function
    int fta {10};
    int ftb {5};
    double ftc {10.0};

    maximum(fta, ftb);

    maximum<double>(ftb, ftc); // Explicity specify which version of a function using explicity template argument

    max_by_ref(fta, ftb); // This version uses references to pass the value instead of making copies

    return 0;
}


// Function Definitions
int test_function (int val1, int val2) {
    return val1 + val2;
}

int test_function (int val1, int val2, int val3) {
    return val1 + val2 + val3;
}


void test_function_ref (int val1, int val2, int& out_val) {
    out_val = val1 + val2;
}