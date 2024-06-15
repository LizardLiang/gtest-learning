cmake_minimum_required(VERSION 3.10)

project(lesson2)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} test1.cpp)
target_link_libraries(test1 ${GTEST_BOTH_LIBRARIES} pthread)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
