#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class Pilha {
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

    public:
        Pilha(int capacidade = 3);
        ~Pilha();

        bool Empilhar(int id, const std::string& valor);
        bool Desempilhar();
        Elemento* ConsultarTopo();
        bool PilhaCheia() const;
        bool PilhaVazia() const;
        
        int getTamanho() const;
        void imprimirPilha();
};

#endif //PILHA_H