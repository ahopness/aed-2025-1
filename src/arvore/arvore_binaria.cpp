#include <string>

#include "../../inc/arvore/arvore_binaria.h"

using std::cout;
using std::endl;

// CLASSE NÓ

ArvoreBinaria::No::No(int id, const std::string& valor) {
    this->ID = id;
    this->valor = valor;
    this->esquerda = nullptr;
    this->direita = nullptr;
}

ArvoreBinaria::No::~No() {
}

void ArvoreBinaria::No::setValor(const std::string& valor) {
    this->valor = valor;
}

std::string ArvoreBinaria::No::getValor() const {
    return this->valor;
}

ArvoreBinaria::No* ArvoreBinaria::No::getEsquerda() const {
    return this->esquerda;
}

void ArvoreBinaria::No::setEsquerda(No* esquerda) {
    this->esquerda = esquerda;
}

ArvoreBinaria::No* ArvoreBinaria::No::getDireita() const {
    return this->direita;
}

void ArvoreBinaria::No::setDireita(No* direita) {
    this->direita = direita;
}

void ArvoreBinaria::No::imprimirInfo() {
    cout << "ID: " << this->ID << ", valor: " << this->valor << endl;
}

// CLASSE ÁRVORE BINÁRIA (DE BUSCA)

ArvoreBinaria::ArvoreBinaria() {
    this->raiz = nullptr;
}

ArvoreBinaria::~ArvoreBinaria() {
    destruirRecursivo(this->raiz);
}

void ArvoreBinaria::destruirRecursivo(No* no) {
    if (no) {
        destruirRecursivo(no->getEsquerda());
        destruirRecursivo(no->getDireita());
        delete no;
    }
}

// O(log n)
void ArvoreBinaria::inserir(int id, const std::string& valor) {
    No* novoNo = new No(id, valor);
    if (!this->raiz) {
        this->raiz = novoNo;
    } else {
        inserirRecursivo(this->raiz, novoNo);
    }
}

void ArvoreBinaria::inserirRecursivo(No* noAtual, No* novoNo) {
    if (novoNo->getID() < noAtual->getID()) {
        if (noAtual->getEsquerda() == nullptr) {
            noAtual->setEsquerda(novoNo);
        } else {
            inserirRecursivo(noAtual->getEsquerda(), novoNo);
        }
    } else {
        if (noAtual->getDireita() == nullptr) {
            noAtual->setDireita(novoNo);
        } else {
            inserirRecursivo(noAtual->getDireita(), novoNo);
        }
    }
}

// O(log n)
bool ArvoreBinaria::remover(int id) {
    if (!this->raiz) {
        return false;
    }

    No* resultado = removerRecursivo(this->raiz, id);
    if (resultado != this->raiz || (this->raiz && this->raiz->getID() == id)) {
        this->raiz = resultado;
        return true;
    }
    return false;
}

ArvoreBinaria::No* ArvoreBinaria::removerRecursivo(No* no, int id) {
    if (!no) {
        return nullptr;
    }
    if (id < no->getID()) {
        no->setEsquerda(removerRecursivo(no->getEsquerda(), id));
    } else if (id > no->getID()) {
        no->setDireita(removerRecursivo(no->getDireita(), id));
    } else {
        // No encontrado
        if (!no->getEsquerda()) {
            No* temp = no->getDireita();
            delete no;
            return temp;
        } else if (!no->getDireita()) {
            No* temp = no->getEsquerda();
            delete no;
            return temp;
        }
        // Nó com dois filhos - encontrar sucessor inorder (menor da subárvore direita)
        No* temp = encontrarMinimo(no->getDireita());
        
        // Copiar dados do sucessor para este nó
        no->setValor(temp->getValor());
        // Não podemos alterar o ID, então vamos criar um novo nó
        No* novoNo = new No(temp->getID(), temp->getValor());
        novoNo->setEsquerda(no->getEsquerda());
        novoNo->setDireita(removerRecursivo(no->getDireita(), temp->getID()));
        delete no;
        return novoNo;
    }
    return no;
}

ArvoreBinaria::No* ArvoreBinaria::encontrarMinimo(No* no) {
    while (no && no->getEsquerda()) {
        no = no->getEsquerda();
    }
    return no;
}

// O(log n)
Elemento* ArvoreBinaria::buscar(int id) {
    return buscarRecursivo(this->raiz, id);
}

Elemento* ArvoreBinaria::buscarRecursivo(No* no, int id) {
    if (!no) {
        return nullptr;
    }
    if (no->getID() == id) {
        return no;
    } else if (id < no->getID()) {
        return buscarRecursivo(no->getEsquerda(), id);
    } else {
        return buscarRecursivo(no->getDireita(), id);
    }
}

void ArvoreBinaria::imprimir() const {
    cout << "Arvore Binaria (em ordem):" << endl;
    if (!this->raiz) {
        cout << "  Arvore vazia" << endl;
    } else {
        imprimirRecursivo(this->raiz);
    }
    cout << endl;
}

void ArvoreBinaria::imprimirRecursivo(No* no) const {
    if (no) {
        imprimirRecursivo(no->getEsquerda());
        cout << "  ";
        no->imprimirInfo();
        imprimirRecursivo(no->getDireita());
    }
}

