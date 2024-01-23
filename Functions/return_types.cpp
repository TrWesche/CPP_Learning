#include <iostream>
#include <optional>

// Return By Values

int add_two (int a, int b) {
    return a + b;
}


// Return By References

int& compare_two(int& a, int& b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}


// Caution!  Don't do something like this, local variable will still be destroyed after the function executes
int& bad_function(int& a, int& b) {
    int ret_val = a + b;
    return ret_val;
}

// Caution!  Also don't do something like this; since the variables are not being passed in as references these are local copies scoped to the "another_bad_function"
int& another_bad_function(int a, int b) {
    if (a > b) {
        return a;
    }
    else 
    {
        return b;
    }
}


void sample_main() {
    int a {15};
    int b {13};

    int& compare_result_1 =  compare_two(a, b); //Returns a reference with refers to variable a
    int compare_result_2 = compare_two(a, b); // Return a copy of the result of the function
}



// Return By Pointer
int* max_return_pointer(int* a, int* b) {
    if (*a > *b) {
        return a;
    }
    else {
        return b;
    }
}

// Caution: Similar to references it is easy to accidently return pointers to local vairables

void sample_main_2() {
    int a {15};
    int b {13};

    int* compare_result_1 =  max_return_pointer(&a, &b); //Returns a pointer for variable a  
}





// Sample with Array
const double* find_max_in_array(const double input_arr[], size_t size) 
{
    size_t max_index{0};
    double current_max = input_arr[0];

    for (size_t i {1}; i < size; i++)
    {
        if (input_arr[i] > current_max) {
            max_index = i;
            current_max = input_arr[i];
        }
    }

    return &input_arr[max_index];
}





void sample_func_with_optional() {
    std::optional<int> opt_val1{3};
    std::optional<std::string> opt_val2{"Optional"};
    std::optional<double> opt_val3{std::nullopt};
    std::optional<char> opt_val4{}; // Initializes to std::nullopt


    std::cout << opt_val1.value() << std::endl; // Gets Value of the Optional Value

    if (opt_val4.has_value()) {
        std::cout << opt_val4.value() << std::endl; // This would cause a crash if nullopt
    }
}


std::optional<int> sample_func_w_opt_output(const std::string & str, char c) {
    for (size_t i{}; i < str.size(); i++) 
    {
        if(str.c_str()[i] == c) {
            return i;
        }
    }

    return {};
}


std::optional<int> sample_func_w_opt_out_in(const std::string & str, std::optional<char> c = std::nullopt) {
    char char_to_find = c.value_or('z'); // Facility with std::optional to fill in for uninitialized values

    for (size_t i{}; i < str.size(); i++) 
    {
        if(str.c_str()[i] == char_to_find) {
            return i;
        }
    }

    return {};
}