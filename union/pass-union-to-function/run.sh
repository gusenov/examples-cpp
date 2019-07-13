#!/usr/bin/env bash

EXE_FILE="./program.out"

[ -f "$EXE_FILE" ] && rm "$EXE_FILE"

clang++ --std=c++11 -U__STRICT_ANSI__ \
    `find . -name "*.cpp" | tr '\n' ' '` -o "$EXE_FILE" && "$EXE_FILE"

# - [GCC 4.8.4 c++11](http://www.prog.org.ru/topic_30264_0.html)
# gcc при включенном -std=c++11 стал определять макрос __STRICT_ANSI__

# https://clang.llvm.org/docs/ClangCommandLineReference.html#compilation-flags
# -std=<arg>, --std=<arg>, --std <arg>
# Language standard to compile for

# https://github.com/llvm-mirror/clang/blob/master/include/clang/Frontend/LangStandards.def

# https://clang.llvm.org/docs/ClangCommandLineReference.html#preprocessor-flags
# -U<macro>, --undefine-macro <arg>, --undefine-macro=<arg>
# Undefine macro <macro>

# https://clang.llvm.org/docs/UsersManual.html#differences-between-various-standard-modes
# clang supports the -std option, which changes what language mode clang uses.
# The supported modes for C are c89, gnu89, c99, gnu99, c11, gnu11, c17, gnu17, and various aliases for those modes.
# If no -std option is specified, clang defaults to gnu11 mode.
# Many C99 and C11 features are supported in earlier modes as a conforming extension, with a warning.
# Use -pedantic-errors to request an error if a feature from a later standard revision is used in an earlier mode.
# Differences between all c* and gnu* modes:
#  - c* modes define “__STRICT_ANSI__”.

# https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html
# -ansi
# In C mode, this is equivalent to -std=c90. In C++ mode, it is equivalent to -std=c++98.
# …
# The macro __STRICT_ANSI__ is predefined when the -ansi option is used.
# Some header files may notice this macro and refrain from declaring certain functions or defining certain macros that the ISO standard doesn’t call for;
# this is to avoid interfering with any programs that might use these names for other things.
