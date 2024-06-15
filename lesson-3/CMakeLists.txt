cmake_minimum_required(VERSION 3.10)

project(lesson3)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lesson3 test1.cpp)
target_link_libraries(lesson3 ${GTEST_BOTH_LIBRARIES} pthread)
add_test(NAME lesson3 COMMAND ${PROJECT_NAME})
