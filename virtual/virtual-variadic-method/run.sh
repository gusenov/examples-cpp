#!/bin/bash

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ -Weverything \
        -Wno-weak-vtables \
        -Wno-c++98-compat \
        --std=c++17 \
        main.cc -o "$EXE_FILE" && "$EXE_FILE"
