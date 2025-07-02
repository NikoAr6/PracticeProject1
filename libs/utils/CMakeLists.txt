# Выделение всех .cpp и .h в utils
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Библиотеки utils (SHARED-для динамической библ(dll))
add_library(utils SHARED ${SOURCES} ${HEADERS})

# Для win определяем экспорт при сборке
if(WIN32)
    target_compile_definitions(utils PRIVATE UTILS_EXPORTS)
endif()

# Относительное местонахождение хедера
target_include_directories(utils PUBLIC include)

# Зависимость от core
target_link_libraries(utils PUBLIC core)