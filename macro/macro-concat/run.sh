#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 main.cc -DSYSTEM_HEADERS -o "$EXE_FILE" && "$EXE_FILE"
