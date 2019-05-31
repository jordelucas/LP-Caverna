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
    Quadrado getInicio();
    Quadrado getFim();
    void getVizinhos(Quadrado * array, Quadrado * quadAtual);

    /*
    void resetar();
    */
};

#endif