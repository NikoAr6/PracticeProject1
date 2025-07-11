#include <iostream>
#include "utils.h"
#include "core.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);  // установка utf8 для консоли в случае win
    #endif
    std::cout << core::base_function() << std::endl << utils::utility_function() << std::endl
        << " Я цитирую цитату цитаты:\"" << utils::utility_function() << "\"" << std::endl;
    std::cin.get();
    return 0;
}