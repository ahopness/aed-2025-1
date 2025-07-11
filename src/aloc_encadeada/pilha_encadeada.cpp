#include <string>

#include "../../inc/aloc_encadeada/pilha_encadeada.h"

//UTILIZANDO A LISTA DUPLAMENTE ENCADEADA CIRCULAR (O(1) para remocao e insercao)

// CLASSE NÓ

using std::cout;
using std::endl;

PilhaEnc::No::No(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
    this->proximo = nullptr;
    this->anterior = nullptr;
}

PilhaEnc::No::~No() {
}

void PilhaEnc::No::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string PilhaEnc::No::getValor() const {
    return this->valor;
}

void PilhaEnc::No::setProximo(No* proximo) {
    this->proximo = proximo;
}

PilhaEnc::No* PilhaEnc::No::getProximo() const {
    return this->proximo;
}

void PilhaEnc::No::setAnterior(No* anterior) {
    this->anterior = anterior;
}

PilhaEnc::No* PilhaEnc::No::getAnterior() const {
    return this->anterior;
}

void PilhaEnc::No::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor;
}

// CLASSE PILHA

PilhaEnc::PilhaEnc() {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->tamanho = 0;
}

PilhaEnc::~PilhaEnc() {
    if (this->tamanho == 0) {
        return;
    }

    this->ultimo->setProximo(nullptr);

    No* atual = this->primeiro;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->getProximo();
        delete temp;
    }
}

bool PilhaEnc::PilhaVazia() const {
    if (this->tamanho == 0) {
        return true;
    }
    return false;
}

// O(1) - insere no final
void PilhaEnc::Empilhar(int id, const std::string& valor) {
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

// O(1) - remove do final
bool PilhaEnc::Desempilhar() {
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

Elemento* PilhaEnc::ConsultarTopo() {
    if (PilhaVazia()) {
        return nullptr;
    }
    return this->ultimo;
}

int PilhaEnc::getTamanho() const{
    return this->tamanho;
}

void PilhaEnc::imprimirPilha() {
     cout << "Pilha (De Lista Duplamente Encadeada Circular) (Tamanho: " << this->tamanho << "):" << endl;
     
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