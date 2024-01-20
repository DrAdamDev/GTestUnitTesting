#!/bin/bash

rm -rf build

cmake -S . -B build >> .build.log 2>&1 || { cat .build.log; exit 1; }

cmake --build build > .build.log 2>&1 || { cat .build.log; exit 1; }

./build/program "$@" 2>&1 | tee -a .buid.log || { cat .build.log; exit 1; }
