#ifndef LOG_H
#define LOG_H

#include <iostream>

#ifdef WORBLERAY_DEBUG
    #define DEBUG(x) std::cout << "DEBUG: " << x << std::endl;
#else
    #define DEBUG(x)
#endif

#define INFO(x) std::cout << "INFO: " << x << std::endl;
#define ERROR(x) std::cout << "ERROR: " << x << std::endl;

#endif // LOG_H
