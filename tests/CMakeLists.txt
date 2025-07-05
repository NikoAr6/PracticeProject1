add_executable(Practice1Test src/tests.cpp)
target_link_libraries(Practice1Test PRIVATE utils core)

target_include_directories(Practice1Test PRIVATE 
    ${CMAKE_SOURCE_DIR}/libs/core/include
    ${CMAKE_SOURCE_DIR}/libs/utils/include
)

enable_testing()

# Создание dll для запуска exe
if(WIN32)
    add_custom_command(TARGET Practice1Test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:core>
            $<TARGET_FILE:utils>
            $<TARGET_FILE_DIR:Practice1Test>
    )
endif()