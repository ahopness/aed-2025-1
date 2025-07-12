#include <string>

#include "../../inc/aloc_encadeada/fila.h"

using std::cout;
using std::endl;

//UTILIZANDO A LISTA DUPLAMENETE ENCADEADA CIRCULAR (O(1) para remocao e insercao)

// CLASSE NO

FilaEnc::No::No(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
    this->proximo = nullptr;
    this->anterior = nullptr;
}

FilaEnc::No::~No() {
}

void FilaEnc::No::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string FilaEnc::No::getValor() const {
    return this->valor;
}

void FilaEnc::No::setProximo(No* proximo) {
    this->proximo = proximo;
}

FilaEnc::No* FilaEnc::No::getProximo() const {
    return this->proximo;
}

void FilaEnc::No::setAnterior(No* anterior) {
    this->anterior = anterior;
}

FilaEnc::No* FilaEnc::No::getAnterior() const {
    return this->anterior;
}

void FilaEnc::No::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor;
}

//CLASSE FILA

FilaEnc::FilaEnc() {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->tamanho = 0;
}

FilaEnc::~FilaEnc() {
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

bool FilaEnc::FilaVazia() const {
    if (this->tamanho == 0) {
        return true;
    }
    return false;
}

// O(1) - insere no final
void FilaEnc::Emfileirar(int id, const std::string& valor) {
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
bool FilaEnc::Desemfileirar() {
    if (FilaVazia()) {
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

Elemento* FilaEnc::ConsultarInicio() {
    if (FilaVazia()) {
        return nullptr;
    }
    return this->primeiro;
}

Elemento* FilaEnc::ConsultarFinal() {
    if (FilaVazia()) {
        return nullptr;
    }
    return this->ultimo;
}

int FilaEnc::getTamanho() const {
    return this->tamanho;
}

void FilaEnc::imprimirFila() {
    cout << "Fila (De Lista Duplamente Encadeada Circular) (Tamanho: " << this->tamanho << "):" << endl;

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