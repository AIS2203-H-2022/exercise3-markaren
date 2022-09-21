
include_directories("${CMAKE_SOURCE_DIR}/include")
link_libraries(Catch2::Catch2)

if (UNIX)
  link_libraries(pthread)
endif()

add_executable(test_exercise1 test_exercise1.cpp)
add_test(NAME test_exercise1 COMMAND test_exercise1)

add_executable(test_exercise2 test_exercise2.cpp)
add_test(NAME test_exercise2 COMMAND test_exercise2)

add_executable(test_exercise3 test_exercise3.cpp)
add_test(NAME test_exercise3 COMMAND test_exercise3)
