# Выделение всех .cpp и .h в utils
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Библиотеки utils (SHARED-для динамической библ(dll))
add_library(utils_shared SHARED ${SOURCES} ${HEADERS})
# Для win определяем экспорт при сборке
if(WIN32)
    target_compile_definitions(utils_shared PRIVATE UTILS_EXPORTS)
endif()
set_target_properties(utils_shared PROPERTIES OUTPUT_NAME "utils")

# Статическая библиотека
add_library(utils_static STATIC ${SOURCES} ${HEADERS})
set_target_properties(utils_static PROPERTIES OUTPUT_NAME "utils")

# Относительное местонахождение хедера
target_include_directories(utils_shared PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # При сборке в include 
    $<INSTALL_INTERFACE:include> # После установки будут доступны
)

target_include_directories(utils_static PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # При сборке в include 
    $<INSTALL_INTERFACE:include> # После установки будут доступны
)

# Зависимость от core
target_link_libraries(utils_shared PUBLIC core_shared)
target_link_libraries(utils_static PUBLIC core_static)

# Установка библиотеки и заголовочных файлов
install(TARGETS utils_shared utils_static
    EXPORT utilsTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR} # Динамические библиотеки в lib (so, dylib)
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # exe и dll в bin
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Статические библиотеки
)

install(DIRECTORY include/ DESTINATION include/utils)
install(DIRECTORY include/ DESTINATION include/core)