#ifndef PILHA_ENCADEADA_H
#define PILHA_ENCADEADA_H

#include <iostream>
#include <string>

#include "../elemento.h"

class PilhaEnc {
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
        PilhaEnc();
        ~PilhaEnc();

        void Empilhar(int id, const std::string& value);
        bool Desempilhar();
        Elemento* ConsultarTopo();
        bool PilhaVazia() const;

        int getTamanho() const;
        void imprimirPilha();
};

#endif //PILHA_ENCADEADA_H