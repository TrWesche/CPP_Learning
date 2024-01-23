#if !defined(EXFORWARDDEFB_H)
#define EXFORWARDDEFB_H

#include <iostream>

class ExForwardDefB {
    private:
        double m_var_1 {};

    public:
        double get_var_1 ();
        void set_var_1 (double in_var_1);

        void print_info() const;

        ExForwardDefB() = default;
        ExForwardDefB(double in_var_1);
        ~ExForwardDefB();
};


#endif // MACRO