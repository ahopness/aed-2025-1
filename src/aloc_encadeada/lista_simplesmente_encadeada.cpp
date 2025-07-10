#include "../../inc/aloc_encadeada/lista_simplesmente_encadeada.h"

using std::cout;
using std::endl;

// CLASSE NÓ

ListaSimplesmenteEncadeada::No::No(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
    this->proximo = nullptr;
}
ListaSimplesmenteEncadeada::No::~No() {
}

void ListaSimplesmenteEncadeada::No::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string ListaSimplesmenteEncadeada::No::getValor() const {
    return this->valor;
}

void ListaSimplesmenteEncadeada::No::setProximo(No* proximo) {
    this->proximo = proximo;
}

ListaSimplesmenteEncadeada::No* ListaSimplesmenteEncadeada::No::getProximo() const {
    return this->proximo;
}

void ListaSimplesmenteEncadeada::No::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor;
}

// CLASSE LISTA

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->tamanho = 0;
}
ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada() {
    No* atual = this->primeiro;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->getProximo();
        delete temp;
    }
}

// O(1) - insere diretamente no início
void ListaSimplesmenteEncadeada::inserirNoInicio(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    
    if (this->tamanho == 0) {
        this->primeiro = novoNo;
        this->ultimo = novoNo;
    } else {
        novoNo->setProximo(this->primeiro);
        this->primeiro = novoNo;
    }
    
    this->tamanho++;
}

// O(1) - insere diretamente no final (temos ponteiro para o último)
void ListaSimplesmenteEncadeada::inserirNoFinal(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    
    if (this->tamanho == 0) {
        this->primeiro = novoNo;
        this->ultimo = novoNo;
    } else {
        this->ultimo->setProximo(novoNo);
        this->ultimo = novoNo;
    }
    
    this->tamanho++;
}

// O(1) - remove diretamente do início
bool ListaSimplesmenteEncadeada::removerPrimeiro() {
    if (this->tamanho == 0) {
        return false;
    }
    
    No* temp = this->primeiro;
    
    if (this->tamanho == 1) {
        this->primeiro = nullptr;
        this->ultimo = nullptr;
    } else {
        this->primeiro = this->primeiro->getProximo();
    }
    
    delete temp;
    this->tamanho--;
    return true;
}

// O(n) - precisa percorrer até o penúltimo elemento
bool ListaSimplesmenteEncadeada::removerUltimo() {
    if (this->tamanho == 0) {
        return false;
    }
    
    if (this->tamanho == 1) {
        delete this->primeiro;
        this->primeiro = nullptr;
        this->ultimo = nullptr;
        this->tamanho--;
        return true;
    }
    
    // encontrar o penúltimo nó
    No* atual = this->primeiro;
    while (atual->getProximo() != this->ultimo) {
        atual = atual->getProximo();
    }
    
    delete this->ultimo;
    this->ultimo = atual;
    this->ultimo->setProximo(nullptr);
    this->tamanho--;
    return true;
}

// O(n) - busca linear para encontrar o elemento
bool ListaSimplesmenteEncadeada::removerPeloId(int id) {
    if (this->tamanho == 0) {
        return false;
    }
    
    // se for o primeiro elemento
    if (this->primeiro->getID() == id) {
        return removerPrimeiro();
    }
    
    // encontrar o nó anterior
    No* anterior = this->primeiro;
    while (anterior->getProximo() != nullptr && anterior->getProximo()->getID() != id) {
        anterior = anterior->getProximo();
    }
    
    if (anterior->getProximo() == nullptr) { // id não existe
        return false;
    }
    
    No* paraRemover = anterior->getProximo();
    anterior->setProximo(paraRemover->getProximo());
    
    if (paraRemover == this->ultimo) {
        this->ultimo = anterior;
    }
    
    delete paraRemover;
    this->tamanho--;
    return true;
}

// O(n) - busca linear sequencial
Elemento* ListaSimplesmenteEncadeada::buscarPeloId(int id) {
    No* atual = this->primeiro;
    while (atual != nullptr) {
        if (atual->getID() == id) {
            return atual;
        }
        atual = atual->getProximo();
    }
    return nullptr;
}

// O(n) - busca linear para encontrar o elemento
bool ListaSimplesmenteEncadeada::alterarPeloId(int id, const std::string& novo_valor) {
    No* atual = this->primeiro;
    while (atual != nullptr) {
        if (atual->getID() == id) {
            atual->setValor(novo_valor);
            return true;
        }
        atual = atual->getProximo();
    }
    return false;
}

int ListaSimplesmenteEncadeada::getTamanho() const {
    return this->tamanho;
}

void ListaSimplesmenteEncadeada::imprimirLista() {
    cout << "Lista Simplesmente Encadeada (Tamanho: " << this->tamanho << "):" << endl;
    No* atual = this->primeiro;
    int posicao = 0;
    
    while (atual != nullptr) {
        cout << "  Posicao " << posicao << ": ";
        atual->imprimirInfo();
        cout << endl;
        atual = atual->getProximo();
        posicao++;
    }
    cout << endl;
} 