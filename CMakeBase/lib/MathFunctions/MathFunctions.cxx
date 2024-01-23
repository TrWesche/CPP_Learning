#include "MathFunctions.h"

#include <cmath>

#ifdef USE_CUSTOMMATH 
#   include "mysqrt.h"
#endif

namespace mathfunctions {
  double sqrt(double x)
  {
    #ifdef USE_CUSTOMMATH
      return detail::mysqrt(x);
    #else
      return sqrt(x);
    #endif
  }
}
