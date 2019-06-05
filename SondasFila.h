#ifndef SONDAS_FILA_H
#define SONDAS_FILA_H

#include <iostream>
#include <cstdlib>

#include "Quadrado.h"
#include "Caverna.h"
#include "Queue.h"
#include "Stack.h"

class SondasFila
{
private:
    Caverna * caverna_;
    Queue<Quadrado*> * fila_;

public:
    SondasFila(Caverna * caverna);
    ~SondasFila();
    void esvaziarCaminhos();
    bool possuiCaminhos();
    Quadrado* proximoCaminho();
    bool estaFinalizado();
    void getCaminho();
    Quadrado* passo();
    void encontrarCaminho();
};
#endif