#ifndef TRACE_DEBUG_INFO_H
#define TRACE_DEBUG_INFO_H

#include <iostream>
#include <string>

/*
This header is only for debugging purposes.
It should not be used in production code.

Set the DEBUG flag in the compiler, when debugging the program:

g++ -DDEBUG ......

*/

#ifdef DEBUG

    #define DEBUG_ERROR(str) (std::cout << "### DEBUG ERROR: " << (str) << std::endl);
    #define DEBUG_INFO(str) (std::cout << "### DEBUG INFO: " << (str) << std::endl);
    #define DEBUG_INFO_2(op1, op2) (std::cout << "### DEBUG INFO: " << (op1) << (op2) << std::endl);

#else

    #define DEBUG_ERROR(str) ;
    #define DEBUG_INFO(str) ;
    #define DEBUG_INFO_2(op1, op2) ;

#endif // DEBUG

#endif //#ifndef TRACE_DEBUG_INFO_H
