#include "Caverna.h"

Caverna::Caverna() {}
Caverna::~Caverna() {
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < QtdColunas; ++c) {
        //delete caverna_[l][c];
        }
        //delete[] caverna_[l];
    }
    //delete[] caverna_;
}

void Caverna::carregar(std::ifstream & arq_in){

    int tipo;
    
    arq_in >> qtdLinhas;
    arq_in >> QtdColunas;

    caverna_ = new Quadrado**[qtdLinhas];
    
    for (int l = 0; l < qtdLinhas; ++l) {
        caverna_[l] = new Quadrado*[QtdColunas];
        for (int c = 0; c < QtdColunas; ++c) {
            arq_in >> tipo;
            caverna_[l][c] = new Quadrado(l, c, tipo);
        }
    }
}

/*
Quadrado Caverna::getVizinhos(Quadrado quadrado){
    int qtdLinhas = quadrado_->getLinha();
    quadrado_ = new Quadrado**[qtdLinhas];
} 

Quadrado Caverna::getInicio(Quadrado quadrado){

} 

Quadrado Caverna::getFim(Quadrado quadrado){

} 

void Caverna::resetar(){

}

int Caverna::getQuantLinhas(){

}

*/

void Caverna::toString(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < QtdColunas; ++c) {
            std::cout << caverna_[l][c]->toString();
        }
    std::cout << "\n";
    }
}