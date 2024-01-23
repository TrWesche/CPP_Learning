#include <string>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int max(int a, int b, int c) {
    int intermediary;
    if (a > b) {
        intermediary = a;
    }
    else {
        intermediary = b;
    }

    if (c > intermediary) {
        return c;
    }
    else {
        return intermediary;
    }
}

double max (double a, double b) {
    return (a > b) ? a : b;
}



double max (double* numbers, size_t count) {

}

int max (int* numbers, size_t count) {

}



// Passing by reference potential Problem
// The two functions below can be AMBIGUOUS because inputs to these functions can be exactly the same
void say_my_name(const std::string& name) {

}

void say_my_name(std::string name) {

}