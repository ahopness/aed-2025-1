#include <iostream>

#include "aloc_sequencial/lista_nao_ordenada.h"
#include "aloc_sequencial/lista_ordenada.h"

#include "aloc_encadeada/lista_simplesmente_encadeada.h"
#include "aloc_encadeada/lista_duplamente_encadeada.h"
#include "aloc_encadeada/lista_duplamente_encadeada_circular.h"

#include "arvore/arvore_binaria.h"

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
void demonstrarListaDuplamenteEncadeada() {
    cout << "=== DEMONSTRACAO LISTA DUPLAMENTE ENCADEADA ===" << endl;
    
    ListaDuplamenteEncadeada lista;
    
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
    
    cout << "Removendo ultimo elemento (O(1) - vantagem sobre lista simples!)..." << endl;
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
void demonstrarListaDuplamenteEncadeadaCircular() {
    cout << "=== DEMONSTRACAO LISTA DUPLAMENTE ENCADEADA CIRCULAR ===" << endl;
    
    ListaDuplamenteEncadeadaCircular lista;
    
    // Testando inserções
    lista.inserirNoFinal(10, "Elemento A");
    lista.inserirNoFinal(20, "Elemento B");
    lista.inserirNoInicio(5, "Elemento Inicial");
    lista.inserirNoFinal(30, "Elemento C");
    
    cout << "Apos insercoes (estrutura circular):" << endl;
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
    cout << "Removendo primeiro elemento (mantendo circularidade)..." << endl;
    lista.removerPrimeiro();
    lista.imprimirLista();
    
    cout << "Removendo ultimo elemento (O(1) com estrutura circular)..." << endl;
    lista.removerUltimo();
    lista.imprimirLista();
    
    cout << "Removendo elemento ID 20..." << endl;
    if (lista.removerPeloId(20)) {
        cout << "Elemento removido com sucesso!" << endl;
    }
    lista.imprimirLista();
    
    // Testando com lista pequena para mostrar circularidade
    cout << "Testando circularidade com elemento unico:" << endl;
    lista.inserirNoInicio(100, "Elemento Unico");
    lista.imprimirLista();
    cout << "Removendo elemento unico..." << endl;
    lista.removerPrimeiro();
    lista.imprimirLista();
    
    cout << "Tamanho final: " << lista.getTamanho() << endl;
    cout << endl;
}

void demonstrarArvoreBinaria() {
    cout << "=== DEMONSTRACAO ARVORE BINARIA ===" << endl;
    
    ArvoreBinaria arvore;
    
    // Testando inserções
    arvore.inserir(50, "Raiz");
    arvore.inserir(30, "Esquerda");
    arvore.inserir(70, "Direita");
    arvore.inserir(20, "Esq-Esq");
    arvore.inserir(40, "Esq-Dir");
    arvore.inserir(60, "Dir-Esq");
    arvore.inserir(80, "Dir-Dir");
    
    cout << "Apos insercoes (arvore balanceada manualmente):" << endl;
    arvore.imprimir();
    
    // Testando busca
    cout << "Buscando elemento ID 40:" << endl;
    Elemento* elem = arvore.buscar(40);
    if (elem) {
        cout << "  Encontrado: ";
        elem->imprimirInfo();
    }
    
    cout << "Buscando elemento ID 100 (nao existe):" << endl;
    elem = arvore.buscar(100);
    if (!elem) {
        cout << "  Elemento nao encontrado (como esperado)" << endl;
    }
    
    // Testando remoção de folha
    cout << "Removendo folha (ID 20)..." << endl;
    if (arvore.remover(20)) {
        cout << "Elemento removido com sucesso!" << endl;
    }
    arvore.imprimir();
    
    // Testando remoção de nó com um filho
    cout << "Removendo no com um filho (ID 80)..." << endl;
    if (arvore.remover(80)) {
        cout << "Elemento removido com sucesso!" << endl;
    }
    arvore.imprimir();
    
    // Testando remoção de nó com dois filhos
    cout << "Removendo no com dois filhos (ID 30)..." << endl;
    if (arvore.remover(30)) {
        cout << "Elemento removido com sucesso!" << endl;
    }
    arvore.imprimir();
    
    // Testando remoção da raiz
    cout << "Removendo raiz (ID 50)..." << endl;
    if (arvore.remover(50)) {
        cout << "Elemento removido com sucesso!" << endl;
    }
    arvore.imprimir();
    
    cout << endl;
}

int main() {
    demonstrarListaNaoOrdenada();
    demonstrarListaOrdenada();

    demonstrarListaSimplesmenteEncadeada();
    demonstrarListaDuplamenteEncadeada();
    demonstrarListaDuplamenteEncadeadaCircular();

    demonstrarArvoreBinaria();

    return 0;
}
