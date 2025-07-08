add_executable(Practice1TestCatch2 src/testsCatch2.cpp)
target_link_libraries(Practice1TestCatch2 PRIVATE utils core Catch2::Catch2WithMain)

target_include_directories(Practice1TestCatch2 PRIVATE 
    ${CMAKE_SOURCE_DIR}/libs/core/include
    ${CMAKE_SOURCE_DIR}/libs/utils/include
)

enable_testing()
add_test(NAME Practice1TestCatch2 COMMAND Practice1TestCatch2)

# Автоматическое копирование библиотек
if(WIN32) # копируем dll к exe в Windows
    add_custom_command(TARGET Practice1TestCatch2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core> $<TARGET_FILE_DIR:Practice1TestCatch2>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:utils> $<TARGET_FILE_DIR:Practice1TestCatch2>
    )
elseif(APPLE) # Копируем dylib для macOS
    add_custom_command(TARGET Practice1TestCatch2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core> $<TARGET_FILE_DIR:Practice1TestCatch2>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:utils> $<TARGET_FILE_DIR:Practice1TestCatch2>
    )
    # Устанавливаем RPATH для macOS
    set_target_properties(Practice1TestCatch2 PROPERTIES
        INSTALL_RPATH "@loader_path"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
elseif(UNIX) # Копируем .so для Linux
    add_custom_command(TARGET Practice1TestCatch2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core> $<TARGET_FILE_DIR:Practice1TestCatch2>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:utils> $<TARGET_FILE_DIR:Practice1TestCatch2>
    )
    # Устанавливаем RPATH для Linux
    set_target_properties(Practice1TestCatch2 PROPERTIES
        INSTALL_RPATH "\$ORIGIN"
        BUILD_WITH_INSTALL_RPATH TRUE
    )
endif()