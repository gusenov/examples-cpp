#!/usr/bin/env bash

# https://stackoverflow.com/questions/21870283/how-to-get-list-of-supported-standards-in-clang

touch dummy.cpp

clang -std=dummy dummy.cpp &> list-of-supported-standards-in-clang.txt
# https://stackoverflow.com/questions/637827/redirect-stderr-and-stdout-in-bash

rm dummy.cpp
