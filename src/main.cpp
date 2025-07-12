#include <iostream>

#include "../inc/aloc_sequencial/lista_nao_ordenada.h"
#include "../inc/aloc_sequencial/lista_ordenada.h"

#include "../inc/aloc_sequencial/pilha.h"
#include "../inc/aloc_sequencial/fila.h"

#include "../inc/aloc_encadeada/lista_simplesmente_encadeada.h"
#include "../inc/aloc_encadeada/lista_duplamente_encadeada.h"
#include "../inc/aloc_encadeada/lista_duplamente_encadeada_circular.h"

#include "../inc/aloc_encadeada/pilha.h"
#include "../inc/aloc_encadeada/fila.h"
#include "../inc/aloc_encadeada/deque.h"

#include "../inc/arvore/arvore_binaria.h"

#include "../inc/sorts/sorts.h"

using std::cout;
using std::endl;

void demonstrarListaNaoOrdenada() {
    cout << "=== DEMONSTRACAO LISTA NAO ORDENADA SEQUENCIAL ===" << endl;
    
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
    cout << "=== DEMONSTRACAO LISTA ORDENADA SEQUENCIAL ===" << endl;
    
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

void demonstrarPilhaSequencial() {
    cout << "=== DEMONSTRACAO DA PILHA (NA ALOCACAO SEQUENCIAL) ===" << endl;

    Pilha pilha;

    //Verifica se pilha esta cheia ou vazia
    cout << "Pilha esta cheia ou vazia: ";
    if (pilha.PilhaVazia()) {
        cout << "Vazia" << endl;
    } else if (pilha.PilhaCheia()) {
        cout << "Cheia" << endl;
    }


    //Empilhando
    cout << endl << "Empilhando... " << endl;
    pilha.Empilhar(30, "Elemento C");
    pilha.imprimirPilha();
    pilha.Empilhar(10, "Elemento A");
    pilha.imprimirPilha();
    pilha.Empilhar(20, "Elemento B");
    pilha.imprimirPilha();

    //ConsultarTopo
    Elemento* topo = pilha.ConsultarTopo();
    if (topo) {
        cout << "Topo da pilha: ";
        topo->imprimirInfo();
        cout << endl;
    }

    //Desempilhar
    cout << "Desempilhando..." << endl;
    for (int i = 2; i >= 0; i--) {
        cout << "  Removendo o elemento da posicao " << i << ":" << endl;
        pilha.Desempilhar();
        pilha.imprimirPilha();
    }

    //PilhaCheia e PilhaVazia
    cout << "Pilha esta cheia ou vazia: ";
    if (pilha.PilhaVazia()) {
        cout << "Vazia" << endl;
    } else if (pilha.PilhaCheia()) {
        cout << "Cheia" << endl;
    }
    cout << endl;
}
void demonstrarFilaSequencial() {
    cout << "=== DEMONSTRACAO DA FILA (NA ALOCACAO SEQUENCIAL) ===" << endl;

    Fila fila;

    //FilaCheia e FilaVazia
    cout << "A fila esta cheia ou vazia: ";
    if (fila.FilaVazia()) {
        cout << "Vazia" << endl;
    } else if (fila.FilaCheia()) {
        cout << "Cheia" << endl;
    }

    //Enfileirando
    cout << endl << "Enfileirando: " << endl;
    fila.Enfileirar(30, "Elemento C");
    fila.imprimirFila();
    fila.Enfileirar(10, "Elemento A");
    fila.imprimirFila();
    fila.Enfileirar(20, "Elemento B");
    fila.imprimirFila();

    //ConsultarInicio
    Elemento* ini = fila.ConsultarInicio();
    if (ini) {
        cout << "Inicio da fila: ";
        ini->imprimirInfo();
        cout << endl;
    }

    //ConsultarFinal
    Elemento* fin = fila.ConsultarFinal();
    if (fin) {
        cout << "Final da fila: ";
        fin->imprimirInfo();
        cout << endl;
    }

    //Desemfileirar
    cout << "Desemfileirando..." << endl;
    for (int i = 2; i >= 0; i--) {
        cout << "  Removendo o elemento da posicao " << i << ":" << endl;
        fila.Desemfileirar();
        fila.imprimirFila();
    }
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

void demonstrarPilhaEncadeada() {
    cout << "=== DEMONSTRACAO PILHA (DE LISTA DUPLAMENTE ENCADEADA CIRCULAR) ===" << endl;

    PilhaEnc pilha;

    //Verificar se pilha esta vazia
    cout << "Pilha esta vazia: ";
    if (pilha.PilhaVazia()) {
        cout << "Verdadeiro" << endl;
    } else {
        cout << "Falso" << endl << endl;
    }

    //Empilhando
    cout << endl << "Empilhando..." << endl;
    pilha.Empilhar(10, "Elemento A");
    pilha.imprimirPilha();
    pilha.Empilhar(20, "Elemento B");
    pilha.imprimirPilha();
    pilha.Empilhar(30, "Elemento C");
    pilha.imprimirPilha();

    //ConsultarTopo
    Elemento* topo = pilha.ConsultarTopo();
    if (topo) {
        cout << "Topo da pilha: ";
        topo->imprimirInfo();
    }

    //Verificar se pilha esta vazia
    cout << endl << "Pilha esta vazia: ";
    if (pilha.PilhaVazia()) {
        cout << "Verdadeiro" << endl;
    } else {
        cout << "Falso" << endl << endl;
    }

    //Desempilhar
    cout << "Desempilhando..." << endl;
    while (true) {
        pilha.Desempilhar();
        if (pilha.PilhaVazia()) {
            break;
        }
        pilha.imprimirPilha();
    }

}
void demonstrarFilaEncadeada() {
    cout << "=== DEMONSTRACAO FILA (DE LISTA DUPLAMENTE ENCADEADA CIRCULAR) ===" << endl;

    FilaEnc fila;

    //Verificar se fila esta vazia
    cout << "Fila esta vazia: ";
    if (fila.FilaVazia()) {
        cout << "Verdadeiro" << endl;
    } else {
        cout << "Falso" << endl;
    }

    cout << endl << "Emfileirando..." << endl;
    fila.Emfileirar(10, "Elemento A");
    fila.imprimirFila();
    fila.Emfileirar(20, "Elemento B");
    fila.imprimirFila();
    fila.Emfileirar(30, "Elemento C");
    fila.imprimirFila();

    //ConsultarInicio
    Elemento* ini = fila.ConsultarInicio();
    if (ini) {
        cout << "Inicio da fila: ";
        ini->imprimirInfo();
        cout << endl;
    }

    //ColsultarFinal
    Elemento* fin = fila.ConsultarFinal();
    if (fin) {
        cout << "Final da fila: ";
        fin->imprimirInfo();
        cout << endl;
    }

    //Verificar se fila esta vazia
    cout << "Fila esta vazia: ";
    if (fila.FilaVazia()) {
        cout << "Verdadeiro" << endl;
    } else {
        cout << "Falso" << endl << endl;
    }

    //Desemfileirar
    cout << "Desemfileirando..." << endl;
    while(true) {
        fila.Desemfileirar();
        if (fila.FilaVazia()) {
            break;
        }
        fila.imprimirFila();
    }

}
void demonstrarDequeEncadeado() {
    cout << "=== DEMONSTRACAO DEQUE (DE LISTA DUPLAMENTE ENCADEADA CIRCULAR) ===" << endl;

    Deque deque;

    //Verificar se deque esta vazio
    cout << "Deque esta vazio: ";
    if (deque.DequeVazio()) {
        cout << "Verdadeiro" << endl;
    } else {
        cout << "Falso" << endl << endl;
    }

    //Inserindo (no inicio e no final)
    cout << endl << "Inserindo..." << endl;
    deque.InserirNoInicio(10, "Elemento A");
    deque.imprimirDeque();
    deque.InserirNoFinal(20, "Elemento B");
    deque.imprimirDeque();
    deque.InserirNoInicio(30, "Elemento C");
    deque.imprimirDeque();
    deque.InserirNoFinal(40, "Elemento D");
    deque.imprimirDeque();
    deque.InserirNoInicio(50, "Elemento E");
    deque.imprimirDeque();
    deque.InserirNoFinal(60, "Elemento F");
    deque.imprimirDeque();

    //Verificar se deque esta vazio
    cout << endl << "Deque esta vazio: ";
    if (deque.DequeVazio()) {
        cout << "Verdadeiro" << endl;
    } else {
        cout << "Falso" << endl << endl;
    }

    //Removendo (no inicio e no final)
    cout << "Removendo..." << endl;
    while (true) {
        deque.RemoverUltimo();
        deque.imprimirDeque();
        deque.RemoverPrimeiro();
        if (deque.DequeVazio()) {
            break;
        }
        deque.imprimirDeque();
    }

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

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void copiarArray(int destino[], int origem[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}
void demonstrarSorts() {
    cout << "=== DEMONSTRACAO ALGORITMOS DE ORDENACAO ===" << endl;
    
    int arr_original[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr_original) / sizeof(arr_original[0]);
    
    cout << "Array original: ";
    imprimirArray(arr_original, n);
    cout << endl;
    
    cout << "--- BUBBLE SORT (O(n^2)) ---" << endl;
    int arr_bubble[7];
    copiarArray(arr_bubble, arr_original, n);
    cout << "Antes: ";
    imprimirArray(arr_bubble, n);
    bubble_sort(arr_bubble, n);
    cout << "Depois: ";
    imprimirArray(arr_bubble, n);
    cout << endl;
    
    cout << "--- INSERTION SORT (O(n^2)) ---" << endl;
    int arr_insertion[7];
    copiarArray(arr_insertion, arr_original, n);
    cout << "Antes: ";
    imprimirArray(arr_insertion, n);
    insertion_sort(arr_insertion, n);
    cout << "Depois: ";
    imprimirArray(arr_insertion, n);
    cout << endl;
    
    cout << "--- MERGE SORT (O(n log n)) ---" << endl;
    int arr_merge[7];
    copiarArray(arr_merge, arr_original, n);
    cout << "Antes: ";
    imprimirArray(arr_merge, n);
    merge_sort(arr_merge, 0, n - 1);
    cout << "Depois: ";
    imprimirArray(arr_merge, n);
    cout << endl;
    
    cout << "--- QUICK SORT (O(n log n)) ---" << endl;
    int arr_quick[7];
    copiarArray(arr_quick, arr_original, n);
    cout << "Antes: ";
    imprimirArray(arr_quick, n);
    quick_sort(arr_quick, 0, n - 1);
    cout << "Depois: ";
    imprimirArray(arr_quick, n);
    cout << endl;
    
    cout << "--- HEAP SORT (O(n log n)) ---" << endl;
    int arr_heap[7];
    copiarArray(arr_heap, arr_original, n);
    cout << "Antes: ";
    imprimirArray(arr_heap, n);
    heap_sort(arr_heap, n);
    cout << "Depois: ";
    imprimirArray(arr_heap, n);
    cout << endl;
    

    cout << "--- BOGO SORT (O(n!)) - usando array menor pra demonstracao ---" << endl;
    initialize_random();
    int arr_bogo[] = {3, 1, 2};
    int n_bogo = 3;
    cout << "Antes: ";
    imprimirArray(arr_bogo, n_bogo);
    cout << "Ordenando com Bogo Sort (PS: pode demorar...)" << endl;
    bogosort(arr_bogo, n_bogo);
    cout << "Depois: ";
    imprimirArray(arr_bogo, n_bogo);
    cout << endl;
}

int main() {
    // Demonstrar Listas Sequenciais
    demonstrarListaNaoOrdenada();
    demonstrarListaOrdenada();

    // Pilha e Fila
    demonstrarPilhaSequencial();
    demonstrarFilaSequencial();

    // Demonstrar Listas Encadeadas
    demonstrarListaSimplesmenteEncadeada();
    demonstrarListaDuplamenteEncadeada();
    demonstrarListaDuplamenteEncadeadaCircular();

    // Pilha, Fila e Deque
    demonstrarPilhaEncadeada();
    demonstrarFilaEncadeada();
    demonstrarDequeEncadeado();

    // Arvore
    demonstrarArvoreBinaria();

    // Extra: Sorts
    demonstrarSorts();

    return 0;
}
