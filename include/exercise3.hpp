
#ifndef TEST_EXERCISE_EXERCISE3_HPP
#define TEST_EXERCISE_EXERCISE3_HPP

#include <algorithm>
#include <execution>
#include <functional>
#include <thread>
#include <vector>

namespace ais2203
{

void invokeTasks(std::vector<std::function<void()>>& tasks)
{
    for (auto& t : tasks) {
        t();
    }
}

void invokeTasksInParallel(std::vector<std::function<void()>>& tasks)
{
    //    std::vector<std::thread> threads;
    //
    //    for (const auto& task : tasks) {
    //        std::thread t(task);
    //        threads.emplace_back(std::move(t));
    //    }
    //
    //    for (auto& t : threads) {
    //        if (t.joinable()) {
    //            t.join();
    //        }
    //    }

    std::for_each(std::execution::par, tasks.begin(), tasks.end(), [](auto t) {
        t();
    });
}

} // namespace ais2203

#endif // TEST_EXERCISE_EXERCISE3_HPP
