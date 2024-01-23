#include "add_offset.h"

int sum_two(int a, int b) {
    int output = a + b;
    add_offset(output, 2);

    return output;
}