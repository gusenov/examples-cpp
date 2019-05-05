#!/bin/bash

EXE_FILE="./program.out"
VALGRIND_LOG="./valgrind.log"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"
[ -f "$VALGRIND_LOG" ] && rm "$VALGRIND_LOG"

g++ -Wall `find . -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" \
  && valgrind --leak-check=yes --log-file="$VALGRIND_LOG" "$EXE_FILE"

if [ -f "$VALGRIND_LOG" ]; then
  echo "Memcheck's output:"
  cat "$VALGRIND_LOG"
fi
