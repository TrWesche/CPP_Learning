Smart Pointers:
- Added in C++ to help alleviate the problems with manually releasing memory with the delete operator
    - Missing deletes causes memory leaks, this is a big issue in large projects

- Library: <memory>
    - These are wrappers for the pointer type:
        - std::unique_ptr
            - Only one pointer can be managing the memory at any time
            - Memory is automatically released when pointer goes out of scope
        - std::shared_ptr
        - std::weak_ptr