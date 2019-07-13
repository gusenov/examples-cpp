#!/usr/bin/env bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 \
    `find . -name "*.cpp" -maxdepth 1 | tr '\n' ' '` -o "$EXE_FILE" && "$EXE_FILE"
