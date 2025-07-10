cmake_minimum_required(VERSION 3.10)

project(aed-2025-1)

# usa o c++ 11 de padrão, EU **ACHO** Q o rodrigo usa essa msm versão em sala de aula, provavelmento to errado
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# lida com os arquivos include
include_directories(inc)
include_directories(inc/aloc_sequencial)
include_directories(inc/aloc_encadeada)
include_directories(inc/arvore)
include_directories(inc/sorts)

# buscar automaticamente todos os arquivos .h e .cpp
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/**/*.cpp"
)
file(GLOB_RECURSE HEADERS 
    "inc/*.h"
    "inc/**/*.h"
)
set(TUDO ${SOURCES} ${HEADERS}) # agrupa as duas listas

add_executable(${PROJECT_NAME} ${TUDO})

if(WIN32)
    # opções de compilação do MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /Zi /Od)
else()
    # opções de compilação pro GCC e pro Clang
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -g -O0)
endif()