#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++11 -U__STRICT_ANSI__ \
    `find . -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" && "$EXE_FILE"
