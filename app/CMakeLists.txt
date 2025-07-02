# Исполняемый файл
add_executable(Practice1 src/main.cpp)

# Зависимости
target_link_libraries(Practice1 PRIVATE core utils)

# Пути к заголовкам
target_include_directories(Practice1 PRIVATE 
    ${CMAKE_SOURCE_DIR}/libs/core/include
    ${CMAKE_SOURCE_DIR}/libs/utils/include
)

# Создание dll для запуска exe
if(WIN32)
    add_custom_command(TARGET Practice1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core>
            $<TARGET_FILE:utils>
            $<TARGET_FILE_DIR:Practice1>
    )
endif()