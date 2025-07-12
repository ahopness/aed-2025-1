#include <string>

#include "../../inc/aloc_sequencial/pilha.h"

// ITEM

using std::cout;
using std::endl;

Pilha::Item::Item(int id, const std::string& valor){
    this->ID = id;
    this->valor = valor;
}
Pilha::Item::~Item(){
}

void Pilha::Item::setValor(const std::string& valor){
    this->valor = valor;
}
std::string Pilha::Item::getValor() const {
    return this->valor;
}

void Pilha::Item::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor << endl;
}

// PILHA

Pilha::Pilha(int capacidade) {
    this->capacidade = capacidade;
    this->tamanho = 0;
    this->elementos = new Elemento*[capacidade];
    for (int i = 0; i < capacidade; i++) {
        this->elementos[i] = nullptr;
    }
}
Pilha::~Pilha() {
    for (int i = 0; i < this->tamanho; ++i) {
        delete this->elementos [i];
    }
    delete[] this->elementos;
}

bool Pilha::PilhaVazia() const {
    if (this->tamanho == 0) {
        return true;
    }
    return false;
}

bool Pilha::PilhaCheia() const {
    if (this->tamanho >= this->capacidade) {
        return true;
    }
    return false;
}

// O(1)
bool Pilha::Empilhar(int id, const std::string& valor) {
    if (PilhaCheia()) {
        return false;
    }

    this->elementos[this->tamanho] = new Item(id, valor);
    this->tamanho++;

    return true;
}

// O(1)
bool Pilha::Desempilhar() {
    if (PilhaVazia()) {
        return false;
    }

    delete this->elementos[this->tamanho-1];
    this->elementos[this->tamanho-1] = nullptr;
    this->tamanho--;
    return true;
}

Elemento* Pilha::ConsultarTopo() {
    if (PilhaVazia()) {
        return nullptr;
    }
    return this->elementos[tamanho-1];
} 

int Pilha::getTamanho() const {
    return this->tamanho;
}

void Pilha::imprimirPilha() {
    cout << "Pilha (Tamanho: " << this->tamanho << "):" << endl;
    for (int i = 0; i < this->tamanho; i++) {
        cout << " Posicao " << i << ": ";
        this->elementos[i]->imprimirInfo();
    }
    cout << endl;
}