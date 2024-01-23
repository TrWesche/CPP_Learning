#include "Box.h"

void some_func () {
    Box b1{2};
    Box b2{3};

    Box boxes[] = {b1, b2}; // The boxes stored in this array will be copies, not references to the original objects


    // Range based for loops will create copies if you initialize them like this
    for (Box box : boxes) {
        box.print_info();
    }

    // Using the reference though will prevent the creation of copies
    for (Box& box : boxes) {
        box.print_info();
    }

    // Standard for loops will always access the original component
    for (size_t i {}; i < std::size(boxes); i++)
    {
        boxes[i].print_info();
    }
}