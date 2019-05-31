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
    Quadrado * array = new Quadrado[4];

    caverna_->getVizinhos(array, pontAtual);

    for(int i = 0; i < 4; i++){
        if(array[i].getSituacao() == false && array[i].getTipo() == 0){                
            array[i].setAnterior(pontAtual);
            pilha->push(array[i]);
            array[i].setSituacao();
            empty = false;
        }
    }

    if(empty == true) {
        pilha->pop();
    }

    return posicaoAtual;
}

void SondasPilha::encontrarCaminho() {
    //while(estaFinalizado() == false) {    
        std::cout << pilha->top()->getLinha(); 
        std::cout << pilha->top()->getColuna() << "\n"; 
        passo();     
        std::cout << pilha->top()->getLinha(); 
        std::cout << pilha->top()->getColuna() << "\n";
        passo();     
        std::cout << pilha->top()->getLinha(); 
        std::cout << pilha->top()->getColuna() << "\n";
        passo();
        std::cout << pilha->top()->getLinha(); 
        std::cout << pilha->top()->getColuna() << "\n";
        passo();
        //passo();
        //getCaminho();
    //}
}

void SondasPilha::getCaminho(){
    Stack<Quadrado> * caminho;

    Quadrado posicaoAtual = proximoCaminho();
    caminho->push(posicaoAtual);

    /*while(posicaoAtual.getAnterior()){
        posicaoAtual = *(posicaoAtual.getAnterior());
        caminho->push(posicaoAtual);
    }

    while (caminho->empty() == false) {
        std::cout << "[" << caminho->top()->getLinha() 
        << "," << caminho->top()->getColuna() << "] -> ";
        caminho->pop();
    }*/

    caminho->clear();
    
}