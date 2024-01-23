#include <iostream>

int multiplier (int val1, int val2);

double multiplier (double val1, double val2);


int divider (int val1, int val2);

double divider (double val1, double val2);


int pointer_pass_stuff_1 (int* val1, int* val2);

int cpointer_pass_stuff_2 (const int* val1, int* val2);

int cpointerc_pass_stuff_3 (const int* const val1, int* val2, int* val3);

int pass_by_ref_1 (int& val1, int& val2);

int pass_by_cref_1 (const int& val1, const int& val2);

int super_sum (int array[], size_t count);

double sum_10(const double (&input_array)[10]);

double sum_2dim_matrix(const double input_matrix[][3], size_t size);

double sum_3dim_matrix(const double input_matrix[][3][3], size_t size);

int function_with_defaults(int val1, int val2, int val3 = 10);

void function_with_str(std::string_view in_str);