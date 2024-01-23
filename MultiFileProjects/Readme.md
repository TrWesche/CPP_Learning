Can split the compilation into two steps:
1. Compilation
   - Preprocessing (Resolve includes)
   - Compilation (Create Binaries)
2. Linking
    - Combine into single binary


Commands:
- Compile and Link: g++ -o template.exe main.cpp utilities.cpp
    - Output: Executable Binary
- Compile Only: g++ -c main.cpp utilities.cpp
    - Output: Pair of Object File
- Link Object Files: g++ -o template.exe main.o utilities.o



Linkage:
- None: Function Scoped Variables
- Internal: Const Variables, only accessible in a single TU / CPP File
    - To make something internal only, mark it with static or wrap it with an anonymous namespace:
        - Example (static): static void some_function() {};
        - Example (anon namespace): namespace { void some_function() {};};
- External: Global Variables (non-const), Functions
    - For Variables access with: "extern"; This accesses a value defined in another translation unit, will tell the compiler the variable in this scope is only a declaration.
        - Example: extern int item_count;
    - To make a constant accessible externally:
        - Example: extern const double something {12.3};
- Module 



Inline:
- Used to control the scope of a variable / function to a single translation unit (cpp file)
- When marked as "inline" the compiler will unify all repeated definitions of a function so that only one logically exists.
    - Useful if you want to create a Header file only library where the declarations and definitions are in a single file.
    - Note: If you need to do this it is more efficient then using static/anonymous namespaces.
        - Inline will result in a single definition
        - Static/Anonymous Namespace will result in multiple definitions


Forward Declaration:
- Used to decouple classes:
    - For example instead of including a header for for a class to be used by another you can provide a declaration of the class so there is no longer a dependency between the two.