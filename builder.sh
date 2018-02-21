#!/usr/bin/bash

SRC=$(find . -name *cpp)

echo "Files to be compiled:"
echo $SRC

g++ -std=c++11 $SRC -o build/app_runner -I include/

#-v flag shows detailed information when compiling files
