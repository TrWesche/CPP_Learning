#include <iostream>
#include <string>

consteval int get_value(){
    return 3;
}

int add_numbers(int input1, int input2) {
    return input1 + input2;
}

int get_number_input() {
    int input;

    try
    {
        std::cout << "Type in a number" << std::endl;
        std::cin >> input;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' << std::endl;
        input = 0;
    }
    
    return input;
}


std::string get_string_input() {
    std::string input;

    try
    {
        std::cout << "Type in some name" << std::endl;
        std::cin >> input;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        input = "";
    }
    
    return input;
}

std::string get_input_line() {
    std::string input;

    std::cout << "Type in some stuff with spaces to be caputed in a single line" << std::endl;
    // std::cin.ignore();
    std::cin.clear();
    std::getline(std::cin, input);

    return input;
}


int stream_in_multiple_inputs() {
    std::string input_str;
    int input_num;

    try
    {
        std::cout << "Type in a string and a number separated by a space" << std::endl;
        std::cin >> input_str >> input_num;
        std::cout << input_str << " | " << input_num << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

int main(int argc, char **argv){
    unsigned int first_num {4};
    signed int second_num {100};

    // Integer size modifiers
    // short = 2 bytes
    // int = 4 bytes
    // long = 4 or 8 bytes (compiler dependent)
    // long long = 8 bytes
    // sizeof(variable) will return how many bytes are allocated

    // Floating Point size modifiers
    // float = 4 bytes - precision 7
    // double = 8 bytes - precision 15
    // long double = 12 bytes - precision > double (compiler dependent)
    // std::setprecision(20) <- control the precision printed out from std::cout (Comes from iomanip library)

    // Boolean = 1 byte (8 bits)
    // std::boolalpha <- Makes boolean outputs read as true/false

    // Char = 1 byte - Standard ASCII Encoding Table
    //    - char value = 65 -> This will be implicitly converted to a Character based on the Decimal Code

    // Operator Precedence (Order Of Operators) & Associativity (Direction of interpretation i.e. Left to Right or Right to Left)
    // There is a wikipedia table for this
    // () - Overrides
    // *, /, % | Left to Right
    // +, - | Left to Right

    // Prefix and Postfix +/-
    // value++ <- do the addition immediately after (Postfix)
    // ++value <- do the addition immediately before (Prefix)

    // Compound Operations
    // +=
    // -=
    // *=
    // /=
    // %=

    // Relation Operators
    // >
    // <
    // >=
    // <=
    // ==
    // !=   

    // Logical Operators
    // &&
    // ||
    // !

    // Output Formatting
    // Libraries: ios, iomanip, ostream
    // std::flush -> Manually sends buffer to the terminal
    // std::setw -> Set width of text printed to the terminal
    // std::right -> justification
    // std::internal -> sign for a number is left justified while data is right
    // std::setfill('-') -> specify the fille character
    // std::showpos / std::noshowpos -> show positive sign
    // std::dec -> show data in decimal
    // std::hex -> show data in hex
    // std::oct -> show data in octal
    // std::showbase / std::noshowbase -> show base numberset as part of the output
    // std::uppercase -> show data in uppercase
    // std::fixed -> force fixed print rather then scientific notation
    // std::scientific -> force everything to print in scientific notation
    // std::count.unsetf(std::ios::scientific | std::ios::fixed) -> set things back to defaults
    // std::setprecision -> set print precision
    // std::showpoint -> force showing of decimals for floating point


    // Numeric Limits
    // Library: limits
    // std::numeric_limits<T>::min()
        // Floating Point = Smallest Positive Number
        // Integer = Max Negative Number
    // std::numeric_limits<T>::max()
        // Floating Point = Max Positive Number
        // Integer = Max Positive Number
    // std::numeric_limits<T>::lowest()
        // Floating Point = Max Negative Number
        // Integer = No Meaning


    // Math Functions
    // Library: cmath

    // Integral Types Which Cannot Handle Aritematic Operations
    // Char
    // Short Int

    // Literals - These variables live in the Program's memory area instead of outside of the program's allocated space
    // const
    // constexpr: Constant that has the POTENTIAL to be evaluated at compile time
    //      - Useful to move heavy computations that don't need to be modified after the program starts from runtime to compile time.
    //         Instead of the computation executing every time the binary is run it will only be run once during the compile and the result
    //         of the comuptation will be "baked" into the binary.
    //      - const and constexpr can't be combined, constexpr is already a constant
    // constinit: A variable that should be initialized with a constant or literal at compile time
    //      - Used for helping control the initialization of global variables outside of the main function.  
    //          A const init can only exist with static or thread storage duration (ex. global variables.)
    //      - Must be initialized with const or literals
    //      - Does not mean the variable is Constant, it only means initialization is enforced at compile time
    //      - const and constinit can be combied (i.e. const constinit int value = {100})

    // Data Conversions
    // implicit
    // explicit: static_cast<int>(x)

    // Assertions
    // static_assert - This assertion happens at compile time and can be used for validations

    // Bitwise Operators
    // How to Print:
    //      - Library: bitset
    //      - std::bitset<16>(data)
    // Shift Operators:
    //      - << Shift Left
    //          - Multiplies by 2^n until data is lost
    //      - >> Shift Right
    //          - Divides by 2^n until data is lost
    //      - Ex: value = (value >> 1)
    //          - Note: The shift operation will convert the value behind the scenes to the base version; i.e. unsigned short int will be cast to int by the shift operation
    // Logical Operators:
    //      AND: &
    //      OR: |
    //      XOR: ^
    //      NOT: ~
    // Compound Operators:
    //      >>=
    //      <<=
    //      |=
    //      &=
    //      ^=
    // Masks:
    //      Safely set (val | mask), reset (val & ~mask), check ((val & mask) >> position), and toggle bits (val ^ mask) at specific positions
 

    // Variable Lifetime / Storage Duration
    //      Local (block, automatic) - Is deallocated at the end of the code block
    //      Static - Is deallocated when the program ends
    //      Dynamic - Developer decides when it is deallocated

    // Flow Control
    //      if, else, else if
    //      switch (variable) ( case x: {} break; case y: {} break; default: {} break; )
    //          - variable can only be an integer or enum
    //      ternary operator
    //          - result = (condition) ? true_option : false_option;
    // Order of AND/OR Operations can improve performance
    // Integral Logic Conditions
    //      Any Number different then a 0 will evaluate as true
    // if constexpr
    //      - if constexpr(condition) { do this } else { do that };
    //      - The block of code matching the condition is the only part of the expression which will be maintained in the compiled binary
    // if initializer
    //      - if (int high_speed{33}; go) { do this } else {do that};
    //      - Allows variables relevant to the if scope to be initialized within the if statement to reduce variable pollution
    // switch with initializer
    //      - switch (double strength{1.23}, tool) {case 1: do this; case 2: do that; default: do something;}
    //      - Allows variables relevant to the switch scope to be initialized within the switch statement to reduce variable pollution


    // Loops
    // For Loop
    for (unsigned int i{}; i < 10; ++i) {
        std::cout << "For Loop: " << i << std::endl;
    }

    for (size_t i{}; i < 10; ++i) {  // Use this version, size_t is a special type for iterators; is a representation of an unsigned int
        std::cout << "For Loop: " << i << std::endl;
    }

    // For Loop w/ Multiple Declarations - Only 1 Variable Can Control the Loop Lifecycle (in this example y) 
    for (size_t i{0}, x{5}, y{22}; y > 15; ++i, x+=5, y-=1) {
        std::cout << "Multi Declaration For Loop - i: " << i << " x: " << x << " y: " << y << std::endl;
        
        // break;
        // continue;
    }

    // Range Based For Loop
    int value_array [] {1,2,3}; // Collection
    for (int value : value_array) {
        std::cout << "Range Based Iterator: " << value << std::endl;
    }

    // While Loop
    const unsigned int w_loop_count {5};
    unsigned int w_loop_i {0};
    while (w_loop_i < w_loop_count) {
        std::cout << "While Loop: "  << w_loop_i << std::endl;
        ++w_loop_i;
    }

    // Do While Loop
    const unsigned int dw_loop_count {5};
    unsigned int dw_loop_i {0};
    do {
        std::cout << "Do While Loop: "  << dw_loop_i << std::endl;
        ++dw_loop_i;
    } while (dw_loop_i < dw_loop_count);
    
    // Comma Operator
    //      - Combines two or more expressions into a single expression.  The value of the operation is the right operand

    
    // Arrays
    int sample_array[10]; // 10 Specifies the Size
    sample_array[0] = 10;

    int initialized_array [] {1,2,3,4,5};

    std::cout << std::size(initialized_array) << std::endl;

    // Character Arrays
    //  - Can be printed out directly, but only if they end with \0 - The Null Termination Character
    char message [6] {'H', 'e', 'l', 'l', 'o', '\0'}; // Note: Can also leave the null terminator off and the value will be initialized to \0
    std::cout << std::size(message) << std::endl;


    // Random Numbers
    // std::time(0);
    std::srand(std::time(0)); // Seed the rand function with time since Jan 1st, 1970 at 00:00:00 AM
    int random_num = std::rand(); // Value between 0 and RAND_MAX (Compiler Dependent)
    int rand_between_0_10 = random_num%11;


    // 2 Dimensional Array
    int sample_2dim_arr [4][3] {
        {1, 2, 3},
        {3, 4, 5},
        {4, 5, 6},
        {5, 6, 7}
    };  
    for ( size_t i {0}; i < std::size(sample_2dim_arr); i++) {
        for (size_t j {0}; j < std::size(sample_2dim_arr[i]); j++) {
            std::cout << "[i:" << i << "j:" << j << " - " << sample_2dim_arr[i][j] << "]";
        }
        std::cout << std::endl; 
    }

    // 3 Dimensial Array
    int sample_3dim_arr [2][2][2];  


    // Pointers - Must be associated with the type they are pointing to
    int * p_var_int{nullptr};
    double * p_var_double;

    int sample_pointer_value {100};

    p_var_int = &sample_pointer_value; //  & is the Address Of Operator

    // Dereferencing a Pointer
    std::cout << *p_var_int << std::endl;

    // Character Pointers -- Points to the first character of the const char array assigned to the pointer.  Value at pointer cannot be modified
    const char * p_message {"Hello World"};

    // Constant Usage
    // const int* -> Variable behind the pointer is a constant
    // int* const -> Pointer address is constant
    // Can be combined -> const int* const

    // Special Type for Pointer Differences
    // std::ptrdiff_t


    // Memory Types
    // Stack:
    //      - Finite
    //      - Developer is not in control of the lifetime
    //      - Lifetime is defined by the Program Scope
    // Heap (Dynamic):
    //      - Finite
    //      - Additional memory where developer is in full control of allocation and lifetime
    //      - Lifetime is controlled with the new and delete operators
    int * p_sample_heap1{nullptr};
    p_sample_heap1 = new int; // Memory is dynamically allocated
    delete p_sample_heap1; // Memory is deallocated
    p_sample_heap1 = nullptr;

    // Dangling Pointers - Things to be Cautious About and make sure they do not exist in the program
    //      - Unitiliazied Pointer
    //      - Deleted Pointer
    //      - Multiple Pointers to Same memory


    // new Failures - Happens rarely but good to handle for
    //      - Handle through Exception
    try {
        // int* lots_of_ints3 { new int[10000000]};
    } catch (std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }
    //      - Handle through the std::nothrow setting
    // int* lots_of_ints4 { new(std::nothrow) int[10000000]}; // On failure will return nullptr
    // if (lots_of_ints4 == nullptr) {
    //     std::cout << "Memory Allocation Failed" << std::endl;
    // }


    // Memory Leaks - Something to be cautious of, some example cases:
    //      - Multiple new assigments to a single pointer
    //      - Deferencing a value into a currently allocated pointer
    //      - Scope defined pointer with a reference to dynamic memory being release on scope


    // Dynamic Arrays
    //      - Allocating: double* p_salaries {new(std::nothrow) double[10] {1,2,3}};
    //      - Releasing: delete[] p_salaries;  p_salaries = nullptr;


    // References
    int val_to_reference {45};
    int& ref_to_val_to_ref {val_to_reference};
    //  - Const Reference: Won't let you modify the target through the reference, however the target value does not need to be const!
    const int& const_ref_to_val_to_ref{val_to_reference};
    //  - Sample Usecase: Reference in a for loop.  Each value within the array will be modified i.e. 10, 20, 30, 40, 50 will populate the array after the loop runs
    int ref_values[] {1, 2, 3, 4, 5};
    for (int& value : ref_values) {
        value = value * 10;
    }

    // Reference vs. Pointer
    // Reference
    //  - Don't use dereferencing for reading and writing
    //  - Can't be changed to reference something else
    //  - Must be initialized at declaration
    //      - Note: List const pointers (int *const variable)
    // Pointer
    //  - Must go through dereference operator to read/write to pointed to value
    //  - Can be updated to point elsewhere
    //  - Can be declared uninitialized 




    // Character String Handling
    // Library: cctype
    // std::isalnum('C') - Checks if the value is alphanumeric (Behavior is linked to C Locale)
    // std::isalpha('C') - Checks if the value is alphabetic (Behavior is linked to C Locale)
    // std::isblank('C') - Checks if value is a blank character, can be combined with a loop to check for blanks.
    std::string sample_msg_1 {"Sample Message"};
    int sample_msg_1_count {0};
    for (size_t i{0}; i < sample_msg_1.size(); i++) {
        if (std::isblank(sample_msg_1[i])) {
            sample_msg_1_count++;
        }
    }
    // std::isupper('C')
    // std::islower('C')
    // std::isdigit('1')
    // std::toupper('c')
    // std::tolower('C')


    // CString - Don't recommend using this library
    // Library: cstring
    // std::strlen - Gets length of string (also works on pointers).  Does not include null character
    // std::strcmp(a, b) - Compares 2 strings.  a comes before b = Negative, equivalent = 0, a comes after b = Postive
    // std::strncmp(a, b, n) - Compares strings up to a specified number of character
    // std::strchr(result, target) - Returns location of first occurence (Pointer if found, Null Pointer If Not Found)
    // std::strrchr(result, target) - Returns location of last occurence
    // std::strcat(dest, src) - Concatenates the two values into the "dest" character array -- Don't Use, it is an unsafe function
    // std::strncat(dest, src, n) - Same as above, with a specification for number of characters -- Don't Use
    // std::strcpy(dest, src) - Copy from source to destination
    // std::strncpy(dest, src, n) - Copy from source to destination


    // std::string
    // Library: string
    // Concatenation: + Operator (Doesn't work for String Literals by default)
    //          - Can use the string literals namespace to handle string literals differently by enabling a new suffix
    //              using namespace std::string_literals;
    //              std::string sample_str_literal_concat {"Hello"s + " World"};
    // Append: string_val.append(other_string_val);
    //      - Append is overloaded so it can do multiple different things
    // std::to_string
    // Size: string_var.size()
    // Loop:
    //  for (char value : string_var) {}
    // At: string_var.at() - Access value at a specified index
    // Front: string_var.front() - Note: Just a copy unless you use references
    // Back: string_var.back()  - Note: Just a copy unless you use references
    // Return const char* under the string type: string_var.c_str() 
    // Get modifiable char array: string_var.data()
    // Empty: string_var.empty()
    // Max Size: string_var.max_size()
    // Capacity: string_var.capacity() - Current max number of characters you can store in a string (i.e. the current allocation space, not the max space)
    // Reserve: string_var.reserve(number) - Manually allocate space
    // Shrink to Fit: string_var.shrink_to_fit()
    // Clear: string_var.clear()
    // Insert Chars: string_var.insert(index, qty, character) - Note: This does not overwrite, it shifts characters in the array to make space for the new character
    //          - Has lots of overloads, ex. addition version string_var.insert(index, const_char_array)
    // Erase: string_var.erase(index, qty)
    // Push Back: string_var.push_back(char)
    // Pop Back: string_var.pop_back()
    // Comparison - Using standard operators
    //      ==, !=, >, >=, <, <=
    // Comparison - Using Method
    //  string_var.compare(b) - Will return Negative, 0, or Positive
    // Replacing: string_var.replace(index, length, value)  - There are overloads
    // Copying: string_var.copy(dest_array, length, index)
    // Resizing: string_var.resize(number) - Autofills with null or specified character when expanding
    // Swapping: string_var.swap(string_var_other)
    // Find/Search: string_var.find(search_term) - If found will return index, if not will return std::string::npos
    // To String: std::to_string(value)
    // From String to Number:  Integer - std::stoi(string_value), Double - std::stod(string_value), and more.
    // Escape Sequences:
    //      - \n, \", etc.
    // Raw String Literals: A way to write strings in a way where escaped characters will be generated by the compiler.  Note the --- allows symbols which may confuse the compiler to also be added to the literal
        std::string todo_list {R"---(
            Task 1
            "Task 2"
            Task 3
        )---"};
    // String View: A type to save memory if a string literal is used multiple times rather than having multiple copies
        std::string_view sv_val1 {"Hello"};
        std::string_view sv_val2 {sv_val1}; // Rather then copies these reference the original literal
        std::string_view sv_val3 {sv_val2};
        // Make sure the view dies before the string being viewed.  Can cause errors otherwise

    constexpr int value = get_value();
    int sum = add_numbers(1, 2);

    std::cout << "value : " << value << " | sum : " << sum << " | another num: " << add_numbers(first_num, second_num) << std::endl;

    std::cerr << "Logging an Error" << std::endl;

    std::clog << "Logging some information" << std::endl;

    // std::string input_string = get_string_input();
    // int input_num_one = get_number_input();
    // int input_num_two = get_number_input();
    // std::cout << input_string << " summed inputs to: " << add_numbers(input_num_one, input_num_two) << std::endl;

    // stream_in_multiple_inputs();
    
    std::string get_line_input = get_input_line();
    std::cout << get_line_input << std::endl;

    return 0;
}