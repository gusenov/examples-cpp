#!/bin/bash

g++ -Wall `find . -name "*.h" -or -name "*.cpp" | tr '\n' ' '` -o program.out && ./program.out
