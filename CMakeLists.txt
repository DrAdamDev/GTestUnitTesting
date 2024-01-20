cmake_minimum_required(VERSION 3.22)

project(unitTesting)

# Add sources
add_executable(program main.cpp stack.cpp)

enable_testing()

# Add test executable
add_executable(tests tests.cpp stack.cpp)

# Making GTest library discoverable
find_package(GTest REQUIRED)

# Link against GTest library
target_link_libraries(tests GTest::gtest_main)

# CMake specific config
include(GoogleTest)

gtest_discover_tests(tests)
