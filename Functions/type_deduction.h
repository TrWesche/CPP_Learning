
void some_function() {
    int a {9};
    double b {5.5};

    decltype( (a > b) ? a : b) c {67}; // The result of the expression within decltype will be used to deduce the type of c
}