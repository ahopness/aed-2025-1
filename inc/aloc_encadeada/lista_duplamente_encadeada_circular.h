#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include <iostream>
#include <string>

#include "../elemento.h"

class ListaDuplamenteEncadeadaCircular {
private:
    class No : public Elemento {
    private:
        std::string valor;
        No* proximo;
        No* anterior;
    
    public:
        No(int id, const std::string& valor);
        ~No();

        void setValor(const std::string& valor);
        std::string getValor() const;

        void setProximo(No* proximo);
        No* getProximo() const;
        void setAnterior(No* anterior);
        No* getAnterior() const;

        void imprimirInfo() override;
    };

    No* primeiro;
    No* ultimo;
    int tamanho;

public:
    ListaDuplamenteEncadeadaCircular();
    ~ListaDuplamenteEncadeadaCircular();
    
    void inserirNoInicio(int id, const std::string& valor); // O(1)
    void inserirNoFinal(int id, const std::string& valor); // O(1)

    bool removerPrimeiro(); // O1)
    bool removerUltimo(); // O(1)
    
    bool removerPeloId(int id); // O(n)
    Elemento* buscarPeloId(int id); // O(n)
    bool alterarPeloId(int id, const std::string& novo_valor); // O(n)
    
    int getTamanho() const;
    void imprimirLista();
};

#endif 