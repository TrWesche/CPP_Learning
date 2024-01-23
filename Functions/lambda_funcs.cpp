#include <iostream>

void sample_main() {

    // Lambda Function Signature
    // [Capture List] (parameters) -> Return_Type {Function Body}
    auto sample_func1 = [](){{
        std::cout << "This is a Lambda" << std::endl;
    }};

    sample_func1();

    [](){{
        std::cout << "Directly Calling Lambda" << std::endl;
    }}();


    auto sample_func2 = [](double a, double b){{
        std::cout << "Adding Some Doubles: "  << (a + b) << std::endl;
        return a + b;
    }};
    sample_func2(1.1, 2.2);



    auto sample_func3 = [](double a, double b) -> double {
        return a + b;
    };
    double sample_func3_out = sample_func3(2.4, 3.5);


    // Capture List Usage - Gives you access to variables outside the Lambda Function's Scope.  I.e. a Lambda Function does not have access to variables defined at a higher scope by default
    double a {1.2};
    double b {1.3};

    auto sample_func4 = [a, b](){  // Capture By Value - These are one time copies; the local value will not be updated alongside the external value
        std::cout << "a + b = " << a + b << std::endl;
    };
    sample_func4(); 



    auto sample_func5 = [&a, &b](){  // Capture By Reference - Will be able to see the changes to the external values
        std::cout << "a + b = " << a + b << std::endl;
    };
    sample_func5(); 



    //Capture All in Context By Value, Use '=' in Capture List
    auto sample_func6 = [=](){ 
        std::cout << "a + b = " << a + b << std::endl; // Still have access to a and b
    };
    sample_func6(); 


    //Capture All in Context By Reference, Use '&' in Capture List
    auto sample_func6 = [&](){ 
        std::cout << "a + b = " << a + b << std::endl; // Still have access to a and b
    };
    sample_func6(); 



}