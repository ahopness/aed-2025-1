#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class ListaDuplamenteEncadeada {
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
    int tamanho;
    
    void inserirNoFinalRecursivo(No* atual, int id, const std::string& valor);
    No* encontrarUltimoRecursivo(No* atual);
    Elemento* buscarPeloIdRecursivo(No* atual, int id);
    bool alterarPeloIdRecursivo(No* atual, int id, const std::string& novo_valor);
    void imprimirListaRecursivo(No* atual, int posicao);

public:
    ListaDuplamenteEncadeada();
    ~ListaDuplamenteEncadeada();
    
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