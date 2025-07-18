# Выделение всех .cpp и .h в core
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Библиотеки core (SHARED-для динамической библ(dll))
add_library(core SHARED ${SOURCES} ${HEADERS})

# Для win определяем экспорт при сборке
if(WIN32)
    target_compile_definitions(core PRIVATE CORE_EXPORTS)
endif()

# Относительное местонахождение хедера
target_include_directories(core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # При сборке в include 
    $<INSTALL_INTERFACE:include> # После установки будут доступны
)

# Установка библиотеки и заголовочных файлов
install(TARGETS core
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # Динамические библиотеки в lib (so, dylib)
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # exe и dll в bin
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Статические библиотеки
    CONFIGURATIONS Debug Release RelWithDebInfo MinSizeRel
)

install(DIRECTORY include/ DESTINATION include/core)