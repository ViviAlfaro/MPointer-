cmake_minimum_required(VERSION 3.10)
project(MPointers)

# Configuración de C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Añadir el directorio de los archivos fuente
include_directories(${PROJECT_SOURCE_DIR})

# Encontrar GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Crear la biblioteca
add_library(LinkedListLib STATIC
    MPointer.cpp
    LinkedList.cpp
    MPointerGC.cpp
)

# Crear el ejecutable de pruebas unitarias
add_executable(UnitTests
    test.cpp
)

# Vincular el ejecutable de pruebas unitarias con GoogleTest y la biblioteca
target_link_libraries(UnitTests
    LinkedListLib
    ${GTEST_LIBRARIES}
    pthread
)
