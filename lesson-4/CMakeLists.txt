cmake_minimum_required(VERSION 3.10)

project(lesson4)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lesson4 test1.cpp)
target_link_libraries(lesson4 ${GTEST_BOTH_LIBRARIES} pthread)
add_test(NAME lesson4 COMMAND ${PROJECT_NAME})
