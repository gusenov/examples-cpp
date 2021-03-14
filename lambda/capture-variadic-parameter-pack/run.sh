#!/usr/bin/env bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

g++ -std=gnu++17 -Wall main.cpp -o "$EXE_FILE" && "$EXE_FILE"
