#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 main.cc -o "$EXE_FILE" -lm && "$EXE_FILE"
