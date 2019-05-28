#ifndef CAVERNA_H
#define CAVERNA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Quadrado.h"

class Caverna{
private:
    Quadrado *** caverna_;
    int qtdLinhas;
    int QtdColunas;

public: 
    Caverna();
    ~Caverna();
    void carregar(std::ifstream &);
    void toString();
    Quadrado* getInicio();
    Quadrado* getFim();
    /*
    Quadrado getVizinhos(Quadrado quadrado); //ERRO
    void resetar();
    */
};

#endif