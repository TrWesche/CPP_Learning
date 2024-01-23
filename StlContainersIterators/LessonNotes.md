Iterator Types:
Input - RValue, Read things from the container, Copy
    - No ++ Operator
Output - LValue, Use to put data back into container, Reference/Pointer
    - No ++ Operator
Forward
    - Can Move Forward in a Container
Bidirectrional
    - Can Move Forward or Backward
Random Access
    - Can access ranges non-sequentially
Contiguous Iterator (C++ 20): 
    - Provides guarantee the denoted elements are stored contiguously in memory