# ais2203-exercise3

### Exercise 1

The class in `include/exercise1.hpp` is not thread safe. The test spawns multiple threads that concurrently calls increment and decrement. 
Each thread calls `increment` and `decrement` an equal number of times. The value of the passed in `value` is set to `0` by the test. 
You'd think that the value of `value` should still be `0` after all threads have executed, 
but this is not necessarily the case. This is due to the fact that `--` and `++` are not atomic operations.

Modify the class so that only one thread is able to modify `value` at any given time.

### Exercise 2

Implement the following logic within the function defined inside `include/exercise2.hpp`:

Block the calling thread until `ready==true`. I.e., as long as `ready==false` the function should not return.

### Exercise 3

Beat the performance of "invokeTasks" function in `include/exercise3.hpp` by parallelizing the execution of the tasks.
Leave `invokeTasks` unchanged. Implement your changes in `invokeTasksInParallell`.
You need to be at least 1.5x faster than "invokeTasks". GO!

<br>
