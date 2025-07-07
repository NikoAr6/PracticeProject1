# Исполняемый файл
add_executable(Practice1 src/main.cpp)

# Зависимости
target_link_libraries(Practice1 PRIVATE core utils)

# Пути к заголовкам
target_include_directories(Practice1 PRIVATE 
    ${CMAKE_SOURCE_DIR}/libs/core/include
    ${CMAKE_SOURCE_DIR}/libs/utils/include
)

# Автоматическое копирование библиотек
if(WIN32) # копируем dll к exe в win
    add_custom_command(TARGET Practice1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core> $<TARGET_FILE_DIR:Practice1>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:utils> $<TARGET_FILE_DIR:Practice1>
    )
elseif(APPLE) # Копируем dylib в RPATH для mac
    add_custom_command(TARGET Practice1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core> $<TARGET_FILE_DIR:Practice1>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:utils> $<TARGET_FILE_DIR:Practice1>
    )
    # Устанавливаем RPATH для macOS
    set_target_properties(Practice1 PROPERTIES
        INSTALL_RPATH "@loader_path" # В mac для указ. относит. путей используется loaderPath
        BUILD_WITH_INSTALL_RPATH TRUE
    )
elseif(UNIX) # Копируем .so в RPATH для linux
    add_custom_command(TARGET Practice1 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core> $<TARGET_FILE_DIR:Practice1>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:utils> $<TARGET_FILE_DIR:Practice1>
    )
    # Устанавливаем RPATH для Linux
    set_target_properties(Practice1 PROPERTIES
        INSTALL_RPATH "\$ORIGIN"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
endif()