#pragma once

#ifdef _WIN32
    #ifdef TESTS_EXPORTS
        #define TESTS_API __declspec(dllexport)
    #else
        #define TESTS_API __declspec(dllimport)
    #endif
#else
    #define TESTS_API  // Пустое для остальных
#endif

namespace tests{
    TESTS_API void XXXXX();
}