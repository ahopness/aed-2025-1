#include <iostream>

#include "aloc_sequencial/lista_nao_ordenada.h"
#include "aloc_sequencial/lista_ordenada.h"

using std::cout;
using std::endl;

void demonstrarListaNaoOrdenada() {
    cout << "=== DEMONSTRACAO LISTA NAO ORDENADA ===" << endl;
    
    ListaNaoOrdenada lista;
    
    lista.inserirNoFinal(30, "Elemento C");
    lista.inserirNoFinal(10, "Elemento A");
    lista.inserirNoInicio(20, "Elemento B");
    
    std::cout << "Apos insercoes:" << std::endl;
    lista.imprimirLista();
    
    cout << "Buscando elemento ID 10:" << endl;
    Elemento* elem = lista.buscarPeloId(10);
    if (elem) {
        cout << "  Encontrado: ";
        elem->imprimirInfo();
    }
    
    lista.removerPrimeiro();
    cout << "Apos remover primeiro:" << endl;
    lista.imprimirLista();
    
    cout << "Tamanho final: " << lista.getTamanho() << endl;
    cout << endl;
}

void demonstrarListaOrdenada() {
    cout << "=== DEMONSTRACAO LISTA ORDENADA ===" << endl;
    
    ListaOrdenada lista;
    
    lista.inserir(30, "Elemento C");
    lista.inserir(10, "Elemento A");
    lista.inserir(20, "Elemento B");
    
    cout << "Apos insercoes (automaticamente ordenada):" << endl;
    lista.imprimirLista();
    
    cout << "Buscando elemento ID 20 (busca binaria):" << endl;
    Elemento* elem = lista.buscarPeloId(20);
    if (elem) {
        cout << "  Encontrado: ";
        elem->imprimirInfo();
    }
    
    lista.alterarPeloId(30, "Elemento C Alterado");
    cout << "Apos alterar ID 30:" << endl;
    lista.imprimirLista();
    
    cout << "Tamanho final: " << lista.getTamanho() << endl;
    cout << endl;
}

int main() {
    demonstrarListaNaoOrdenada();
    demonstrarListaOrdenada();
    
    return 0;
}
