#include "Summable.h"

using namespace TW;

Summable& operator+=(Summable& left, const Summable& right) {
    left.add_and_update(right);
    return left;
}

Summable& operator+(const Summable& left, const Summable& right) {
    Summable& sumResult = left.add_create_new(right);
    return sumResult;
}