// Including B in the header creates a dependency in class A on class B.  
//      Every time class a is used class b will also need to be compile and evey change in class b will affect class a even if the changes are not important to class A
//      However if the definition is required for Class A to operate you will need to use the include.
// #include "ex_forward_def_b.h" 

// Better practice is a forward declaration where you give class A an empty declaration for class B which will be linked up with the definition provided in class B
#if !defined(EXFORWARDDEFA_H)
#define EXFORWARDDEFA_H

#include <iostream>

class ExForwardDefB;

class ExForwardDefA {
    private:
        double m_var_1 {};
        // ExForwardDefB defB; // Not valid with forward declaration - Definition Required

    public:
        void use_def_b(const ExForwardDefB& b); // Ok with forward declaration - No definition required

        // void def_req_function(ExForwardDefB &b); // Not valid with forward declaration - Definition required

        double get_var_1 ();
        void set_var_1 (double in_var_1);

        ExForwardDefA() = default;
        ExForwardDefA(double in_var_1);
        ~ExForwardDefA();
};


#endif // MACRO