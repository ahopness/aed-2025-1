#include <string>

#include "../../inc/aloc_sequencial/fila.h"

//ITEM

using std::cout;
using std::endl;

Fila::Item::Item(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
}
Fila::Item::~Item() {
}

void Fila::Item::setValor(const std::string& valor) {
    this->valor = valor;
}
std::string Fila::Item::getValor() const {
    return this->valor;
}

void Fila::Item::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor << endl;
}

//FILA

Fila::Fila(int capacidade) {
    this->capacidade = capacidade;
    this->tamanho = 0;
    this->elementos = new Elemento*[capacidade];
    for (int i = 0; i < capacidade; i++) {
        this->elementos[i] = nullptr;
    }
}
Fila::~Fila() {
    for (int i = 0; i < this->tamanho; ++i) {
        delete this->elementos[i];
    }
    delete[] this->elementos;
}

bool Fila::FilaCheia() const {
    if (this->tamanho >= this->capacidade) {
        return true;
    }
    return false;
}

bool Fila::FilaVazia() const {
    if (this->tamanho == 0) {
        return true;
    }
    return false;
}

bool Fila::Enfileirar(int id, const std::string& valor) {
    if (FilaCheia()) {
        return false;
    }

    this->elementos[this->tamanho] = new Item(id, valor);
    this->tamanho++;
    
    return true;
}

bool Fila::Desemfileirar() {
    if (FilaVazia()) {
        return false;
    }
    delete this->elementos[0];

    for (int i = 0; i < this->tamanho - 1; i++) {
        this->elementos[i] = this->elementos[i + 1];
    }

    this->elementos[this->tamanho -1] = nullptr;
    this->tamanho--;
    return true;
}

Elemento* Fila::ConsultarInicio () {
    if (FilaVazia()) {
        
        return nullptr;
    }
    return this->elementos[0];
}

Elemento* Fila::ConsultarFinal() {
    if (FilaVazia()) {
        
        return nullptr;
    }
    return this->elementos[tamanho-1];
}

int Fila::getTamanho() const {
    return this->tamanho;
}

void Fila::imprimirFila() {
    cout << "Fila (Tamanho: " << this->tamanho << "):" << endl;
    for (int i = 0; i < this->tamanho; i++) {
        cout << " Posicao " << i << ": ";
        this->elementos[i]->imprimirInfo();
    }
    cout << endl;
}