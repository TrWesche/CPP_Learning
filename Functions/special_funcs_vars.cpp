#include <iostream>

// Static Variable - Lives for the full lifetime of the application
// Kind 1: Global Variable - Defined Outside of the Main Function
// Kind 2: Variable with Static Scope defined inside a function.  This variable lives across function calls, but is only available within that function's scope.

int some_global_static_var {1};

void func_with_static_var() {
    static int some_static_var_init_in_function {1};

    some_static_var_init_in_function++; // Every call of this function updates the variable and it lives across the function calls.
    // Example Usecase: Tracking number of calls to the function

    std::cout << some_static_var_init_in_function << std::endl;

    return;
}



// Inline Functions - Note for the compiler to try to expand the function call in place where the function call is defined rather than the typical behavior where
//                      the function will exist elsewhere in memory and the variables will be passed to that function as such.
//                           - Upside: The normal behavior adds some overhead which can be avoided during execution if the function can be inlined
//                           - Downside: Multiple calls to an inline function will result in the code to be duplicated in multiple places making the binary larger.
inline int sample_inline_func(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}


void fake_main() {
    int a {3};
    int b {2};

    std::cout << sample_inline_func(a, b) << std::endl;
}



// Recursive Functions

int sum_to_zero(int value) {
    if (value > 0) {
        return value + sum_to_zero(value - 1);
    }
    else if (value < 0) {
        return value + sum_to_zero(value + 1);
    }
    else {
        return 0;
    }
}

void fake_recur_main() {

    std::cout << sum_to_zero(3) << std::endl;

    std::cout << sum_to_zero(-5) << std::endl;
}