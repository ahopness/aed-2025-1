#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class FilaEnc {
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
        FilaEnc();
        ~FilaEnc();

        void Emfileirar(int id, const std::string& valor); // O(1)
        bool Desemfileirar(); // O(1)
        Elemento* ConsultarInicio();
        Elemento* ConsultarFinal();
        bool FilaVazia() const;

        int getTamanho() const;
        void imprimirFila();
};

#endif //FILA_ENCADEADA_H