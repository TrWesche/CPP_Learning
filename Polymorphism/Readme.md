Concept:
- Using base class pointers/references to manage derived classes
- Can use it to store different types of objects in a single collection

Way to Use:
- Relies on method overrides to execute the proper functionality depending on the derived class

Override & Virtual Annotations/Identifier:
- Virtual marks a method for dynamic resolution meaning the type of the underlying class will be used for determining what code to call.  Without virtual the resultion of the method will be static meaning it will use the type of most primitive class:
    - I.e. If you have a class Oval which Inherits from Shape, if you have a method defined both in Oval and Shape but do not use the virtual annotation if you call that oval object method from a Shape pointer the shape's implementation of the method will be used.
- Override is used to validate that a method is being overwritten by the class method as intended.
    - Note: Override is not a keyword, it is a compiler feature used for validating implementation.

Final Annotation/Identifier:
- Classes & Methods can be marked as final which means downstream classes / methods cannot overwrite or inherit from them
    - Note: Final is not a keyword, it is a compiler feature used for validating implementation.


Virtual Function Accessibility
- You can change the scope of your method overrides to be more restrictive in derived classes.  The opposite is not true.
    - Recommendation: Limit accessibility to minimum unless you determine addition access is necessary.


Default Argument Behaivor
- The base class default arguments are always used when Polymorphic functions are called.  Default arguments are handled at compile time vs. polymorphic calls which are handled at runtime.
    - Recommendation: Don't use default arguments