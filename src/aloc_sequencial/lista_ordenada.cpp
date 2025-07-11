#include <string>

#include "../../inc/aloc_sequencial/lista_ordenada.h"

using std::endl;
using std::cout;

ListaOrdenada::Item::Item(int id, const std::string& valor){
    this->ID = id;
    this->valor = valor;
}

ListaOrdenada::Item::~Item() {
}

void ListaOrdenada::Item::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string ListaOrdenada::Item::getValor() const {
    return this->valor;
}

void ListaOrdenada::Item::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor << endl;
}

ListaOrdenada::ListaOrdenada(int capacidade_inicial) {
    this->capacidade = capacidade_inicial;
    this->tamanho = 0;
    this->elementos = new Elemento*[capacidade_inicial];
    for (int i = 0; i < capacidade_inicial; i++) {
        this->elementos[i] = nullptr;
    }
}

ListaOrdenada::~ListaOrdenada() {
    for (int i = 0; i < this->tamanho; i++) {
        delete this->elementos[i];
    }
    delete[] this->elementos;
}

// O(n) - precisa copiar todos os elementos para o novo array
void ListaOrdenada::redimensionar() {
    int nova_capacidade = this->capacidade * 2;
    Elemento** novos_elementos = new Elemento*[nova_capacidade];
    
    for (int i = 0; i < this->tamanho; i++) {
        novos_elementos[i] = this->elementos[i];
    }
    
    for (int i = this->tamanho; i < nova_capacidade; i++) {
        novos_elementos[i] = nullptr;
    }
    
    delete[] this->elementos;
    this->elementos = novos_elementos;
    this->capacidade = nova_capacidade;
}

// O(log n) - busca binária para encontrar posição de inserção
int ListaOrdenada::encontrarPosicaoInsercao(int id) {
    int inicio = 0;
    int fim = this->tamanho;
    
    while (inicio < fim) {
        int meio = (inicio + fim) / 2;
        if (this->elementos[meio]->getID() < id) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }
    
    return inicio;
}

// O(n) - busca O(log n) + inserção/deslocamento O(n) = O(n)
void ListaOrdenada::inserir(int id, const std::string& valor) {
    if (this->tamanho >= this->capacidade) {
        this->redimensionar();
    }
    
    int posicao = this->encontrarPosicaoInsercao(id);
    
    for (int i = this->tamanho; i > posicao; i--) {
        this->elementos[i] = this->elementos[i - 1];
    }
    
    this->elementos[posicao] = new Item(id, valor);
    this->tamanho++;
}

// O(n) - precisa deslocar todos os elementos para a esquerda
bool ListaOrdenada::removerPrimeiro() {
    if (this->tamanho == 0) {
        return false;
    }
    
    delete this->elementos[0];
    
    for (int i = 0; i < this->tamanho - 1; i++) {
        this->elementos[i] = this->elementos[i + 1];
    }
    
    this->elementos[this->tamanho - 1] = nullptr;
    this->tamanho--;
    return true;
}

// O(1) - remove diretamente do final
bool ListaOrdenada::removerUltimo() {
    if (this->tamanho == 0) {
        return false;
    }
    
    delete this->elementos[this->tamanho - 1];
    this->elementos[this->tamanho - 1] = nullptr;
    this->tamanho--;
    return true;
}

// O(n) - busca linear + deslocamento dos elementos (poderia ser O(log n) para busca, mas ainda O(n) para remoção)
bool ListaOrdenada::removerPeloId(int id) {
    for (int i = 0; i < this->tamanho; i++) {
        if (this->elementos[i]->getID() == id) {
            delete this->elementos[i];
            
            for (int j = i; j < this->tamanho - 1; j++) {
                this->elementos[j] = this->elementos[j + 1];
            }
            
            this->elementos[this->tamanho - 1] = nullptr;
            this->tamanho--;
            return true;
        }
    }
    return false;
}

Elemento* ListaOrdenada::buscarPeloId(int id) { // Busca binaria
    int inicio = 0;
    int fim = this->tamanho - 1;
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int id_meio = this->elementos[meio]->getID();
        
        if (id_meio == id) {
            return this->elementos[meio];
        } else if (id_meio < id) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    return nullptr;
}

// O(log n) - utiliza busca binária para encontrar o elemento
bool ListaOrdenada::alterarPeloId(int id, const std::string& novo_valor) {
    Elemento* elemento = this->buscarPeloId(id);
    if (elemento != nullptr) {
        Item* item = (Item*)elemento;
        item->setValor(novo_valor);
        return true;
    }
    return false;
}

int ListaOrdenada::getTamanho() const {
    return this->tamanho;
}

void ListaOrdenada::imprimirLista() {
    cout << "Lista Ordenada (Tamanho: " << this->tamanho << "):" << endl;
    for (int i = 0; i < this->tamanho; i++) {
        cout << "  Posicao " << i << ": ";
        this->elementos[i]->imprimirInfo();
    }
    cout << endl;
} 
