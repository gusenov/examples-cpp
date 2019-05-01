#!/bin/bash

g++ -Wall `find . -name "*.cpp" | tr '\n' ' '` -o program.out && ./program.out
