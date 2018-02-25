#!/bin/bash

#Use this script instead of builder.sh when you want to include
#debug macros DEBUG_ERROR and DEBUG_INFO into the binary.
#This is to be used only for debugging purposes.

SRC=$(find src/ -name *cpp)

echo "Files to be compiled:"
echo $SRC

#Make is not used since there are only several files in the project.
g++ -DDEBUG -std=c++0x $SRC -o build/app_runner -I include/

if [ $? -eq 0 ] ; then
    echo "BUILD SUCCESSFULL"
else
    echo "BUILD FAILED"
fi

#-v flag shows detailed information when compiling files
