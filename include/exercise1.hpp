
#ifndef EXERCISE1_HPP
#define EXERCISE1_HPP

/*
 * The code in found here is not thread-safe. The test spawns multiple threads that concurrently calls increment and decrement.
 * Each thread calls `increment` and `decrement` an equal number of times. The initial value of 'value' is set to 0 by the test.
 * You'd think that the value of `value` should still be `0` after all threads have executed,
 * but this is not necessarily the case. This is due to the fact that `--` and `++` are not atomic operations.
 *
 * Task: Modify the class so that only one thread is able to modify `value` at any given time.
 */

namespace ais2203
{

class atomic_int
{
public:
    explicit atomic_int(int value)
        : value(value)
    { }

    void increment()
    {
        value++;
    }

    void decrement()
    {
        value--;
    }

    [[nodiscard]] int get() const
    {
        return value;
    }

private:
    int value;
};

} // namespace ais2203


#endif // EXERCISE1_HPP
