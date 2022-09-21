
#ifndef EXERCISE2_HPP
#define EXERCISE2_HPP

#include <mutex>
#include <condition_variable>

#include <iostream>

namespace ais2203
{

void threadFunc(std::mutex &m, std::condition_variable &cv, bool &flag) {

    // TODO: Block the calling thread until flag == true
}

} // namespace ais2203


#endif // EXERCISE2_HPP
