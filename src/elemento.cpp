#include <iostream>

#include "elemento.h"

Elemento::Elemento() {
    this->ID = 0;
}

Elemento::~Elemento() {
}

int Elemento::getID() const {
    return this->ID;
}

void Elemento::imprimirInfo() {
    std::cout << "ID: " << this->ID << std::endl;
}
