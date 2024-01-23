// Whats the difference between Struct & Class?
//      - Member Variables of a Struct are Public by Default, while for a Class they are Private.
// Typically a struct will be used for a class which has only public member variables.  Otherwise just use class.
#include <string>

struct ExStruct {
    std::string name;
};