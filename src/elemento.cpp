#include <iostream>

#include "elemento.h"

using std::cout;
using std::endl;

Elemento::Elemento() {
    this->ID = 0;
}

Elemento::~Elemento() {
}

int Elemento::getID() const {
    return this->ID;
}

void Elemento::imprimirInfo() {
    cout << "ID: " << this->ID << endl;
}
