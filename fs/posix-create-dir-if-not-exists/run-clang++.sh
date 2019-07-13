#!/usr/bin/env bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++17 \
    `find . -name "*.cpp" -maxdepth 1 | tr '\n' ' '` -o "$EXE_FILE" && "$EXE_FILE"

# На Ubuntu Linux выдаст предупреждение:
# find: предупреждение: вы указали параметр -maxdepth после аргумента без параметра -name, 
# а параметры не являются позиционными (-maxdepth влияет на тесты указанные как перед ним, так и после него). 
# Указывайте параметры перед другими аргументами.

