#include <catch2/catch_test_macros.hpp>
#include<iostream>
#include "core.h"
#include "utils.h"
#ifdef _WIN32
#include <windows.h>
#endif


TEST_CASE("Core function", "[core]") {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);  // установка utf8 для консоли в случае win
    #endif
    const std::string expectedCore = " Я цитата! ";
    REQUIRE(core::base_function() == expectedCore);
}

TEST_CASE("Utility function", "[utils]") {
    const std::string expectedCore = " Я цитата! ";
    const std::string expectedUtils = " Я цитирую цитату:\"" + expectedCore + "\" ";
    REQUIRE(utils::utility_function() == expectedUtils);
}

TEST_CASE("Pause") {
    REQUIRE(1 == 1);
    std::system("pause"); // Добавит "Press any key to continue..."
}