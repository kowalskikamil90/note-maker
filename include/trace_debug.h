#ifndef TRACE_DEBUG_INFO_H
#define TRACE_DEBUG_INFO_H

#include <iostream>

#define DEBUG_ERROR(string) (std::cout << "### DEBUG ERROR: " << (string) << std::endl;)
#define DEBUG_INFO(string) (std::cout << "### DEBUG INFO: " << (string) << std::endl;)

#endif //#ifndef TRACE_DEBUG_INFO_H
