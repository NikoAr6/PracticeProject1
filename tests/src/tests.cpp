#include<cassert>
#include<iostream>
#include "utils.h"
#include "core.h"

namespace tests {
    void test_utils(const std::string& expectedCore) {
        const std::string actualUtils = utils::utility_function();
        const std::string expectedUtils = " Я цитирую цитату:\"" + expectedCore + "\" ";
        assert(actualUtils == expectedUtils);
        std::cout << "Utils test passed" << std::endl;
    }

    void test_core() {
        const std::string actualCore = core::base_function();
        const std::string expectedCore = " Я цитата! ";
        assert(actualCore == expectedCore);
        std::cout << "Core test passed" << std::endl;
        test_utils(expectedCore);
    }

    void run_all_tests() { // Функция для расширения при необходимости(core вызывает utils при исполнении)
        test_core();
    }
}


int main() {
    tests::run_all_tests();
    std::cout << "ALL TESTS PASSED" << std::endl;
    std::cout << "Press Enter to exit";
    std::cin.get();
    return 0;
}