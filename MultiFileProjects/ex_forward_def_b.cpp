#include "ex_forward_def_b.h"

ExForwardDefB::ExForwardDefB(double in_var_1) : m_var_1(in_var_1) {};

ExForwardDefB::~ExForwardDefB() {};


void ExForwardDefB::print_info() const {
    std::cout << "Info on Def B: " << m_var_1 << std::endl;
}

double ExForwardDefB::get_var_1 () {
    return m_var_1;
}

void ExForwardDefB::set_var_1 (double in_var_1) {
    m_var_1 = in_var_1;
}
