#!/bin/bash

SRC=$(find src/ -name *cpp)

echo "Files to be compiled:"
echo $SRC

g++ -std=c++0x $SRC -o build/app_runner -I include/

if [ $? -eq 0 ] ; then
    echo "BUILD SUCCESSFULL"
else
    echo "BUILD FAILED"
fi

#-v flag shows detailed information when compiling files
