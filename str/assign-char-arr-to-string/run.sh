#!/bin/bash

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

export PATH="/usr/local/opt/llvm/bin:$PATH"
which clang++

clang++ --std=c++17 \
    `find . -maxdepth 1 -name "*.cc" | tr '\n' ' '` -o "$EXE_FILE" \
    && ASAN_OPTIONS=detect_leaks=1 \
 && "$EXE_FILE"
