#include <iostream>
#include <memory>
#include "UnqPtr.h"
#include "ShrdPtr.h"


// This will implicitly move the ownership of the pointer into the function's scope.  If you don't return it the memory will be released upon exiting this functions scope.
void do_something_with_unqptr (std::unique_ptr<UnqPtr> p) {
    p->print_info();
}

// This will keep the unique pointer alive only providing a reference to the pointer in the functions scope.  Must be a const reference.
void do_something_with_unqptr_ref(const std::unique_ptr<UnqPtr>& p) {
    p->set_name("UpdatedName");
    p->print_info();
}

// The compiler will make this function work, it will return a reference instead of a copy to keep the uniqueness of the pointer
std::unique_ptr<UnqPtr> create_new_unqptr() {
    std::unique_ptr<UnqPtr> up_new = std::make_unique<UnqPtr>("NewUnqPtr");
    std::cout << "New Unique Ptr Created At: " << up_new.get() << std::endl;
    return up_new;
}



// This will create a copy of the pointer referencing the passed value's memory location. This copied pointer will only live within the functions scope.
//      Reference Count will increment
void do_something_with_shrdptr (std::shared_ptr<ShrdPtr> p) {
    p->print_info();
}

// This will pass a modifiable reference to the function allowing access to all functionalities associated with the shared pointer such as reset
//      Reference Count will not change
void do_something_with_shrdptr_ref(std::shared_ptr<ShrdPtr>& p) {
    p.reset(); // Allowed, this is a non-const reference to shared_ptr
    p->set_name("UpdatedSPName");
    p->print_info();
}

// This will pass a protected reference to the function; disallowing access to shared_ptr functionalities such as reset
//      Reference Count will not change
void do_something_with_shrdptr_const_ref(const std::shared_ptr<ShrdPtr> p) {
    // p.reset(); // Not allowed, this is a const reference to shared_ptr
    p->set_name("UpdatedSPName");
    p->print_info();
}



// The compiler will make this function work, it will return a reference to the shared pointer returned by this function to keep it within program scope
//      I.e. there is only one shared_ptr created; at no point will there be 2 references to the memory (an external and internal)
std::shared_ptr<ShrdPtr> create_new_shrdptr() {
    std::shared_ptr<ShrdPtr> sp_new = std::make_unique<ShrdPtr>("NewShrdPtr");
    std::cout << "New Shared Ptr Created At: " << sp_new.get() << std::endl;
    return sp_new;
}

// IMPORTANT
// - Do not return shared_ptrs by reference


int main(int argc, char **argv){
    // ==========================
    // Unique Pointers
    // ==========================
    UnqPtr* up_raw1 = new UnqPtr("UnqPtr1"); // Pointer Defined Elsewhere
    std::unique_ptr<UnqPtr> up_var1{up_raw1}; // Wrap the Pointer, the unique pointer takes over
    up_raw1 = nullptr; // If you do this you should no longer use the original pointer variable and us the unique ptr type going forward


    std::unique_ptr<UnqPtr> up_var2{new UnqPtr("UnqPtr2")};
    up_var2->print_info();


    std::unique_ptr<int> up_int1{new int(1000)};
    std::cout << "UP_INT1 Value Before: "  << *up_int1 << std::endl;
    *up_int1 = 200;
    std::cout << "UP_INT1 Value After: "  << *up_int1 << std::endl;
    std::cout << "UP_INT1 raw pointer lives at " << up_int1.get() << std::endl;


    std::unique_ptr<UnqPtr> up_var3{nullptr}; // Reserve space for unique pointer to manage


    std::unique_ptr<UnqPtr> up_var4 = std::make_unique<UnqPtr>("UnqPtr4"); // Gives over the "New" call to the standard library
    up_var4->print_info();


    // You cannot copy unique pointers
    // std::unique_ptr<UnqPtr> up_var5 = up_var4; // Illegal operation, no copy constructor
    // std::unique_ptr<UnqPtr> up_var6{up_var4}; // Illegal operation, no copy constructor


    // You can move ownership
    std::unique_ptr<UnqPtr> up_var7 = std::move(up_var4);
    // up_var4 will be set to nullptr
    std::cout << up_var4.get() << std::endl;
    // up_var7 now owns the memory up_var4 had previously
    std::cout << up_var7.get() << std::endl;
    up_var7->print_info();


    // You can reset pointer as well (release the memory and sets unique_ptr to nullptr)
    up_var7.reset();
    if (up_var7) {
        std::cout << "Pointer to Somewhere: " << up_var7.get() << std::endl;
    } else  {
        std::cout << "Pointer to Nowhere: " << up_var7.get() << std::endl;
    }


    // ----------------------------- Behavior with functions
    // This will not be allowed, pass by value & copy is not allowed with unique pointers
    // do_something_with_unqptr(up_var2); 

    // This works, but it transfers variable ownership of the value to the function.  
    //      I.e. up_var2 will become null pointer and the memory will be released when the function returns
    // do_something_with_unqptr(std::move(up_var2)); 

    // This will perform an implicit move so the pointer will also be released when the funtion returns
    // do_something_with_unqptr(std::make_unique<UnqPtr>("ImplicitMove"));

    do_something_with_unqptr_ref(up_var2); // This pass by reference is allowed, won't cause up_var2 to be released
    std::cout << "After function call" << std::endl;
    up_var2->print_info();


    std::unique_ptr<UnqPtr> up_var8 = create_new_unqptr();
    std::cout << "Unique Pointer Created by Function: " << up_var8.get() << std::endl;


    // ------------------------------ Unique Pointer Array
    // auto up_arr_ptr = std::unique_ptr<UnqPtr[]> (
    std::unique_ptr<UnqPtr[]> up_arr_ptr = std::unique_ptr<UnqPtr[]> (
        new UnqPtr[3]{ 
            UnqPtr("Arr_UPTR1"), 
            UnqPtr("Arr_UPTR2"), 
            UnqPtr("Arr_UPTR3")
            }
        );


    for (size_t i{}; i < 3; i++) {
        up_arr_ptr[i].print_info();
    }

    // With make Unique - You can't initialize the individual elements
    //      Once the memory is allocated though you can change the individual elements how you see fit
    auto up_arr_ptr2 = std::make_unique<UnqPtr[]>(3); 

    for (size_t i{}; i < 3; i++) {
        up_arr_ptr2[i].print_info();
    }

    // ==========================
    // Shared Pointers
    // ==========================
    // Allows multiple pointers which point to the same piece of data in memory - Maintains a reference count to the data in memory; incrementing/decrementing it dynmaically for you
    //      if the reference count goes to 0 the data in memory will be released
    std::shared_ptr<int> sp_int_1{new int(1)};

    std::cout << "The shared pointer int value is " << *sp_int_1 << std::endl;
    *sp_int_1 = 100;
    std::cout << "The shared pointer int value is now " << *sp_int_1 << std::endl;
    std::cout << "The shared pointer int value is used " << sp_int_1.use_count() << " times" << std::endl;

    std::shared_ptr<int> sp_int_1b = sp_int_1;
    std::cout << "The shared pointer int value is now used " << sp_int_1.use_count() << " times" << std::endl;

    std::cout << "The address of shared pointer int b is " << sp_int_1b << " which matches " << sp_int_1 << std::endl;
    sp_int_1b.reset();
    std::cout << "The address of shared pointer int b is now nullptr after reset: " << sp_int_1b << " but sp_int_1 still retained its target: " << sp_int_1 << std::endl;

    std::cout << "Can get the underlying pointer: "  << sp_int_1.get() << std::endl;

    if(sp_int_1b) {
        std::cout << "This won't be called if nullptr" << std::endl;
    }
    else {
        std::cout << "Can also use the shared_ptr for boolean expressions: " << static_cast<bool>(sp_int_1b) << std::endl;
    }


    // Make shared - The two statements below are equivalent
    // std::shared_ptr<ShrdPtr> sp_var_1{new ShrdPtr("SharedPointer1")};
    std::shared_ptr<ShrdPtr> sp_var_1 = std::make_shared<ShrdPtr>("SharedPointer1");
    // Note: There is partial support for make_shared with arrays, but it should not be regularly needed


    // Arrays - Note: Default constructor will be used for uninitialized vars
    std::shared_ptr<ShrdPtr[]> sp_arr_ptr1(new ShrdPtr[5]{ShrdPtr("NewArraySP1"), ShrdPtr("NewArraySP2")});
    for (size_t i = 0; i < 5; i++)
    {
        sp_arr_ptr1[i].print_info();
    }

    sp_arr_ptr1[4] = ShrdPtr("UpdatedArrSP5");

    std::cout << "Updating a location within the array" << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        sp_arr_ptr1[i].print_info();
    }


    // ----------------------
    // Move from Unique Point to Shared Pointer
    // ----------------------
    // Creating unique pointers to be used
    std::unique_ptr<int> mov_me_uptr_1 = std::make_unique<int>(100);
    std::unique_ptr<UnqPtr> mov_me_uptr_2 = std::make_unique<UnqPtr>("MoveThisPointer");

    // Moved the unique pointers to be managed by a shared pointer
    std::shared_ptr<int> movd_sptr_1 = std::move(mov_me_uptr_1);
    std::shared_ptr<UnqPtr> movd_sptr_2 = std::move(mov_me_uptr_2);

    // Not allowed to move a shared pointer to a unique pointer



    // ==========================
    // Weak Pointers
    // ==========================
    //      - Pointers which do not own the data they are referencing, if the pointer goes out of scope the data it is pointing to is not affected
    //      - These do not implement the deferencing (*) or pointer access (->) operators.  They cannot be used directly to read or modify data
    std::shared_ptr<ShrdPtr> weak_ptr_src1 = std::make_shared<ShrdPtr>("WeakPtrSource1");
    std::weak_ptr<ShrdPtr> weak_ptr_1 (weak_ptr_src1);

    // The weak pointer cannot be used directly.  To use you need to use the .lock method to turn it into a shared pointer
    std::shared_ptr<ShrdPtr> weak_ptr_locked_1 = weak_ptr_1.lock();
    weak_ptr_locked_1->print_info();

    // ----------------------
    // Use Case for the Weak Pointer -- Cyclic Dependencies :: Look at Person Class

    return 0;
}