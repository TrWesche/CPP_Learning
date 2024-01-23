#include <iostream>

int multiplier (int val1, int val2)
{
    return val1 * val2;
}

double multiplier (double val1, double val2)
{
    return val1 * val2;
}


int divider (int val1, int val2)
{
    if (val2 != 0) {
        return val1 / val2;
    }
    else 
    {
        return 0;
    }
}

double divider (double val1, double val2)
{
    if (val2 != 0) {
        return val1 / val2;
    }
    else 
    {
        return 0;
    }
}

// Interesting this to not about this, these pointers are copies and not the original pointer
int pointer_pass_stuff_1 (int* val1, int* val2) 
{
    (*val1)++;
    return (*val1 + *val2);
}

// Interesting this to not about this, these pointers are copies and not the original pointer
int cpointer_pass_stuff_2 (const int* val1, int* val2)
{
    // (*val1)++; // Not Modifiable
    (*val2)++;
    return *val1 + *val2;
}

// Interesting this to not about this, these pointers are copies and not the original pointer
int cpointerc_pass_stuff_3 (const int* const val1, int* val2, int* val3) {
    int* ptemp;

    ptemp = val2;
    val2 = val3;
    val3 = ptemp;

    return (*val1 * *val2) + *val3;
}

int pass_by_ref_1 (int& val1, int& val2) {
    val1++;
    val2 += 2;

    return val1 + val2;
}

int pass_by_cref_1 (const int& val1, const int& val2) {
    // val1++;
    // val2 += 2; // Cant change these anymore

    return val1 + val2;
}

// Need the count here because the array will decay into a pointer
int super_sum (int array[], size_t count) {
    int output {};
    for (size_t i{}; i < count; i++) {
        output += array[i];
        // output += *(array++); // This is another option directly referencing the pointer
    }

    return output;
}

// This is a method of getting the compiler to enforce the array to be a certain size
double sum_10(const double (&input_array)[10])
{
    double output;
    for (size_t i{}; i < std::size(input_array); i++) {
        output += input_array[i];
    }

    return output;
}

// Can't have the second dimension be undefined
double sum_2dim_matrix(const double input_matrix[][3], size_t size)
{
    double output;

    for (size_t i{}; i < size; i++) {
        for (size_t j{}; j < 3; j++) {
            output += input_matrix[i][j];
        }
    }

    return output;
}

double sum_3dim_matrix(const double input_matrix[][3][3], size_t size) 
{
    double output;

    for (size_t i{}; i < size; i++) {
        for (size_t j{}; j < 3; j++) {
            for (size_t k{}; k < 3; k++) {
                output += input_matrix[i][j][k];
            }
        }
    }

    return output;
}


// Defaults are specified in the function declaration, they should not be in the definition
int function_with_defaults(int val1, int val2, int val3) 
{
    return (val1 + val2) * val3;
}

// Should use string view to prevent strings from being copied wherever possible
void function_with_str(std::string_view in_str) {
    std::cout << "Printing out string: " << in_str << std::endl;
}