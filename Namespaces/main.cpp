#include <iostream>
#include "basic-math.h"
#include "basic-math-adj.h"
#include "Point.h"
#include "nested-namespaces.h"


using namespace Geo;
using std::cout; // Its not recommended to bring in the full std namespace.  If you want to bring something in do it this way

// Anonymous Namespace Declaration
//          - Note: These namespaces do not exist globally.  I.e. The anonymous namespace will be given a random name during compilation and will not
//                   be common across all anonymous namespace definitions; as a general rule they will not exist outside of a single cpp file (really tied to the translation unit)
namespace {
    double add_anon(double a, double b);
}


double add(double a, double b) {
    return a + b;
}

int main(int argc, char **argv){
    std::cout << Basic_Math::add(1, 2) << std::endl;

    cout << Basic_Math_Adj::add(1, 2) << std::endl;

    Point p1(2, 3); // This now works because of the "using namespace Geo"
    Geo::Point::print_point_info(p1);

    // Global Namespace (::) - Don't need to use it
    std::cout << ::add(1, 2) << std::endl; // :: is the default global namespace identifier

    // Anonymous Namespace
    std::cout << add_anon(3,4) << std::endl;

    // Nested Namespace
    hello::do_something_else();
    hello::world::do_something();

    // Namespace Alias
    namespace data = hello::world;
    std::cout << "Aliased Namespace Variable: " << data::weight << std::endl;

    return 0;
}


// Anonymous Namespace - Definition
namespace {
    double add_anon(double a, double b)
    {
        return a + b;
    }
}
