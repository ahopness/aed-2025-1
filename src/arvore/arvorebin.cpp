#include "arvorebin.h"
#include <string>

ArvoreBin::ArvoreBin() : raiz(nullptr) { }

ArvoreBin::~ArvoreBin() {
    liberar();
}

void ArvoreBin::liberar() {
    liberarRecursivo(raiz);
    raiz = nullptr;
}

void ArvoreBin::liberarRecursivo(Item* no) {
    if (no) {
        liberarRecursivo(no->getEsquerda());
        liberarRecursivo(no->getDireita());
        delete no;
    }
}

void ArvoreBin::inserir(int id, const std::string& valor) {
    Item* novoItem = new Item(id, valor);
    if (!raiz) {
        raiz = novoItem;
    } else {
        inserirRecursivo(raiz, novoItem);
    }
}

void ArvoreBin::inserirRecursivo(Item* no, Item* novoItem) {
    if (novoItem->getID() < no->getID()) {
        if (no->getEsquerda() == nullptr) {
            no->setEsquerda(novoItem);
        } else {
            inserirRecursivo(no->getEsquerda(), novoItem);
        }
    } else {
        if (no->getDireita() == nullptr) {
            no->setDireita(novoItem);
        } else {
            inserirRecursivo(no->getDireita(), novoItem);
        }
    }
}

Elemento* ArvoreBin::buscar(int id) const {
    return buscarRecursivo(raiz, id);
}

Elemento* ArvoreBin::buscarRecursivo(Item* no, int id) const {
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

bool ArvoreBin::remover(int id) {
    if (!raiz) {
        return false;
    }
    raiz = removerRecursivo(raiz, id);
    return true;
}

ArvoreBin::Item* ArvoreBin::removerRecursivo(Item* no, int id) {
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
            Item* temp = no->getDireita();
            delete no;
            return temp;
        } else if (!no->getDireita()) {
            Item* temp = no->getEsquerda();
            delete no;
            return temp;
        }
        // No com dois filhos
        Item* temp = encontrarMinimo(no->getDireita());
        no->setValor(temp->getValor());
        no->setID(temp->getID());
        no->setDireita(removerRecursivo(no->getDireita(), temp->getID()));
    }
    return no;
}

ArvoreBin::Item* ArvoreBin::encontrarMinimo(Item* no) {
    while (no && no->getEsquerda()) {
        no = no->getEsquerda();
    }
    return no;
}

void ArvoreBin::imprimir() const {
    imprimirRecursivo(raiz);
}

void ArvoreBin::imprimirRecursivo(Item* no) const {
    if (no) {
        imprimirRecursivo(no->getEsquerda());
        no->imprimirInfo();
        imprimirRecursivo(no->getDireita());
    }
}

