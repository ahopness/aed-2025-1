#ifndef LISTA_SIMPLESMENTE_ENCADEADA_H
#define LISTA_SIMPLESMENTE_ENCADEADA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class ListaSimplesmenteEncadeada {
private:
    class No : public Elemento {
    private:
        std::string valor;
        No* proximo;
    
    public:
        No(int id, const std::string& valor);
        ~No();

        void setValor(const std::string& valor);
        std::string getValor() const;

        void setProximo(No* proximo);
        No* getProximo() const;

        void imprimirInfo() override;
    };

    No* primeiro;
    int tamanho;
    
    void inserirNoFinalRecursivo(No* atual, int id, const std::string& valor);
    No* encontrarPenultimoRecursivo(No* atual);
    Elemento* buscarPeloIdRecursivo(No* atual, int id);
    bool alterarPeloIdRecursivo(No* atual, int id, const std::string& novo_valor);
    void imprimirListaRecursivo(No* atual, int posicao);

public:
    ListaSimplesmenteEncadeada();
    ~ListaSimplesmenteEncadeada();
    
    void inserirNoInicio(int id, const std::string& valor); // O(1)
    void inserirNoFinal(int id, const std::string& valor); // O(n)

    bool removerPrimeiro(); // O(1)
    bool removerUltimo(); // O(n)
    
    bool removerPeloId(int id); // O(n)
    Elemento* buscarPeloId(int id); // O(n)
    bool alterarPeloId(int id, const std::string& novo_valor); // O(n)
    
    int getTamanho() const;
    void imprimirLista();
};

#endif