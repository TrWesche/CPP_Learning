#include "StreamInsertable.hpp"

namespace TW {

std::ostream& operator << (std::ostream& os, const StreamInsertable& operand)
{
    operand.stream_insert(os);
    return os;
}

}