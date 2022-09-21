
#include "exercise2.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <chrono>
#include <thread>

TEST_CASE("1: Wait for condition")
{

    bool flag = false;

    std::mutex m;
    std::condition_variable cv;

    std::thread t1(ais2203::threadFunc, std::ref(m), std::ref(cv), std::ref(flag));
    std::thread t2([&] {

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        {
            std::lock_guard<std::mutex> lk(m);
            flag = true;
        }
        cv.notify_one();

    });

    if (t1.joinable()) t1.join();

    CHECK(flag);

    if (t2.joinable()) t2.join();
}
