#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

g++ `find . -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" \
  && "$EXE_FILE"
