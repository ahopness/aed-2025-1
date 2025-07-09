cmake_minimum_required(VERSION 3.24)
project(aeds_2025_1)

set(SOURCE_FILES
    main.cpp
    elemento.cpp
    aloc_sequencial/lista_nao_ordenada.cpp
    aloc_sequencial/lista_ordenada.cpp
    sorts/sorts.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})