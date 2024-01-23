const double adjustment = 1;

namespace Basic_Math_Adj {
    double add (double x, double y);
    double sub (double x, double y);
}

// Could put this in a separate file
namespace Basic_Math_Adj {
    double add (double x, double y) {
        return x + y - adjustment;
    }

    double sub (double x, double y) {
        return x - y - adjustment;
    }
}
