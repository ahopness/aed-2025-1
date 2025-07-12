#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class ListaOrdenada {
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
    int encontrarPosicaoInsercao(int id);

public:
    ListaOrdenada(int capacidade_inicial = 10);
    ~ListaOrdenada();
    
    void inserir(int id, const std::string& valor); // O(n)

    bool removerPrimeiro(); // O(n)
    bool removerUltimo(); // O(1)

    bool removerPeloId(int id); // O(n)
    Elemento* buscarPeloId(int id); // O(log n)
    bool alterarPeloId(int id, const std::string& novo_valor); // O(log n)
    
    int getTamanho() const;
    void imprimirLista();
};

#endif