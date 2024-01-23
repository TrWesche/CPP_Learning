#include "ex_forward_def_a.h"
#include "ex_forward_def_b.h" // You still need to include the header for B in the definitions

ExForwardDefA::ExForwardDefA(double in_var_1) : m_var_1(in_var_1) {};

ExForwardDefA::~ExForwardDefA() {};

void ExForwardDefA::use_def_b(const ExForwardDefB& b) {
    b.print_info();
}

// void def_req_function(ExForwardDefB &b) {
//     std::cout << b.get_var_1() << std::endl;
// }

double ExForwardDefA::get_var_1 () {
    return m_var_1;
}
void ExForwardDefA::set_var_1 (double in_var_1)
{
    m_var_1 = in_var_1;
}