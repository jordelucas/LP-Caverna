#include "Caverna.h"

Caverna::Caverna() {}

Caverna::~Caverna() {
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            delete caverna_[l][c];
        }
    delete[] caverna_[l];
    }
    delete[] caverna_;
}

void Caverna::carregar(std::ifstream & arq_in){
    int tipo;
    
    arq_in >> qtdLinhas;
    arq_in >> qtdColunas;

    caverna_ = new Quadrado**[qtdLinhas];
    
    for (int l = 0; l < qtdLinhas; ++l) {
        caverna_[l] = new Quadrado*[qtdColunas];
        for (int c = 0; c < qtdColunas; ++c) {
            arq_in >> tipo;
            caverna_[l][c] = new Quadrado(l, c, tipo);
        }
    }
}

Quadrado * Caverna::getInicio(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            if(caverna_[l][c]->getTipo() == 2){
                return caverna_[l][c];
            }
        }
    }    
    return nullptr;
} 

Quadrado * Caverna::getFim(){

    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            if(caverna_[l][c]->getTipo() == 3){
                return caverna_[l][c];
            }
        }
    }    
    return nullptr;
} 

Quadrado * Caverna::getVizinhos( Quadrado * quadrado, int op){
    switch (op)
    {
    case 0:
        if(quadrado->getColuna() != 0){
            return (caverna_[quadrado->getLinha()][quadrado->getColuna()-1]);
        }else{
            return nullptr;
        }
        break;
    case 1:
        if(quadrado->getColuna() != qtdColunas-1){
            return  (caverna_[quadrado->getLinha()][quadrado->getColuna()+1]);
        }else{
            return nullptr;
        }
        break;
    case 2:
        if(quadrado->getLinha() != 0){
            return  (caverna_[quadrado->getLinha()-1][quadrado->getColuna()]);
        }else{
            return nullptr;
        }
        break;
    case 3:
        if(quadrado->getLinha() != qtdLinhas-1){
            return  (caverna_[quadrado->getLinha()+1][quadrado->getColuna()]);
        }else{
            return nullptr;
        }
        break;

    default:
        return nullptr;
        break;
    }
}

void Caverna::toString(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            std::cout << caverna_[l][c]->toString();
        }
        std::cout << "\n";
    }
    
}

void Caverna::resetar(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            caverna_[l][c]->resetar();
        }
    }    
}