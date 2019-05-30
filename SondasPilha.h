#ifndef SONDAS_PILHA_H
#define SONDAS_PILHA_H

#include <iostream>

#include "Quadrado.h"
#include "Caverna.h"
#include "Stack.h"

class SondasPilha
{
private:
    Caverna caverna_;
    Stack<Quadrado> pilha;

public:
    SondasPilha(Caverna caverna);
    ~SondasPilha();
    void esvaziarCaminhos();
    bool possuiCaminhos();
    Quadrado proximoCaminho();
    bool estaFinalizado();
    std::string getCaminho();
    Quadrado passo();
};
#endif // !SONDAS_PILHA_H