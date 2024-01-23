# Container Types:

## Sequence Containers:
- std::deque  (Double Ended Queue)
    - Fast Insertions and Removals from both ends of the container
    - Not contiguous in memory
    - Doesn't require any element to be copied or moved
    - Never invalidates pointers/references to other elements in the collection
    - Supports random access operators (ex. [])
- std::forward_list
    - Fast Insertions and Removals anywhere in the container (even in middle)
    - Single Linked List, i.e. can only be traversed in the forward direction
    - Non Contiguous Storage (Optimizations for CPU are limited, i.e. slow compared to contiguous storage)
    - No Random Access Operators
- std::list
    - Fast Insertions and Removed anywhere in the container (even in middle)
    - Double Linked List, i.e. can be travered both forwards and backwards
    - Non Contiguous Storage (Optimizations for CPU are limited, i.e. slow compared to contiguous storage)
    - No Random Access Operators
- std::vector
    - Fast Item Retrievals with [] operator
    - Contiguous Storage
    - Forward & Reverse Iterators
    - Adding Elements to Back is Fast
    - Adding Elements to Front/Middle Are Slow/Expensive
- std::array
    - Fixed Size Container
    - Fast Item Retrievals with [] operator
    - Contiguous Storage
    - Forward & Reverse Iterators

## Associative Containers: (Store data by key & value - depending on how things are defined the key can be used for ordering)
- std::pair (Base Type Used by Associative Containers)
    - Groups 2 data components as a single entity
- std::set
    - Fast Search for Elements
    - Built on a Binary Search Tree (red black)
    - Ordered
        - STD Set will order elements for you as they are inserted
            - Note: This requries what is inserted to implement the "Less Than" Operator (Can also just implement the 3 way comparison operator since this creates the less than at compile time)
        - A callback can also be used to order things
    - Element keys must be unique
        - Duplicate is determined using the less than operator, not the == operator ( i.e. !(x < y) && !(x > y) )
- std::map
    - Fast Search for Elements
    - Built on a Binary Search Tree (red black)
    - Key & Value are explicitly defined
    - Ordered
        - STD Set will order elements for you as they are inserted
            - Note: This requries what is inserted to implement the "Less Than" Operator (Can also just implement the 3 way comparison operator since this creates the less than at compile time)
        - A callback can also be used to order things
    - Element keys must be unique
        - Duplicate is determined using the less than operator, not the == operator ( i.e. !(x < y) && !(x > y) )
- std::multiset & std::multimap
    - Allow duplicates in the collection
    - Ordered
- std::unordered_set
    - Use Hash Maps for Storing Data for Faster Operation then regular set; ordering is not human readable though
        - You can provide your own hash map to control how things are ordered
- std::unordered_map
    - Use Hash Maps for Storing Data for Faster Operation then regular set; ordering is not human readable though
        - You can provide your own hash map to control how things are ordered

## Container Adaptors (Specializations of Sequence Containers):
- std::stack
    - LIFO
    - Can be built on top of list, vector, or deque.
        - deque = default
    - Requires the following methods on the underlying container: back(), push_back(), pop_back()
    - "top" method provieds access to the last element by reference (i.e. you could use it to modify the value)
    - "pop" will remove the last element (note, does not return anything and comes from the underlying container)
    - "emplace", "push", "push_range (C++ 20)" adds the stack
- std::queue
    - FIFO
    - Can be built on top of list, deque.
        - deque = default
- std::priority_queue
    - Puts thing in FIFO order, but with additional prioritization based on specialized conditions
    - Can be built on top of vector, deque.
        - vector = default


Vector:Data is continguous in memory

Array: Data is contiguous in memory

Dict:

List: Data is not contiguous in memory, instead it using the linking on the list