#ifdef ARVOREBIN_H
#define ARVOREBIN_H

#include <iostream>
#include <string>

#include "../elemento.h"

class ArvoreBin {
private:
    class Item : public Elemento {
        private:
            std::string valor;
            Item* esquerda;
            Item* direita;

        public:
            Item(int id, const std::string& valor);
            ~Item();
            void setValor(const std::string& valor);
            std::string getValor() const;
            void imprimirInfo() override;
            Item* getEsquerda() const;
            Item* getDireita() const;
            void setEsquerda(Item* esquerda);
            void setDireita(Item* direita);
    };
public: 
    ArvoreBin();
    ~ArvoreBin();

    void inserir(int id, const std::string& valor);
    bool remover(int id);
    Elemento* buscar(int id) const;
    void imprimir() const;

};

#endif // ARVOREBIN_H