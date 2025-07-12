#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class Fila {
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
        Fila(int capacidade = 3);
        ~Fila();

        bool Enfileirar(int id, const std::string& valor); // O(1)
        bool Desemfileirar(); // O(n)
        Elemento* ConsultarInicio();
        Elemento* ConsultarFinal();
        bool FilaCheia() const;
        bool FilaVazia() const;

        int getTamanho() const;
        void imprimirFila();
};

#endif //FILA_H