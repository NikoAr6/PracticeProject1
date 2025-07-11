cmake_minimum_required(VERSION 3.14) # Минимальная версия(из-за Catch2)
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
add_subdirectory(testsCatch2)

include(GNUInstallDirs) # Cтандартные пути для установки файлов
include(CTest)

# Экспорт rконфигураций
install(EXPORT coreTargets
    FILE coreConfig.cmake
    NAMESPACE Practice1:: # Practice1::core теперь можно как библиотеку в таргет линк!
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/core
)

install(EXPORT utilsTargets
    FILE utilsConfig.cmake
    NAMESPACE Practice1::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/utils
)