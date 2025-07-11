#include <string>

#include "../../inc/aloc_encadeada/deque.h"

using std::cout;
using std::endl;

//UTILIZANDO A LISTA DUPLAMENTE ENCADEADA CIRCULAR (O(1) para remocao e insercao)

// CLASSE NO

Deque::No::No(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
    this->proximo = nullptr;
    this->anterior = nullptr;
}

Deque::No::~No() {
}

void Deque::No::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string Deque::No::getValor() const {
    return this->valor;
}

void Deque::No::setProximo(No* proximo) {
    this->proximo = proximo;
}

Deque::No* Deque::No::getProximo() const {
    return this->proximo;
}

void Deque::No::setAnterior(No* anterior) {
    this->anterior = anterior;
}

Deque::No* Deque::No::getAnterior() const {
    return this->anterior;
}

void Deque::No::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor;
}

// CLASSE DEQUE

Deque::Deque() {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->tamanho = 0;
}

Deque::~Deque() {
    if (this->tamanho == 0) {
        return;
    }

    this->ultimo->setProximo(nullptr);

    No* atual = this->primeiro;
    while (atual != nullptr) {
        No* temp = atual; atual = atual->getProximo();
        delete temp;
    }
}

bool Deque::DequeVazio() const {
    if (this->tamanho == 0) {
        return true;
    }
    return false;
}

// O(1) - insere no inicio
void Deque::InserirNoInicio(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);

    if (this->tamanho == 0) {
        this->primeiro = novoNo;
        this->ultimo = novoNo;
        novoNo->setProximo(novoNo);
        novoNo->setAnterior(novoNo);
    } else {
        novoNo->setProximo(this->primeiro);
        novoNo->setAnterior(this->ultimo);
        this->primeiro->setAnterior(novoNo);
        this->ultimo->setProximo(novoNo);
        this->primeiro = novoNo;
    }
    this->tamanho++;
}

// O(1) - insere no final
void Deque::InserirNoFinal(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    
    if (this->tamanho == 0) {
        this->primeiro = novoNo;
        this->ultimo = novoNo;
        novoNo->setProximo(novoNo);
        novoNo->setAnterior(novoNo);
    } else {
        novoNo->setProximo(this->primeiro);
        novoNo->setAnterior(this->ultimo);
        this->ultimo->setProximo(novoNo);
        this->primeiro->setAnterior(novoNo);
        this->ultimo = novoNo;
    }
    this->tamanho++;
}

// O(1) - remove do início
bool Deque::RemoverPrimeiro() {
    if (this->tamanho == 0) {
        return false;
    }
    
    No* temp = this->primeiro;
    
    if (this->tamanho == 1) {
        this->primeiro = nullptr;
        this->ultimo = nullptr;
    } else {
        this->primeiro = this->primeiro->getProximo();
        this->primeiro->setAnterior(this->ultimo);
        this->ultimo->setProximo(this->primeiro);
    }
    delete temp;
    this->tamanho--;
    return true;
}

// O(1) - remove do final
bool Deque::RemoverUltimo() {
    if (this->tamanho == 0) {
        return false;
    }
    
    No* temp = this->ultimo;
    
    if (this->tamanho == 1) {
        this->primeiro = nullptr;
        this->ultimo = nullptr;
    } else {
        this->ultimo = this->ultimo->getAnterior();
        this->ultimo->setProximo(this->primeiro);
        this->primeiro->setAnterior(this->ultimo);
    }
    delete temp;
    this->tamanho--;
    return true;
}

int Deque::getTamanho() const {
    return this->tamanho;
}

void Deque::imprimirDeque() {
    cout << "Deque (De Lista Duplamente Encadeada Circular) (Tamanho: " << this->tamanho << "):" << endl;

    if (this->tamanho == 0) {
        cout << endl;
        return;
    }

    No* atual = this->primeiro;
    int posicao = 0;

    do {
        cout << "  Posicao " << posicao << ": ";
        atual->imprimirInfo();
        cout << endl;
        atual = atual->getProximo();
        posicao++;
    } while (atual != this->primeiro);
    cout << endl;
}