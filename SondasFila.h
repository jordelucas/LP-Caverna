#ifndef SONDAS_FILA_H
#define SONDAS_FILA_H

#include <iostream>

#include "Quadrado.h"
#include "Caverna.h"
#include "Queue.h"

class SondasFila
{
private:
    Caverna caverna_;
public:
    SondasFila(Caverna caverna);
    void esvaziarCaminhos();
    bool possuiCaminhos();
    Quadrado proximoCaminho();
    bool estaFinalizado();
    std::string getCaminho();
    Quadrado passo();
};

#endif // !SONDAS_FILA_H