#include "../../inc/aloc_encadeada/lista_duplamente_encadeada_circular.h"

using std::cout;
using std::endl;

// CLASSE NÓ

ListaDuplamenteEncadeadaCircular::No::No(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
    this->proximo = nullptr;
    this->anterior = nullptr;
}

ListaDuplamenteEncadeadaCircular::No::~No() {
}

void ListaDuplamenteEncadeadaCircular::No::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string ListaDuplamenteEncadeadaCircular::No::getValor() const {
    return this->valor;
}

void ListaDuplamenteEncadeadaCircular::No::setProximo(No* proximo) {
    this->proximo = proximo;
}

ListaDuplamenteEncadeadaCircular::No* ListaDuplamenteEncadeadaCircular::No::getProximo() const {
    return this->proximo;
}

void ListaDuplamenteEncadeadaCircular::No::setAnterior(No* anterior) {
    this->anterior = anterior;
}

ListaDuplamenteEncadeadaCircular::No* ListaDuplamenteEncadeadaCircular::No::getAnterior() const {
    return this->anterior;
}

void ListaDuplamenteEncadeadaCircular::No::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor;
}

// CLASSE LISTA

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->tamanho = 0;
}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    if (this->tamanho == 0) {
        return;
    }
    
    // quebrar o círculo antes de deletar
    this->ultimo->setProximo(nullptr);
    
    No* atual = this->primeiro;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->getProximo();
        delete temp;
    }
}

// O(1) - insere diretamente no início
void ListaDuplamenteEncadeadaCircular::inserirNoInicio(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    
    if (this->tamanho == 0) {
        this->primeiro = novoNo;
        this->ultimo = novoNo;
        // formar círculo com um único elemento
        novoNo->setProximo(novoNo);
        novoNo->setAnterior(novoNo);
    } else {
        // inserir entre último e primeiro
        novoNo->setProximo(this->primeiro);
        novoNo->setAnterior(this->ultimo);
        this->primeiro->setAnterior(novoNo);
        this->ultimo->setProximo(novoNo);
        this->primeiro = novoNo;
    }
    
    this->tamanho++;
}

// O(1) - insere diretamente no final
void ListaDuplamenteEncadeadaCircular::inserirNoFinal(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    
    if (this->tamanho == 0) {
        this->primeiro = novoNo;
        this->ultimo = novoNo;
        // formar círculo com um único elemento
        novoNo->setProximo(novoNo);
        novoNo->setAnterior(novoNo);
    } else {
        // inserir entre último e primeiro
        novoNo->setProximo(this->primeiro);
        novoNo->setAnterior(this->ultimo);
        this->ultimo->setProximo(novoNo);
        this->primeiro->setAnterior(novoNo);
        this->ultimo = novoNo;
    }
    
    this->tamanho++;
}

// O(1) - remove diretamente do início
bool ListaDuplamenteEncadeadaCircular::removerPrimeiro() {
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

// O(1) - remove diretamente do final
bool ListaDuplamenteEncadeadaCircular::removerUltimo() {
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

// O(n) - busca linear para encontrar o elemento
bool ListaDuplamenteEncadeadaCircular::removerPeloId(int id) {
    if (this->tamanho == 0) {
        return false;
    }
    
    // se for o primeiro elemento
    if (this->primeiro->getID() == id) {
        return removerPrimeiro();
    }
    
    // se for o último elemento
    if (this->ultimo->getID() == id) {
        return removerUltimo();
    }
    
    // buscar o nó no meio da lista
    No* atual = this->primeiro->getProximo(); // começar do segundo
    while (atual != this->primeiro && atual->getID() != id) {
        atual = atual->getProximo();
    }
    
    if (atual == this->primeiro) { // deu a volta completa, id não existe
        return false;
    }
    
    // ajustar ponteiros dos nós vizinhos
    atual->getAnterior()->setProximo(atual->getProximo());
    atual->getProximo()->setAnterior(atual->getAnterior());
    
    delete atual;
    this->tamanho--;
    return true;
}

// O(n) - busca linear sequencial
Elemento* ListaDuplamenteEncadeadaCircular::buscarPeloId(int id) {
    if (this->tamanho == 0) {
        return nullptr;
    }
    
    No* atual = this->primeiro;
    do {
        if (atual->getID() == id) {
            return atual;
        }
        atual = atual->getProximo();
    } while (atual != this->primeiro);
    
    return nullptr;
}

// O(n) - busca linear para encontrar o elemento
bool ListaDuplamenteEncadeadaCircular::alterarPeloId(int id, const std::string& novo_valor) {
    if (this->tamanho == 0) {
        return false;
    }
    
    No* atual = this->primeiro;
    do {
        if (atual->getID() == id) {
            atual->setValor(novo_valor);
            return true;
        }
        atual = atual->getProximo();
    } while (atual != this->primeiro);
    
    return false;
}

int ListaDuplamenteEncadeadaCircular::getTamanho() const {
    return this->tamanho;
}

void ListaDuplamenteEncadeadaCircular::imprimirLista() {
    cout << "Lista Duplamente Encadeada Circular (Tamanho: " << this->tamanho << "):" << endl;
    
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