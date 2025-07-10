#include <iostream>

#include "aloc_sequencial/lista_nao_ordenada.h"
#include "aloc_sequencial/lista_ordenada.h"

#include "aloc_encadeada/lista_simplesmente_encadeada.h"

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

void demonstrarListaSimplesmenteEncadeada() {
    cout << "=== DEMONSTRACAO LISTA SIMPLESMENTE ENCADEADA ===" << endl;
    
    ListaSimplesmenteEncadeada lista;
    
    // Testando inserções
    lista.inserirNoFinal(10, "Elemento A");
    lista.inserirNoFinal(20, "Elemento B");
    lista.inserirNoInicio(5, "Elemento Inicial");
    lista.inserirNoFinal(30, "Elemento C");
    
    cout << "Apos insercoes:" << endl;
    lista.imprimirLista();
    
    // Testando busca
    cout << "Buscando elemento ID 20:" << endl;
    Elemento* elem = lista.buscarPeloId(20);
    if (elem) {
        cout << "  Encontrado: ";
        elem->imprimirInfo();
        cout << endl;
    }
    
    // Testando alteração
    if (lista.alterarPeloId(10, "Elemento A Alterado")) {
        cout << "Elemento ID 10 alterado com sucesso!" << endl;
    }
    lista.imprimirLista();
    
    // Testando remoções
    cout << "Removendo primeiro elemento..." << endl;
    lista.removerPrimeiro();
    lista.imprimirLista();
    
    cout << "Removendo ultimo elemento..." << endl;
    lista.removerUltimo();
    lista.imprimirLista();
    
    cout << "Removendo elemento ID 20..." << endl;
    if (lista.removerPeloId(20)) {
        cout << "Elemento removido com sucesso!" << endl;
    }
    lista.imprimirLista();
    
    cout << "Tamanho final: " << lista.getTamanho() << endl;
    cout << endl;
}

int main() {
    demonstrarListaNaoOrdenada();
    demonstrarListaOrdenada();
    demonstrarListaSimplesmenteEncadeada();
    
    return 0;
}
