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
    
    void inserirNoInicio(int id, const std::string& valor);
    void inserirNoFinal(int id, const std::string& valor);

    bool removerPrimeiro();
    bool removerUltimo();
    
    bool removerPeloId(int id);
    Elemento* buscarPeloId(int id);
    bool alterarPeloId(int id, const std::string& novo_valor);
    
    int getTamanho() const;
    void imprimirLista();
};

#endif 