#!/bin/bash

EXE_FILE="./a.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

g++ -std=gnu++17 -Wall `find . -name "*.cc" | tr '\n' ' '` -o "$EXE_FILE"
