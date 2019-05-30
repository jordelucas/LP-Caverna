#include "SondasPilha.h"

SondasPilha::SondasPilha(Caverna * caverna) {
    caverna_ = caverna;
    pilha = new Stack<Quadrado>();
    esvaziarCaminhos();
}

SondasPilha::~SondasPilha(){
    esvaziarCaminhos();
}

void SondasPilha::esvaziarCaminhos(){
    if(pilha->empty()){
        pilha->push(caverna_->getInicio());
        return;
    }
    pilha->clear();
    delete pilha;
    pilha = nullptr;
}

bool SondasPilha::possuiCaminhos(){
    return !pilha->empty();
}

Quadrado SondasPilha::proximoCaminho(){
    return *(pilha->top());
}

bool SondasPilha::estaFinalizado(){
    if(possuiCaminhos() || proximoCaminho().getTipo() != caverna_->getFim().getTipo()) {
        return false;
    }else{
        return true;
    }
}

Quadrado SondasPilha::passo(){
    std::cout << "A lista está vazia? ";
    if(possuiCaminhos() == false){
        std::cout << "Sim\n";
        return Quadrado();
    }
    std::cout << "Nao\n";

    Quadrado posicaoAtual = proximoCaminho();
    Quadrado * pontAtual = &posicaoAtual;

    std::cout << "A posicao atual é a ultima? ";
    if(posicaoAtual.getTipo() == caverna_->getFim().getTipo()){
        std::cout << "Sim\n";
        getCaminho();
        return Quadrado();
    }
    std::cout << "Nao\n";


    std::cout << "Saga dos vizinhos\n";
    bool empty = true;
    Quadrado * pont = new Quadrado[4];

    std::cout << "Vai entrar\n";
    caverna_->getVizinhos(pont, posicaoAtual);
    std::cout << "Success!!!\n";

    std::cout << "força, foco e fé!\n\n";
    for(int i = 0; i < 4; i++){
        if((pont[i].getAnterior() == nullptr) && (pont[i].getTipo() == 0)){                
            pont[i].setAnterior(posicaoAtual);
            pilha->push(pont[i]);
            empty = false;
        }
    }

    std::cout << "\n" << pilha->size() << "\n";

    if(empty == true) {
        pilha->pop();
    }

    delete[] pont;

    return posicaoAtual;
}

void SondasPilha::encontrarCaminho() {
    //while(estaFinalizado() == false) {
        //std::cout << "Prepare-se\n";
        passo();
        std::cout << "\n";
        passo();
        std::cout << "\n";
        passo();
        //getCaminho();
    //}
}

void SondasPilha::getCaminho(){
    Stack<Quadrado> * caminho;

    Quadrado posicaoAtual = proximoCaminho();
    caminho->push(posicaoAtual);

    while(posicaoAtual.getAnterior()){
        posicaoAtual = *(posicaoAtual.getAnterior());
        caminho->push(posicaoAtual);
    }

    while (caminho->empty() == false) {
        std::cout << "[" << caminho->top()->getLinha() 
        << "," << caminho->top()->getColuna() << "] -> ";
        caminho->pop();
    }

    caminho->clear();
    
}