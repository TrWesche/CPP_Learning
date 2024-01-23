#include "StreamInsertable.h"

using namespace TW;

std::ostream& operator << (std::ostream& os, const StreamInsertable& right)
{
    right.stream_insert(os);
    return os;
}