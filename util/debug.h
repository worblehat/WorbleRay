#ifndef DEBUG_H
#define DEBUG_H

#ifdef WORBLERAY_DEBUG
    #include <iostream>
    #define D(x) std::cout << x
#else
    #define D(x)
#endif

#endif // DEBUG_H
