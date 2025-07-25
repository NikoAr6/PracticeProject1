cmake_minimum_required(VERSION 3.14) # Минимальная версия(из-за Catch2)
project(Practice1)

# Установка общей директории для исполняемых файлов и dll при сборке
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

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
add_subdirectory(testsCatch2)

include(GNUInstallDirs) # Cтандартные пути для установки файлов
include(CTest)

set(CMAKE_INSTALL_RPATH "$ORIGIN") 
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)  # Использовать RPATH при сборке