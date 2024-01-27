# Minimum CMake version required
cmake_minimum_required(VERSION 3.22)

# Project name
project(unitTesting)

# Create an executable with main.cpp and stack.cpp as sources
add_executable(program src/main.cpp src/stack.cpp)

# Enable testing
enable_testing()

# Create an executable for tests using tests.cpp and stack.cpp
add_executable(tests src/tests.cpp src/stack.cpp)

# Find and include GTest library
find_package(GTest REQUIRED)

# Link the 'tests' executable against the GTest library
target_link_libraries(tests GTest::gtest_main)

# Include GoogleTest for CMake configuration
include(GoogleTest)

# Discover tests for the 'tests' executable
gtest_discover_tests(tests)
