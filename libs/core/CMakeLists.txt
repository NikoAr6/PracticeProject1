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
target_include_directories(core PUBLIC include)