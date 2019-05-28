#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Quadrado.h"
#include "Caverna.h"

Quadrado::Quadrado(int linha, int coluna, char tipo)
: linha_(linha), coluna_(coluna), tipo_(tipo) {}

int Quadrado::getLinha(){
    return linha_;
}
int Quadrado::getColuna(){
    return coluna_;
}
int Quadrado::getTipo(){
    return tipo_;
}

std::string Quadrado::toString(){
    switch (getTipo()){
        case '0':
            return "_";
            break;

        case '1':
            return "#";
            break;

        case '2':
            return "I";
            break;

        case '3':
            return "F";
            break;
            
        default:
            return "";
    }
}