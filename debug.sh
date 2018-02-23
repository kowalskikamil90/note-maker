#!/bin/bash

SRC=$(find . -name *cpp)

echo "Files to be compiled:"
echo $SRC

g++ -DDEBUG -std=c++0x $SRC -o build/app_runner -I include/

#-v flag shows detailed information when compiling files
