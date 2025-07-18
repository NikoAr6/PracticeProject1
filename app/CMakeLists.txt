# Исполняемый файл
add_executable(Practice1 src/main.cpp)

# Зависимости
target_link_libraries(Practice1 PRIVATE core_shared utils_shared)

# Пути к заголовкам
target_include_directories(Practice1 PRIVATE 
    ${CMAKE_SOURCE_DIR}/libs/core/include
    ${CMAKE_SOURCE_DIR}/libs/utils/include
)

install(TARGETS Practice1 DESTINATION bin)