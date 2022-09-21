cmake_minimum_required(VERSION 3.15)
project(ais2203_exercise3)

set(CMAKE_CXX_STANDARD 17)

# Download Catch2 unit-test framework
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_subdirectory(tests)
