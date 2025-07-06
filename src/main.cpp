#include <iostream>

#include "aloc_sequencial/lista_nao_ordenada.h"
#include "aloc_sequencial/lista_ordenada.h"

void demonstrarListaNaoOrdenada() {
    std::cout << "=== DEMONSTRACAO LISTA NAO ORDENADA ===" << std::endl;
    
    ListaNaoOrdenada lista;
    
    lista.inserirNoFinal(30, "Elemento C");
    lista.inserirNoFinal(10, "Elemento A");
    lista.inserirNoInicio(20, "Elemento B");
    
    std::cout << "Apos insercoes:" << std::endl;
    lista.imprimirLista();
    
    std::cout << "Buscando elemento ID 10:" << std::endl;
    Elemento* elem = lista.buscarPeloId(10);
    if (elem) {
        std::cout << "  Encontrado: ";
        elem->imprimirInfo();
    }
    
    lista.removerPrimeiro();
    std::cout << "Apos remover primeiro:" << std::endl;
    lista.imprimirLista();
    
    std::cout << "Tamanho final: " << lista.getTamanho() << std::endl;
    std::cout << std::endl;
}

void demonstrarListaOrdenada() {
    std::cout << "=== DEMONSTRACAO LISTA ORDENADA ===" << std::endl;
    
    ListaOrdenada lista;
    
    lista.inserir(30, "Elemento C");
    lista.inserir(10, "Elemento A");
    lista.inserir(20, "Elemento B");
    
    std::cout << "Apos insercoes (automaticamente ordenada):" << std::endl;
    lista.imprimirLista();
    
    std::cout << "Buscando elemento ID 20 (busca binaria):" << std::endl;
    Elemento* elem = lista.buscarPeloId(20);
    if (elem) {
        std::cout << "  Encontrado: ";
        elem->imprimirInfo();
    }
    
    lista.alterarPeloId(30, "Elemento C Alterado");
    std::cout << "Apos alterar ID 30:" << std::endl;
    lista.imprimirLista();
    
    std::cout << "Tamanho final: " << lista.getTamanho() << std::endl;
    std::cout << std::endl;
}

int main() {
    demonstrarListaNaoOrdenada();
    demonstrarListaOrdenada();
    
    return 0;
}