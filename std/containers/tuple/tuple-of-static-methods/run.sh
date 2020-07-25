#!/bin/bash

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 main.cc SomethingConcrete.cc Factory.cc -o "$EXE_FILE" && "$EXE_FILE"
