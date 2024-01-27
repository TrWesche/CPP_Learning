#include <iostream>
#include <coroutine>
#include "PRJ_CORO.hpp"
#include "PRJ_CORO_T.hpp"

PRJ_CORO ex_func1() {
    std::cout << "Ex Func 1 - Step 1 - Suspend" << std::endl;
    co_await std::suspend_always{};
    std::cout << "Ex Func 1 - Step 2 - Suspend" << std::endl;
    co_await std::suspend_always{};
    std::cout << "Ex Func 1 - Step 3 - Suspend" << std::endl;
    co_return;
}


PRJ_CORO ex_func2() {
    std::cout << "Ex Func 2 - Step 1 - No Suspend" << std::endl;
    co_await std::suspend_never{};
    std::cout << "Ex Func 2 - Step 2 - Suspend" << std::endl;
    co_await std::suspend_always{};
    std::cout << "Ex Func 2 - Step 3 - End" << std::endl;
    co_return;
}


PRJ_CORO ex_func3() {
    std::cout << "Ex Func 3 - Step 1 - No Suspend" << std::endl;
    co_await std::suspend_never{};
    std::cout << "Ex Func 3 - Step 2 - Yield 45" << std::endl;
    co_yield 45;
    std::cout << "Ex Func 3 - Step 3 - Yield 100" << std::endl;
    co_yield 100;
    std::cout << "Ex Func 3 - Step 4 - Suspend" << std::endl;
    co_await std::suspend_always{};
    std::cout << "Ex Func 3 - Step 5 - End" << std::endl;
    co_return;
}

PRJ_CORO ex_func4() {
    int count {};
    while (true) {
        co_yield ++count;
    }
    co_return;
}

PRJ_CORO_T<size_t> ex_func5(size_t count = 0) {
    while (true) {
        co_yield ++count;
    }
    co_return count;
}



int main(){
    std::cout << "========== Coroutine Keywords ==========" << std::endl;
    std::cout << "1. co_yield: Suspends execution and returns a value which will be the function handle for resuming execution" << std::endl;
    std::cout << "2. co_return: Completes execution and optionally returns a value" << std::endl;
    std::cout << "3. co_await: Suspends execution until resumed" << std::endl;
    std::cout << "  - The presence of any of these keywords in your function will cause your function to become a coroutine" << std::endl;
    std::cout << "Limitations:" << std::endl;
    std::cout << "  - constexpr functions, constructors, destructors, and main CANNOT be coroutines" << std::endl;
    std::cout << "Note: Its generally not recommended to build custom coroutine types.  CPP 20 does not have built in coroutine types but there are libraries available and future C++ releases may include some." << std::endl;

    std::cout << "\n---- Running Example Function 1: 2 Suspend Always ----" << std::endl;
    PRJ_CORO ex_func1_handle = ex_func1();
    std::cout << "    - ex_func1 Initialized, Calling Handle" << std::endl;
    ex_func1_handle.handle();
    std::cout << "    - ex_func1 Initialized, Resuming 1" << std::endl;
    std::cout << "ex_func1_coro_done? " << ex_func1_handle.handle.done() << std::endl;
    ex_func1_handle.handle.resume(); // Resume function off of the handle seems to do the same thing as just calling the handle
    std::cout << "    - ex_func1 Initialized, Resuming 2" << std::endl;
    std::cout << "ex_func1_coro_done? " << ex_func1_handle.handle.done() << std::endl;
    ex_func1_handle.handle.resume();
    std::cout << "ex_func1_coro_done? " << ex_func1_handle.handle.done() << std::endl;


    std::cout << "\n---- Running Example Function 2: 1 Suspend Never, 1 Suspend Always ----" << std::endl;
    PRJ_CORO ex_func2_handle = ex_func2();
    std::cout << "    - ex_func2 Initialized, Calling Handle" << std::endl;
    ex_func2_handle.handle();
    std::cout << "    - ex_func2 Initialized, Resuming 1" << std::endl;
    ex_func2_handle.handle();


    std::cout << "\n---- Running Example Function 3: 1 Suspend Never, 2 Yield, 1 Suspend Always ----" << std::endl;
    PRJ_CORO ex_func3_handle = ex_func3();
    std::cout << "    - ex_func3 Initialized. m_value: " << ex_func3_handle.handle.promise().m_value << " -- Calling Handle" << std::endl;
    ex_func3_handle.handle();
    std::cout << "    - m_value: " << ex_func3_handle.handle.promise().m_value << " -- Resuming 1" << std::endl;
    ex_func3_handle.handle();
    std::cout << "    - m_value: " << ex_func3_handle.handle.promise().m_value << " -- Resuming 2" << std::endl;
    ex_func3_handle.handle();
    std::cout << "    - m_value: " << ex_func3_handle.handle.promise().m_value << " -- Resuming 3" << std::endl;
    ex_func3_handle.handle();


    std::cout << "\n---- Running Example Function 4: Yield Counter ----" << std::endl;
    PRJ_CORO ex_func4_handle = ex_func4();
    std::cout << "  - ex_func4 Initialized, m_value: " << ex_func4_handle.handle.promise().m_value << " -- Calling Handle 1" << std::endl;
    ex_func4_handle.handle();
    std::cout << "m_value: " << ex_func4_handle.handle.promise().m_value << " -- Calling Handle 2" << std::endl;
    ex_func4_handle.handle();
    std::cout << "m_value: " << ex_func4_handle.handle.promise().m_value << " -- Calling Handle 3" << std::endl;
    ex_func4_handle.handle();

    std::cout << "\n\nEND!" << std::endl;



    std::cout << "\n---- Running Example Function 5: Templatized Yield Counter ----" << std::endl;
    PRJ_CORO_T<size_t> ex_func5_handle = ex_func5();
    std::cout << "  - ex_func5 Initialized, Calling Handle 1: " << ex_func5_handle()  << std::endl;
    std::cout << "  - ex_func5 Initialized, Calling Handle 2: " << ex_func5_handle()  << std::endl;
    std::cout << "  - ex_func5 Initialized, Calling Handle 3: " << ex_func5_handle()  << std::endl;
    std::cout << "  - ex_func5 Initialized, Calling Handle 4: " << ex_func5_handle()  << std::endl;


    std::cout << "\n\nEND!" << std::endl;


   return 0;
}