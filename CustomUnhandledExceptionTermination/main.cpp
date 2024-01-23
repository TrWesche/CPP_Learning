#include <iostream>
#include <exception>

void custom_terminate_function() {
    std::cout << "Custom Termination Called - Programed Aborted" << std::endl;
    std::abort();
}

int main(int argc, char **argv){
    std::set_terminate(&custom_terminate_function);

    throw 1;

    return 0;
}