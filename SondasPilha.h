#ifndef SONDAS_PILHA_H
#define SONDAS_PILHA_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>

#include "Quadrado.h"
#include "Caverna.h"

class SondasPilha
{
private:
    Caverna caverna_;
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