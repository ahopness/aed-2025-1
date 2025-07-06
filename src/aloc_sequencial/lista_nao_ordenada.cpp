#include <string>

#include "lista_nao_ordenada.h"

// ITEM

ListaNaoOrdenada::Item::Item(int id, const std::string& valor){
    this->ID = id;
    this->valor = valor;
}
ListaNaoOrdenada::Item::~Item() {
}

void ListaNaoOrdenada::Item::setValor(const std::string& valor) {
    this->valor = valor;
}
std::string ListaNaoOrdenada::Item::getValor() const {
    return this->valor;
}

void ListaNaoOrdenada::Item::imprimirInfo() {
    std::cout << "ID: " << this->ID << ", valor: " << this->valor << std::endl;
}

// LISTA

ListaNaoOrdenada::ListaNaoOrdenada(int capacidade_inicial) {
    this->capacidade = capacidade_inicial;
    this->tamanho = 0;
    this->elementos = new Elemento*[capacidade_inicial];
    for (int i = 0; i < capacidade_inicial; i++) {
        this->elementos[i] = nullptr;
    }
}
ListaNaoOrdenada::~ListaNaoOrdenada() {
    for (int i = 0; i < this->tamanho; i++) {
        delete this->elementos[i];
    }
    delete[] this->elementos;
}

// O(n) - precisa copiar todos os elementos para o novo array
void ListaNaoOrdenada::redimensionar() {
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

// O(n) - precisa deslocar todos os elementos para a direita
void ListaNaoOrdenada::inserirNoInicio(int id, const std::string& valor) {
    if (this->tamanho >= this->capacidade) {
        this->redimensionar();
    }
    
    for (int i = this->tamanho; i > 0; i--) {
        this->elementos[i] = this->elementos[i - 1];
    }
    
    this->elementos[0] = new Item(id, valor);
    this->tamanho++;
}
// O(1) - insere diretamente no final (amortizado devido ao redimensionamento)
void ListaNaoOrdenada::inserirNoFinal(int id, const std::string& valor) {
    if (this->tamanho >= this->capacidade) {
        this->redimensionar();
    }
    
    this->elementos[this->tamanho] = new Item(id, valor);
    this->tamanho++;
}

// O(n) - precisa deslocar todos os elementos para a esquerda
bool ListaNaoOrdenada::removerPrimeiro() {
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
bool ListaNaoOrdenada::removerUltimo() {
    if (this->tamanho == 0) {
        return false;
    }
    
    delete this->elementos[this->tamanho - 1];
    this->elementos[this->tamanho - 1] = nullptr;
    this->tamanho--;
    return true;
}

// O(n) - busca linear + deslocamento dos elementos
bool ListaNaoOrdenada::removerPeloId(int id) {
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
// O(n) - busca linear sequencial
Elemento* ListaNaoOrdenada::buscarPeloId(int id) {
    for (int i = 0; i < this->tamanho; i++) {
        if (this->elementos[i]->getID() == id) {
            return this->elementos[i];
        }
    }
    return nullptr;
}

// O(n) - busca linear para encontrar o elemento
bool ListaNaoOrdenada::alterarPeloId(int id, const std::string& novo_valor) {
    for (int i = 0; i < this->tamanho; i++) {
        if (this->elementos[i]->getID() == id) {
            Item* item = (Item*)this->elementos[i];
            item->setValor(novo_valor);
            return true;
        }
    }
    return false;
}

int ListaNaoOrdenada::getTamanho() const {
    return this->tamanho;
}

void ListaNaoOrdenada::imprimirLista() {
    std::cout << "Lista Nao Ordenada (Tamanho: " << this->tamanho << "):" << std::endl;
    for (int i = 0; i < this->tamanho; i++) {
        std::cout << "  Posicao " << i << ": ";
        this->elementos[i]->imprimirInfo();
    }
    std::cout << std::endl;
}
