Types:
- Unary
    - Take 1 Operand
    - Can overload as member & non-member functions
        - Member: ReturnType operator X ();
        - Non-Member: ReturnType operator X (Type operand);
- Binary
    - Take 2 Operands
    - Can overload as member & non-member functions
        - Member: ReturnType operator X (Type right_operand);
        - Non-Member: ReturnType operator X (Type left_operand, Type right_operand);


Some Operand Operators
a++
a--
a+b
a-b


Operand Behavior:
- The Operator is called on the "first" operand.
    - As an example: A + B
        - Operator from A is used for this operation
    - This is important for implicit conversions if your operator overload is implemented as a member function (i.e. where the first variable is always "this")
        - In general implement the overloads as non-member friend functions