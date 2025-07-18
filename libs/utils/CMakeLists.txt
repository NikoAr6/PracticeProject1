# Выделение всех .cpp и .h в utils
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Библиотеки utils (SHARED-для динамической библ(dll))
add_library(utils SHARED ${SOURCES} ${HEADERS})

# Для win определяем экспорт при сборке
if(WIN32)
    target_compile_definitions(utils PRIVATE UTILS_EXPORTS)
endif()

# Статическая библиотека
add_library(utils_static STATIC ${SOURCES})

# Относительное местонахождение хедера
target_include_directories(utils PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # При сборке в include 
    $<INSTALL_INTERFACE:include> # После установки будут доступны
)

# Зависимость от core
target_link_libraries(utils PUBLIC core)

# Установка библиотеки и заголовочных файлов
install(TARGETS core utils core_static utils_static
    LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR} # Динамические библиотеки в lib (so, dylib)
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # exe и dll в bin
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Статические библиотеки
    CONFIGURATIONS Debug Release RelWithDebInfo MinSizeRel
)

install(DIRECTORY include/ DESTINATION include/utils)
install(DIRECTORY include/ DESTINATION include/core)