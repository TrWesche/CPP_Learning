#pragma once

#ifndef __PRJ_CORO_T__
#define __PRJ_CORO_T__

#include <iostream>
#include <coroutine>
#include <exception>
#include <cassert>

template <typename T>
class PRJ_CORO_T
{
public:
    struct promise_type {
        T m_value;

        PRJ_CORO_T get_return_object() { return PRJ_CORO_T(this); }         // Return value of coroutinetype
        std::suspend_always initial_suspend() noexcept { return {}; }   // Determines if function is suspended upon first call (std::suspend_never will allow it to run at initialization which std::suspend_alwasy will not)
        std::suspend_always final_suspend() noexcept { return {}; }     // Determines if coroutine state is destroyed at last suspension point
        void unhandled_exception() {
            std::rethrow_exception(std::current_exception());
        }                                   // Handles exceptions thrown by coroutines
        void return_value(T value) {
            m_value = value;     
        } // Required for co_return v - Cannot be defined along side return_void
        // void return_void() {}           // Require for co_return
        std::suspend_always yield_value(T value) {
            m_value = value;
            return {};
        }  // Required for co_yield v
    };
    
    PRJ_CORO_T(promise_type* p)
        : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {
        std::cout << "Coroutine Constructed" << std::endl;
    };
    ~PRJ_CORO_T() {
        std::cout << "Coroutine Destroyed" << std::endl;
        m_handle.destroy();
    };

    T operator() () {
        assert(m_handle != nullptr);

        m_handle.resume();
        return (m_handle.promise().m_value);
    }

private:
    std::coroutine_handle<promise_type> m_handle;
};



#endif