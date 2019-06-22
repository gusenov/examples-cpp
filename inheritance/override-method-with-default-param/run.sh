#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ -Woverloaded-virtual --std=c++11 \
    `find . -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" && "$EXE_FILE"
