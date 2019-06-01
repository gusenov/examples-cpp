#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

g++ -fpermissive -Wall `find . -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" \
  && "$EXE_FILE"
