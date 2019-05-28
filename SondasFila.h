#ifndef SONDAS_FILA_H
#define SONDAS_FILA_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>

#include "Quadrado.h"
#include "Caverna.h"

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