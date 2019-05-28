#ifndef CAVERNA_H
#define CAVERNA_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Quadrado.h"

class Caverna{
private:
    Quadrado *quadrado_;
public: 
    Caverna();
    void carregar();
    Quadrado getVizinhos(Quadrado quadrado); //ERRO
    Quadrado getInicio(Quadrado quadrado); //ERRO
    Quadrado getFim(Quadrado quadrado);  //ERRO
    int getQuantLinhas();
    void resetar();
    std::string toString();
};

#endif