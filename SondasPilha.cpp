#include "SondasPilha.h"

SondasPilha::SondasPilha(Caverna caverna): caverna_(caverna){}

SondasPilha::~SondasPilha(){
    pilha.clear();
}

void SondasPilha::esvaziarCaminhos(){
    if(pilha.empty()){
        pilha.push(*caverna_.getInicio());
        return;
    }
    pilha.clear();
}

bool SondasPilha::possuiCaminhos(){
    return !pilha.empty();
}

Quadrado* SondasPilha::proximoCaminho(){
    return pilha.top();
}

bool SondasPilha::estaFinalizado(){
    if(possuiCaminhos() || proximoCaminho() != caverna_.getFim()) {
        return false;
    }else{
        return true;
    }
}

Quadrado* SondasPilha::passo(){
    if(possuiCaminhos() == false){
        return nullptr;
    }

    Quadrado * posicaoAtual = proximoCaminho();

    if(posicaoAtual == caverna_.getFim()){
        getCaminho();
        return nullptr;
    }

    bool empty = true;
    Quadrado * pont;
    caverna_.getVizinhos(pont, *posicaoAtual);

    for(int i = 0; i < 4; i++){
        if(pont[i].getAnterior() != nullptr && pont[i].getTipo() == 0){            
            pont[i].setAnterior(*posicaoAtual);
            pilha.push(pont[i]);
            empty = false;
        }
    }

    if(empty == true) {
        pilha.pop();
    }

    return posicaoAtual;
}

void SondasPilha::encontrarCaminho() {
    while(estaFinalizado() == false) {
        passo();
    }
}

void SondasPilha::getCaminho(){
    Stack<Quadrado> caminho;

    Quadrado * posicaoAtual = proximoCaminho();
    caminho.push(*posicaoAtual);

    while(posicaoAtual->getAnterior()){
        posicaoAtual = posicaoAtual->getAnterior();
        caminho.push(*posicaoAtual);
    }

    while (caminho.empty() == false) {
        std::cout << "[" << caminho.top()->getLinha() 
        << "," << caminho.top()->getColuna() << "] -> ";
        caminho.pop();
    }
    
}