#ifndef ELEMENTO_H
#define ELEMENTO_H

class Elemento {

protected:
    int ID;

public:
    Elemento();
    virtual ~Elemento();

    int getID() const;
    virtual void imprimirInfo();
};

#endif