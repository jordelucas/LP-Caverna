#include "Quadrado.h"
#include <iostream>

Quadrado::Quadrado() 
: linha_(-1), coluna_(-1), tipo_(-1), last_(nullptr), situacao(false) {}

Quadrado::Quadrado(int linha, int coluna, int tipo)
: linha_(linha), coluna_(coluna), tipo_(tipo), last_(nullptr), situacao(false) {}

int Quadrado::getLinha() {
    return linha_;
}

int Quadrado::getColuna() {
    return coluna_;
}

int Quadrado::getTipo() {
    return tipo_;
}

Quadrado * Quadrado::getAnterior() {
    return last_;
}

void Quadrado::setAnterior(Quadrado * quadrado) {
    last_ = quadrado;
}

bool Quadrado::getSituacao() {
    return situacao;
}

void Quadrado::setSituacao() {
    situacao = true;
}

char Quadrado::toString(){
    switch (getTipo()){
        case 0:
            return '-';
            break;

        case 1:
            return '#';
            break;

        case 2:
            return 'I';
            break;

        case 3:
            return 'F';
            break;
            
        default:
            return '0';
    }
}