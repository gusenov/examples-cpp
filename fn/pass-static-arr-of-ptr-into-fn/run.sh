#!/usr/bin/env bash

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

# clang++ --std=c++17 main.cc -o "$EXE_FILE" && "$EXE_FILE"
g++ -std=gnu++17 -Wall main.cc -o "$EXE_FILE" && "$EXE_FILE"
