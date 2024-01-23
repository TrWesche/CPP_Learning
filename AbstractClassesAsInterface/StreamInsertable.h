#pragma once

#include <iostream>

class StreamInsertable
{
    friend std::ostream& operator << (std::ostream& os, const StreamInsertable& operand);

private:
    /* data */
public:
    virtual void stream_insert(std::ostream& os) const = 0;
};
