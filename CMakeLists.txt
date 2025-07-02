cmake_minimum_required(VERSION 3.10) # Минимальная версия
project(Practice1)

# Ссылки на "подпроекты"
add_subdirectory(libs/core)
add_subdirectory(libs/utils)
add_subdirectory(app)
add_subdirectory(tests)