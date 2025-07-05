#include <iostream>
#include "core.h"
#include "utils.h"
#ifdef _WIN32
#include <windows.h>
#endif

namespace utils{
    std::string utility_function(){
        #ifdef _WIN32
            SetConsoleOutputCP(CP_UTF8);  // установка utf8 для консоли в случае win
        #endif
        return " Я цитирую цитату:\"" + core::base_function() + "\" ";
    }
}