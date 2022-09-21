
#ifndef TEST_EXERCISE_EXERCISE3_HPP
#define TEST_EXERCISE_EXERCISE3_HPP

#include <functional>
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
    // TODO: Beat the performance of "invokeTasks" by parallelizing the execution of the tasks
    // You need to be at least 1.5x faster than "invokeTasks". GO!
    invokeTasks(tasks); // <--- placeholder implementation. Replace with a faster (parallel) implementation
}

} // namespace ais2203

#endif // TEST_EXERCISE_EXERCISE3_HPP
