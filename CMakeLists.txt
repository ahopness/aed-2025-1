cmake_minimum_required(VERSION 3.10)
project(aeds_2025_1)

set(SOURCE_FILES
    src/main.cpp
    src/elemento.cpp
    src/aloc_sequencial/lista_nao_ordenada.cpp
    src/aloc_sequencial/lista_ordenada.cpp
    src/aloc_sequencial/pilha.cpp
    src/aloc_sequencial/fila.cpp
    src/arvore/arvore_binaria.cpp
    src/sorts/sorts.cpp
    src/aloc_encadeada/lista_duplamente_encadeada_circular.cpp
    src/aloc_encadeada/lista_duplamente_encadeada.cpp
    src/aloc_encadeada/lista_simplesmente_encadeada.cpp
    src/aloc_encadeada/pilha_encadeada.cpp
    src/aloc_encadeada/fila_encadeada.cpp
    src/aloc_encadeada/deque.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})