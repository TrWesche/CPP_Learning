#pragma once

#ifndef __PRJ_CORO__
#define __PRJ_CORO__

#include <iostream>
#include <coroutine>
#include <exception>

// Awaitables: The Standard Library Supplies suspend_never and suspend_always.  
//You can make a custom awaitable though by defining a struct with the following parameters
struct suspend_custom {
    constexpr bool await_ready() const noexcept { return true; } // Returns boolean where true = do not suspend, and false = suspend.  await_suspend is called for the false case
    constexpr void await_suspend(std::coroutine_handle<>) const noexcept {} // May suspend the coroutine or schedule the state for destruction
    constexpr void await_resume() const noexcept {} // May return the result of the entire co_await expression
};
// Or you can implement the co_await operator in a class
struct Custom_Awaitable {
    auto operator co_await() {return std::suspend_always {}; }  
};




class PRJ_CORO
{
public:
    struct promise_type {
        int m_value {};

        PRJ_CORO get_return_object() { return PRJ_CORO(this); }         // Return value of coroutinetype
        std::suspend_always initial_suspend() noexcept { return {}; }   // Determines if function is suspended upon first call (std::suspend_never will allow it to run at initialization which std::suspend_alwasy will not)
        std::suspend_always final_suspend() noexcept { return {}; }     // Determines if coroutine state is destroyed at last suspension point
        void unhandled_exception() {
            std::rethrow_exception(std::current_exception());
        }                                   // Handles exceptions thrown by coroutines
        // void return_value(int value) {
        //     m_value = value;     
        // } // Required for co_return v - Cannot be defined along side return_void
        void return_void() {}           // Require for co_return
        std::suspend_always yield_value(int value) {
            m_value = value;
            return {};
        }  // Required for co_yield v
    };
    
    PRJ_CORO(promise_type* p)
        : handle(std::coroutine_handle<promise_type>::from_promise(*p)) {
        std::cout << "Coroutine Constructed" << std::endl;
    };
    ~PRJ_CORO() {
        std::cout << "Coroutine Destroyed" << std::endl;
        handle.destroy();
    };

    std::coroutine_handle<promise_type> handle;
private:
    /* data */
};



#endif