
#include "exercise1.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

TEST_CASE("1: increment and decrement")
{

    unsigned int numThreads = std::thread::hardware_concurrency();

    std::mutex m;
    std::condition_variable cv;

    bool ready = false;
    ais2203::atomic_int ai{0};

    std::vector<std::thread> threads(numThreads);
    for (int i = 0; i < numThreads; i++) {
        threads.emplace_back(std::thread([&] {

            {
                // wait for all threads to be ready
                std::unique_lock<std::mutex> lk(m);
                cv.wait(lk, [&]{return ready;});
            }

            for (int j = 0; j < 1000000; j++) {
                ai.increment();
                ai.decrement();
            }

        }));
    }

    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
    }
    cv.notify_all();

    for (auto& thread : threads) {
        if (thread.joinable()) thread.join();
    }

    REQUIRE(ai.get() == 0);
}
