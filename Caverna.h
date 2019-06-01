#ifndef CAVERNA_H
#define CAVERNA_H

#include <iostream>
#include <fstream>

#include "Quadrado.h"

class Caverna{
private:
    Quadrado *** caverna_;
    int qtdLinhas;
    int qtdColunas;

public: 
    Caverna();
    ~Caverna();
    void carregar(std::ifstream &);
    void toString();
    Quadrado * getInicio();
    Quadrado * getFim();
    Quadrado * getVizinhos( Quadrado * quadAtual, int op);

    /*
    void resetar();
    */
};

#endif