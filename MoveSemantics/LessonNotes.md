Value Types:
- LValues: Long Lived values which you can grab the address of and use at a later time
- RValues: Transient/Temporary values which only exist for a short time and are released by the system when they are no longer needed



!! Important
If an rvalue is assigned to a variable it will be treated as an lvalue going foward.  I.e. if the intent was to use the rvalue to instantiate move constructor/assigment calls it will no longer operate as expected and will cause the copy constructor/assigment operator to be instantiated.