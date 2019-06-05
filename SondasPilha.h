#ifndef SONDAS_PILHA_H
#define SONDAS_PILHA_H

#include <iostream>
#include <cstdlib>

#include "Quadrado.h"
#include "Caverna.h"
#include "Stack.h"

class SondasPilha
{
private:
    Caverna * caverna_;
    Stack<Quadrado*> * pilha;

public:
    SondasPilha(Caverna * caverna);
    ~SondasPilha();
    void esvaziarCaminhos();
    bool possuiCaminhos();
    Quadrado* proximoCaminho();
    bool estaFinalizado();
    void getCaminho();
    Quadrado* passo();
    void encontrarCaminho();
};
#endif // !SONDAS_PILHA_H