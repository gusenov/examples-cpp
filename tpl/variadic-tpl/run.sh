#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 `find . -maxdepth 1 -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" && "$EXE_FILE"
