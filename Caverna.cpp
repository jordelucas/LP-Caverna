#include "Caverna.h"

Caverna::Caverna() {}

Caverna::~Caverna() {

    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < QtdColunas; ++c) {
            delete caverna_[l][c];
        }
    delete[] caverna_[l];
    }
    delete[] caverna_;
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

Quadrado* Caverna::getInicio(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < QtdColunas; ++c) {
            if(caverna_[l][c]->getTipo() == 2){
                return caverna_[l][c];
            }
        }
    }    
    return nullptr;
} 

Quadrado* Caverna::getFim(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < QtdColunas; ++c) {
            if(caverna_[l][c]->getTipo() == 3){
                return caverna_[l][c];
            }
        }
    }    
    return nullptr;
} 

vector& Caverna::getVizinhos(Quadrado quadrado){
    int qtd = 0;

    vector volasd(qtd);
/*
    if(caverna_[quadrado.getLinha()][quadrado.getColuna()-1]->getTipo() == 0){
        v.insert(qtd++, caverna_[quadrado.getLinha()][quadrado.getColuna()-1]);
    }
    if(caverna_[quadrado.getLinha()][quadrado.getColuna()-1]->getTipo() == 0){
        v.insert(qtd++, caverna_[quadrado.getLinha()][quadrado.getColuna()+1]);
    }
    if((quadrado.getLinha() - qtdLinhas) >= 0 && caverna_[quadrado.getLinha()-qtdLinhas][quadrado.getColuna()]->getTipo() == 0){
        v.insert(qtd++, caverna_[quadrado.getLinha()][quadrado.getColuna()]);
    }
    if((quadrado.getLinha() + qtdLinhas) >= (qtdLinhas-1) && caverna_[quadrado.getLinha()+qtdLinhas][quadrado.getColuna()]->getTipo() == 0){
        v.insert(qtd, caverna_[quadrado.getLinha()][quadrado.getColuna()+1]);
    }
*/
    return volasd;
}
/*
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