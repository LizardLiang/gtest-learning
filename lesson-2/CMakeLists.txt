cmake_minimum_required(VERSION 3.10)

project(lession1)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test1 test1.cpp)
target_link_libraries(test1 ${GTEST_BOTH_LIBRARIES} pthread)
add_test(NAME test1 COMMAND test1)
