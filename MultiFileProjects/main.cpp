#include <iostream>
#include "utilities.h"
#include "ex_forward_def_a.h"
#include "ex_forward_def_b.h"


int main(){

    double result = add(10.5,20.8);
    std::cout << "result : " << result << std::endl;
    
    ExForwardDefB defB{111.1};
    ExForwardDefA defA{222.2};

    defA.use_def_b(defB);

    return 0;
}