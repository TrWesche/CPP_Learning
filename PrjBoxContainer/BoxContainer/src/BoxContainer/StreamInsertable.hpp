#ifndef STREAM_INSERTABLE_H
#define STREAM_INSERTABLE_H

#include <iostream>

namespace TW {

class StreamInsertable
{
    friend std::ostream& operator << (std::ostream& os, const StreamInsertable& operand);
public:
    virtual void stream_insert(std::ostream& os) const = 0;
};

}

#endif