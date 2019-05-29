#include "SondasPilha.h"

SondasPilha::SondasPilha(Caverna caverna): caverna_(caverna){}

void SondasPilha::esvaziarCaminhos(){
    if(pilha.empty()){
        pilha.push(*caverna_.getInicio());
        return;
    }
    pilha.clear();
}

Quadrado SondasPilha::passo(){
    if(pilha.empty()){
        return;
    }

    if(pilha.top() == caverna_.getFim()){
        return;
    }

    Quadrado * pont;
    caverna_.getVizinhos(pont, *pilha.top());

    for(int i = 0; i < 4; i++){
        if(pont[i].getAnterior() != nullptr && pont[i].getTipo() == 0){
            
            pilha.push(pont[i]);
        }
    }
}

bool SondasPilha::possuiCaminhos(){
    return true;
}
/*



Quadrado SondasPilha::proximoCaminho(){
    return ;
}

bool SondasPilha::estaFinalizado(){

}

std::string SondasPilha::getCaminho(){

}

*/