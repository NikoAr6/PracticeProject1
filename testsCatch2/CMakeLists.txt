add_executable(Practice1TestCatch2 src/testsCatch2.cpp)
target_link_libraries(Practice1TestCatch2 PRIVATE core_shared utils_shared Catch2::Catch2WithMain)

target_include_directories(Practice1TestCatch2 PRIVATE
    ${CMAKE_SOURCE_DIR}/libs/core/include
    ${CMAKE_SOURCE_DIR}/libs/utils/include
)

enable_testing()
add_test(NAME Practice1TestCatch2 COMMAND Practice1TestCatch2)

install(TARGETS Practice1TestCatch2 DESTINATION bin)