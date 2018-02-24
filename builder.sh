#!/bin/bash

SRC=$(find src/ -name *cpp)

echo "Files to be compiled:"
echo $SRC

g++ -std=c++0x $SRC -o build/app_runner -I include/

#-v flag shows detailed information when compiling files
