#!/bin/bash

# Define absolute path
path="/home/dradamdev/Projects/C++Projects/unitTesting"

# Go to project root
cd $path || exit 1

# Remove build directory
rm -rf build/

# Generate build files, redirect std::out to build together with std::err
cmake -S . -B build >> .build.log 2>&1 || { cat .build.log; exit 1; }

cmake --build build > .build.log 2>&1 || { cat .build.log; exit 1; }

cd build/ || exit 1

ctest | tee -a .test.log 2>&1 || { cat .test.log; exit 1; }

cd "$path"/ || exit 1

./build/program "$@" 2>&1 | tee -a .build.log || { cat .build.log; exit 1; }
