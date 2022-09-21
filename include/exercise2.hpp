
#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include <mutex>
#include <condition_variable>

namespace ais2203
{

void threadFunc(std::mutex &m, std::condition_variable &cv, bool &flag) {

    std::unique_lock<std::mutex> lck(m);
    while (!flag) {
        cv.wait(lck);
    }

}

} // namespace ais2203


#endif // EXERCISE2_HPP
