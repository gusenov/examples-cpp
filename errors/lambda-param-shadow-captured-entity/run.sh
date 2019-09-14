#!/bin/bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

# export PATH="/usr/local/opt/llvm/bin:$PATH"

clang++ --version

#   КОМПИЛИРУЕТСЯ:
# Apple LLVM version 10.0.1 (clang-1001.0.46.4)
# Target: x86_64-apple-darwin18.5.0
# Thread model: posix
# InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin

#   НЕ КОМПИЛИРУЕТСЯ:
# clang version 8.0.0 (tags/RELEASE_800/final)
# Target: x86_64-apple-darwin18.5.0
# Thread model: posix
# InstalledDir: /usr/local/opt/llvm/bin

clang++ --std=c++17 main.cpp -o "$EXE_FILE" && "$EXE_FILE"
