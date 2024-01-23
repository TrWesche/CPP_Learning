#include <string>
#include <iostream>

class CopyConstructor
{
private:
    std::string str_val1 {};
    std::string str_val2 {};
    int* num_val1 {};

public:
    CopyConstructor() = default;
    CopyConstructor(const CopyConstructor& source_cc);
    CopyConstructor(const std::string& in_str_val1, const std::string& in_str_val2, int in_num_val1);
    ~CopyConstructor();

public:
    const std::string& get_str_val1() const {
        return str_val1;
    }

    const std::string& get_str_val2() const {
        return str_val2;
    }

    const int* get_num_val1() const {
        return num_val1;
    }

    CopyConstructor* set_str_val1(std::string& in_str_val1) {
        str_val1 = in_str_val1;
        return this;
    }

    CopyConstructor* set_str_val2(std::string& in_str_val2) {
        str_val2 = in_str_val2;
        return this;
    }

    CopyConstructor* set_num_val1(int in_num_val1) {
        *num_val1 = in_num_val1;
        return this;
    }

public:
    void print_about() {
        std::cout << str_val1 << " | " << str_val2 << " | " << *num_val1 << std::endl;
    }
};

// Direct Implementation of a Copy Constructor (Note the special handling of the int * variable)
// CopyConstructor::CopyConstructor(const CopyConstructor& source_cc) :
//     str_val1(source_cc.get_str_val1()), str_val2(source_cc.get_str_val2()), num_val1(new int(*(source_cc.get_num_val1())))
// {
// }



// Copy Constructor Implementation using Constructor Delegation
CopyConstructor::CopyConstructor(const CopyConstructor& source_cc) :
    CopyConstructor(source_cc.get_str_val1(), source_cc.get_str_val2(), *source_cc.get_num_val1())
{
}

CopyConstructor::CopyConstructor(const std::string& in_str_val1, const std::string& in_str_val2, int in_num_val1) :
    str_val1(in_str_val1), str_val2(in_str_val2), num_val1(new int(in_num_val1))
{}

CopyConstructor::~CopyConstructor()
{
    delete num_val1;
}
