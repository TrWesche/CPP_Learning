#include <iostream>
#include <string>
#include <sstream>


bool ConvertToDouble (std::string& input, double& out_double) {
    std::istringstream iss(input);
    double o;
    iss >> std::noskipws >> o;

    bool success = iss.eof() && !iss.fail();
    if (success) {
        out_double = o;
    }

    return success;
}


int main(int argc, char* argv[]){
    int c_mode_flag_loc {-1};
    const std::string flag_cont_mode {"-C"};

    int f_input_flag_loc {-1};
    const std::string flag_formula {"-F"};

    int operands_qty {};
    std::string* operands {nullptr};

    try
    {
    // If not arguments provided - Exit
        if (argc == 1) {
            std::cout << "No Additional Arguments Provided -- Exiting." << std::endl;
            return 0;
        }

        // Search for Flags
        for (size_t i {}; i < argc; i++) {
            if(argv[i] == flag_cont_mode) {
                c_mode_flag_loc = i;
            } else if(argv[i] == flag_formula) {
                f_input_flag_loc = i;
            }
        }

        // Build Operation List
        if (f_input_flag_loc != -1 || c_mode_flag_loc == -1) {
            int formula_start = f_input_flag_loc < 0 ? 1 : f_input_flag_loc + 1;
            operands_qty = argc - formula_start;

            operands = new std::string[operands_qty];

            for (int i {formula_start}; i < argc; ++i) {
                operands[i - formula_start] = argv[i];
            }
        }


        int variable_location {0};
        double variables[2] {};

        int op_location {0};
        char* operations[1] {};
        char operation;

        do {
            if (operands != nullptr) {
                for (size_t i {}; i < operands_qty; i++) {
                    std::cout << "Printing Operand: " << operands[i] << std::endl;
                    
                    bool op_or_var = ConvertToDouble(operands[i], variables[variable_location]);

                    if (op_or_var) {
                        std::cout << "Value is an Input Number: "  << variables[variable_location] << std::endl;
                        variable_location++;
                    }
                    else {
                        operations[op_location] = operands[i].data();
                        std::cout << "Value is an Operator: " << operands[i] << std::endl;
                        op_location++;
                    }
                }

                operation = operations[0][0];

                switch (operation) {
                    case 'x':
                        std::cout << (variables[0] * variables[1]) << std::endl;
                        break;
                    case '/':
                        std::cout << (variables[0] / variables[1]) << std::endl;
                        break;
                    case '-':
                        std::cout << (variables[0] - variables[1]) << std::endl;
                        break;
                    case '+':
                        std::cout << (variables[0] + variables[1]) << std::endl;
                        break;
                    default:
                        std::cout << "Invalid Operator" << std::endl;
                        break;
                }
                
                // if (operations[0] == "x") {
                //     std::cout << (variables[0] * variables[1]) << std::endl;
                // }
                // else if (operations[0] == "/") {
                //     std::cout << (variables[0] / variables[1]) << std::endl;
                // }
                // else if (operations[0] == "-") {
                //     std::cout << (variables[0] - variables[1]) << std::endl;
                // }
                // else if (operations[0] == "+") {
                //     std::cout << (variables[0] + variables[1]) << std::endl;
                // }
                // else {
                //     std::cout << "Invalid Operator" << std::endl;
                // }

                delete operands;
            }

            c_mode_flag_loc = -1;
        }
        while (c_mode_flag_loc > 0);
        
        std::cout << "Exiting" << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught Exeception" << std::endl;
        std::cerr << e.what() << std::endl;

        if (operands != nullptr) {
            delete operands;
        }

        return -1;
    }
  
}