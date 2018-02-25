#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

//This header was introuced in order to solve problems
//with different newline coding on Windows and Linux.

#if defined(_WIN64) || defined (_WIN32)

    #define PLATFORM "Windows"
    #define NEW_LINE "\r\n"

#elif defined(unix) || definde (__unix) || defined(__unix__)

    #define PLATFORM "Unix"
    #define NEW_LINE "\n"

#endif // defined

#endif // PLATFORM_H_INCLUDED
