#ifndef QUADRADO_H
#define QUADRADO_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Quadrado.h"

class Caverna{
private:
    //Quadrado quadrados_[][]; COM ERRO
public:
    Caverna();
    void carregar(std::ifstream arquivo);
    Quadrado::Quadrado getVizinhos(Quadrado::Quadrado quadrado); //ERRO
    Quadrado::Quadrado getInicio(Quadrado::Quadrado quadrado); //ERRO
    Quadrado::Quadrado getFim(Quadrado::Quadrado quadrado); //ERRO
    void resetar();
    std::string toString();
};

Caverna::Caverna(){}

void carregar(std::ifstream arquivo){

}
Quadrado::Quadrado getVizinhos(Quadrado::Quadrado quadrado){

} //ERRO
Quadrado::Quadrado getInicio(Quadrado::Quadrado quadrado){

} //ERRO
Quadrado::Quadrado getFim(Quadrado::Quadrado quadrado){

} //ERRO
void resetar(){

}
std::string toString(){
    
}
#endif