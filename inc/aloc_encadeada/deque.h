#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>

#include "../elemento.h"

class Deque {
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
        Deque();
        ~Deque();

        void InserirNoInicio(int id, const std::string& valor); // O(1)
        void InserirNoFinal(int id, const std::string& valor); // O(1)
        bool RemoverPrimeiro(); // O(1)
        bool RemoverUltimo(); // O(1)
        bool DequeVazio() const;

        int getTamanho() const;
        void imprimirDeque();
};

#endif //DEQUE_H