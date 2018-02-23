#!/bin/bash

#Use this scriptinstead of builder.sh when you want to include
#debug macros DEBUG_ERROR and DEBUG_INFO into the binary.
#This is to be used only for debugging purposes.

SRC=$(find . -name *cpp)

echo "Files to be compiled:"
echo $SRC

g++ -DDEBUG -std=c++0x $SRC -o build/app_runner -I include/

#-v flag shows detailed information when compiling files
