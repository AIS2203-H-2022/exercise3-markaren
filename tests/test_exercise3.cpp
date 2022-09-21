
#include "exercise3.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <vector>
#include <functional>
#include <future>
#include <chrono>


TEST_CASE("1: Parallelize tasks")
{

    int numTasks = 100;
    std::vector<std::function<void()>> tasks;
    std::vector<std::promise<int>> promises(numTasks);

    for (int i = 0; i < numTasks; i++) {

        tasks.emplace_back([i, &promises]{

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            promises[i].set_value(1);

        });

    }

    // dumb executor

    auto start = std::chrono::high_resolution_clock::now();

    ais2203::invokeTasks(tasks);

    int result = 0;
    for (auto& p : promises) {
        result += p.get_future().get();
    }

    auto stop = std::chrono::high_resolution_clock::now();

    CHECK(result == numTasks);

    promises.clear();
    promises.resize(numTasks);


    // In parallel

    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    start = std::chrono::high_resolution_clock::now();

    ais2203::invokeTasksInParallel(tasks);

    result = 0;
    for (auto& p : promises) {
        auto f = p.get_future();
        auto status = f.wait_for(std::chrono::microseconds(duration1)*1.5);
        if (status == std::future_status::timeout) break;
        result += f.get();
    }

    stop = std::chrono::high_resolution_clock::now();

    CHECK(result == numTasks);

    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    REQUIRE(duration1 > (duration2*1.5));

}
