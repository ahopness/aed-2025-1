#include "../../inc/aloc_encadeada/lista_duplamente_encadeada.h"

using std::cout;
using std::endl;

ListaDuplamenteEncadeada::No::No(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
    this->proximo = nullptr;
    this->anterior = nullptr;
}
ListaDuplamenteEncadeada::No::~No() {
}

void ListaDuplamenteEncadeada::No::setValor(const std::string& valor) {
    this->valor = valor;
}
std::string ListaDuplamenteEncadeada::No::getValor() const {
    return this->valor;
}

void ListaDuplamenteEncadeada::No::setProximo(No* proximo) {
    this->proximo = proximo;
}
ListaDuplamenteEncadeada::No* ListaDuplamenteEncadeada::No::getProximo() const {
    return this->proximo;
}
void ListaDuplamenteEncadeada::No::setAnterior(No* anterior) {
    this->anterior = anterior;
}
ListaDuplamenteEncadeada::No* ListaDuplamenteEncadeada::No::getAnterior() const {
    return this->anterior;
}

void ListaDuplamenteEncadeada::No::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor;
}

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
    this->primeiro = nullptr;
    this->tamanho = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    No* atual = this->primeiro;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->getProximo();
        delete temp;
    }
}

// O(1)
void ListaDuplamenteEncadeada::inserirNoInicio(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    
    if (this->tamanho == 0) {
        this->primeiro = novoNo;
    } else {
        novoNo->setProximo(this->primeiro);
        this->primeiro->setAnterior(novoNo);
        this->primeiro = novoNo;
    }
    
    this->tamanho++;
}

void ListaDuplamenteEncadeada::inserirNoFinalRecursivo(No* atual, int id, const std::string& valor) {
    if (atual->getProximo() == nullptr) {
        No* novoNo = new No(id, valor);
        atual->setProximo(novoNo);
        novoNo->setAnterior(atual);
    } else {
        inserirNoFinalRecursivo(atual->getProximo(), id, valor);
    }
}

// O(n)
void ListaDuplamenteEncadeada::inserirNoFinal(int id, const std::string& valor) {
    if (this->tamanho == 0) {
        inserirNoInicio(id, valor);
    } else {
        inserirNoFinalRecursivo(this->primeiro, id, valor);
        this->tamanho++;
    }
}

// O(1)
bool ListaDuplamenteEncadeada::removerPrimeiro() {
    if (this->tamanho == 0) {
        return false;
    }
    
    No* temp = this->primeiro;
    
    if (this->tamanho == 1) {
        this->primeiro = nullptr;
    } else {
        this->primeiro = this->primeiro->getProximo();
        this->primeiro->setAnterior(nullptr);
    }
    
    delete temp;
    this->tamanho--;
    return true;
}

ListaDuplamenteEncadeada::No* ListaDuplamenteEncadeada::encontrarUltimoRecursivo(No* atual) {
    if (atual->getProximo() == nullptr) {
        return atual;
    }
    return encontrarUltimoRecursivo(atual->getProximo());
}

// O(n)
bool ListaDuplamenteEncadeada::removerUltimo() {
    if (this->tamanho == 0) {
        return false;
    }
    
    if (this->tamanho == 1) {
        delete this->primeiro;
        this->primeiro = nullptr;
        this->tamanho--;
        return true;
    }
    
    No* ultimo = encontrarUltimoRecursivo(this->primeiro);
    ultimo->getAnterior()->setProximo(nullptr);
    delete ultimo;
    this->tamanho--;
    return true;
}

// O(n)
bool ListaDuplamenteEncadeada::removerPeloId(int id) {
    if (this->tamanho == 0) {
        return false;
    }
    
    if (this->primeiro->getID() == id) {
        return removerPrimeiro();
    }
    
    No* atual = this->primeiro;
    while (atual != nullptr && atual->getID() != id) {
        atual = atual->getProximo();
    }
    
    if (atual == nullptr) {
        return false;
    }
    
    if (atual->getProximo() == nullptr) {
        atual->getAnterior()->setProximo(nullptr);
    } else {
        atual->getAnterior()->setProximo(atual->getProximo());
        atual->getProximo()->setAnterior(atual->getAnterior());
    }
    
    delete atual;
    this->tamanho--;
    return true;
}

Elemento* ListaDuplamenteEncadeada::buscarPeloIdRecursivo(No* atual, int id) {
    if (atual == nullptr) {
        return nullptr;
    }
    if (atual->getID() == id) {
        return atual;
    }
    return buscarPeloIdRecursivo(atual->getProximo(), id);
}

// O(n)
Elemento* ListaDuplamenteEncadeada::buscarPeloId(int id) {
    return buscarPeloIdRecursivo(this->primeiro, id);
}

bool ListaDuplamenteEncadeada::alterarPeloIdRecursivo(No* atual, int id, const std::string& novo_valor) {
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
bool ListaDuplamenteEncadeada::alterarPeloId(int id, const std::string& novo_valor) {
    return alterarPeloIdRecursivo(this->primeiro, id, novo_valor);
}

int ListaDuplamenteEncadeada::getTamanho() const {
    return this->tamanho;
}

void ListaDuplamenteEncadeada::imprimirListaRecursivo(No* atual, int posicao) {
    if (atual != nullptr) {
        cout << "  Posicao " << posicao << ": ";
        atual->imprimirInfo();
        cout << endl;
        imprimirListaRecursivo(atual->getProximo(), posicao + 1);
    }
}

// O(n)
void ListaDuplamenteEncadeada::imprimirLista() {
    cout << "Lista Duplamente Encadeada (Tamanho: " << this->tamanho << "):" << endl;
    imprimirListaRecursivo(this->primeiro, 0);
    cout << endl;
} 