cmake_minimum_required(VERSION 3.14) # Минимальная версия
project(Practice1)

# Загрузка Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

# Ссылки на "подпроекты"
add_subdirectory(libs/core)
add_subdirectory(libs/utils)
add_subdirectory(app)
add_subdirectory(tests)
add_subdirectory(testsCatch2)