#!/bin/bash

export PATH="/usr/local/opt/llvm/bin:$PATH"
which clang

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ -fsanitize=address \
        -fsanitize=undefined \
        --std=c++17 main.cc \
        -o "$EXE_FILE" \
&& ASAN_OPTIONS=detect_leaks=1 "$EXE_FILE"
