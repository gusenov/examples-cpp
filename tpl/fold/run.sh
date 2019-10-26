#!/bin/bash

g++ -std=c++17 -Wall `find . -name "*.cc" | tr '\n' ' '` -o program.out && ./program.out
