#include "lista_simplesmente_encadeada.h"

using std::cout;
using std::endl;

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

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() {
    this->primeiro = nullptr;
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

// O(1)
void ListaSimplesmenteEncadeada::inserirNoInicio(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    novoNo->setProximo(this->primeiro);
    this->primeiro = novoNo;
    this->tamanho++;
}

void ListaSimplesmenteEncadeada::inserirNoFinalRecursivo(No* atual, int id, const std::string& valor) {
    if (atual->getProximo() == nullptr) {
        atual->setProximo(new No(id, valor));
    } else {
        inserirNoFinalRecursivo(atual->getProximo(), id, valor);
    }
}

// O(n)
void ListaSimplesmenteEncadeada::inserirNoFinal(int id, const std::string& valor) {
    if (this->tamanho == 0) {
        inserirNoInicio(id, valor);
    } else {
        inserirNoFinalRecursivo(this->primeiro, id, valor);
        this->tamanho++;
    }
}

// O(1)
bool ListaSimplesmenteEncadeada::removerPrimeiro() {
    if (this->tamanho == 0) {
        return false;
    }
    
    No* temp = this->primeiro;
    this->primeiro = this->primeiro->getProximo();
    delete temp;
    this->tamanho--;
    return true;
}

ListaSimplesmenteEncadeada::No* ListaSimplesmenteEncadeada::encontrarPenultimoRecursivo(No* atual) {
    if (atual == nullptr || atual->getProximo() == nullptr || atual->getProximo()->getProximo() == nullptr) {
        return atual;
    }
    return encontrarPenultimoRecursivo(atual->getProximo());
}

// O(n)
bool ListaSimplesmenteEncadeada::removerUltimo() {
    if (this->tamanho == 0) {
        return false;
    }
    
    if (this->tamanho == 1) {
        delete this->primeiro;
        this->primeiro = nullptr;
        this->tamanho--;
        return true;
    }
    
    No* penultimo = encontrarPenultimoRecursivo(this->primeiro);
    delete penultimo->getProximo();
    penultimo->setProximo(nullptr);
    this->tamanho--;
    return true;
}

// O(n)
bool ListaSimplesmenteEncadeada::removerPeloId(int id) {
    if (this->tamanho == 0) {
        return false;
    }
    
    if (this->primeiro->getID() == id) {
        return removerPrimeiro();
    }
    
    No* anterior = this->primeiro;
    while (anterior->getProximo() != nullptr && anterior->getProximo()->getID() != id) {
        anterior = anterior->getProximo();
    }
    
    if (anterior->getProximo() == nullptr) {
        return false;
    }
    
    No* paraRemover = anterior->getProximo();
    anterior->setProximo(paraRemover->getProximo());
    
    delete paraRemover;
    this->tamanho--;
    return true;
}

Elemento* ListaSimplesmenteEncadeada::buscarPeloIdRecursivo(No* atual, int id) {
    if (atual == nullptr) {
        return nullptr;
    }
    if (atual->getID() == id) {
        return atual;
    }
    return buscarPeloIdRecursivo(atual->getProximo(), id);
}

// O(n)
Elemento* ListaSimplesmenteEncadeada::buscarPeloId(int id) {
    return buscarPeloIdRecursivo(this->primeiro, id);
}

bool ListaSimplesmenteEncadeada::alterarPeloIdRecursivo(No* atual, int id, const std::string& novo_valor) {
    if (atual == nullptr) {
        return false;
    }
    if (atual->getID() == id) {
        atual->setValor(novo_valor);
        return true;
    }
    return alterarPeloIdRecursivo(atual->getProximo(), id, novo_valor);
}

// O(n)
bool ListaSimplesmenteEncadeada::alterarPeloId(int id, const std::string& novo_valor) {
    return alterarPeloIdRecursivo(this->primeiro, id, novo_valor);
}

int ListaSimplesmenteEncadeada::getTamanho() const {
    return this->tamanho;
}

void ListaSimplesmenteEncadeada::imprimirListaRecursivo(No* atual, int posicao) {
    if (atual != nullptr) {
        cout << "  Posicao " << posicao << ": ";
        atual->imprimirInfo();
        cout << endl;
        imprimirListaRecursivo(atual->getProximo(), posicao + 1);
    }
}

// O(n)
void ListaSimplesmenteEncadeada::imprimirLista() {
    cout << "Lista Simplesmente Encadeada (Tamanho: " << this->tamanho << "):" << endl;
    imprimirListaRecursivo(this->primeiro, 0);
    cout << endl;
} 