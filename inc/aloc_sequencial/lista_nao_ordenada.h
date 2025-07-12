#ifndef LISTA_NAO_ORDENADA_H
#define LISTA_NAO_ORDENADA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class ListaNaoOrdenada {
private:
    class Item : public Elemento {
    private:
        std::string valor;
    
    public:
        Item(int id, const std::string& valor);
        ~Item();

        void setValor(const std::string& valor);
        std::string getValor() const;

        void imprimirInfo() override;
    };

    Elemento** elementos;
    int capacidade;
    int tamanho;
    
    void redimensionar();

public:
    ListaNaoOrdenada(int capacidade_inicial = 10);
    ~ListaNaoOrdenada();
    
    void inserirNoInicio(int id, const std::string& valor); // O(n)
    void inserirNoFinal(int id, const std::string& valor); // O(1)

    bool removerPrimeiro(); // O(n)
    bool removerUltimo(); // O(1)

    bool removerPeloId(int id); // O(n)
    Elemento* buscarPeloId(int id); // O(n)
    bool alterarPeloId(int id, const std::string& novo_valor); // O(n)
    
    int getTamanho() const;
    void imprimirLista();
};

#endif