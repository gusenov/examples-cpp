#!/bin/bash

g++ -Wall `find . -name "*.cc" | tr '\n' ' '` -o program.out && ./program.out
