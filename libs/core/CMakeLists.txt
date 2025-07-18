# Выделение всех .cpp и .h в core
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Библиотеки core (SHARED-для динамической библ(dll))
add_library(core_shared SHARED ${SOURCES} ${HEADERS})
# Для win определяем экспорт при сборке
if(WIN32)
    target_compile_definitions(core_shared PRIVATE CORE_EXPORTS)
endif()
set_target_properties(core_shared PROPERTIES OUTPUT_NAME "core")

# Статическая библиотека
add_library(core_static STATIC ${SOURCES} ${HEADERS})
set_target_properties(core_static PROPERTIES OUTPUT_NAME "core")

# Относительное местонахождение хедера
target_include_directories(core_shared PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # При сборке в include 
    $<INSTALL_INTERFACE:include> # После установки будут доступны
)

target_include_directories(core_static PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # При сборке в include 
    $<INSTALL_INTERFACE:include> # После установки будут доступны
)

# Установка библиотеки и заголовочных файлов
install(TARGETS core_shared core_static
    EXPORT coreTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR} # Динамические библиотеки в lib (so, dylib)
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # exe и dll в bin
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Статические библиотеки
)

install(DIRECTORY include/ DESTINATION include/core)