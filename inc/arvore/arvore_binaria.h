#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class ArvoreBinaria {
private:
    class No : public Elemento {
        private:
            std::string valor;
            No* esquerda;
            No* direita;

        public:
            No(int id, const std::string& valor);
            ~No();

            void setValor(const std::string& valor);
            std::string getValor() const;

            No* getEsquerda() const;
            void setEsquerda(No* esquerda);
            No* getDireita() const;
            void setDireita(No* direita);

            void imprimirInfo() override;
    };

    No* raiz;

    void inserirRecursivo(No* noAtual, No* novoNo);
    Elemento* buscarRecursivo(No* no, int id);
    No* removerRecursivo(No* no, int id);
    No* encontrarMinimo(No* no);
    void imprimirRecursivo(No* no) const;
    void destruirRecursivo(No* no);
public: 
    ArvoreBinaria();
    ~ArvoreBinaria();

    void inserir(int id, const std::string& valor); // O(log n)
    bool remover(int id); // O(log n)
    Elemento* buscar(int id); // O(log n)
    void imprimir() const;
};

#endif