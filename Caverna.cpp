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

Quadrado Caverna::getInicio(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            if(caverna_[l][c]->getTipo() == 2){
                return *(caverna_[l][c]);
            }
        }
    }    
    return Quadrado();
} 

Quadrado Caverna::getFim(){

    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            if(caverna_[l][c]->getTipo() == 3){
                return *(caverna_[l][c]);
            }
        }
    }    
    return Quadrado();
} 

void Caverna::getVizinhos(Quadrado * vizinhos, Quadrado * quadrado){
    int qtd = 0;

    if(quadrado->getColuna() != 0){
        std::cout << "Esquerda\n";
        vizinhos[qtd++] =  *(caverna_[quadrado->getLinha()][quadrado->getColuna()-1]);
    }else{
        std::cout << "Nao pode ir pra esquerda\n";
        vizinhos[qtd++] = Quadrado();
    }

    if(quadrado->getColuna() != qtdColunas-1){
    std::cout << "Direita\n";
        vizinhos[qtd++] =  *(caverna_[quadrado->getLinha()][quadrado->getColuna()+1]);
    }else{
        std::cout << "Nao pode ir pra direita\n";
        vizinhos[qtd++] = Quadrado();
    }

    if(quadrado->getLinha() != 0){
        std::cout << "Cima\n";
        vizinhos[qtd++] =  *(caverna_[quadrado->getLinha()-1][quadrado->getColuna()]);
    }else{
        std::cout << "Nao pode ir pra cima\n";
        vizinhos[qtd++] = Quadrado();

    }

    if(quadrado->getLinha() != qtdLinhas-1){
        std::cout << "Baixo\n";
        vizinhos[qtd++] =  *(caverna_[quadrado->getLinha()+1][quadrado->getColuna()]);
    }else{
        std::cout << "Nao pode ir pra baixo\n";
        vizinhos[qtd++] = Quadrado();
    }

    std::cout << "\n";
}

void Caverna::toString(){
    for (int l = 0; l < qtdLinhas; ++l) {
        for (int c = 0; c < qtdColunas; ++c) {
            std::cout << caverna_[l][c]->toString();
        }
    std::cout << "\n";
    }
}

/*
void Caverna::resetar(){

}
*/