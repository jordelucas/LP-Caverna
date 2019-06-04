#include "SondasPilha.h"

SondasPilha::SondasPilha(Caverna* caverna) {
    caverna_ = caverna;
    pilha = new Stack<Quadrado>();
    
    esvaziarCaminhos();
}

SondasPilha::~SondasPilha(){
    std::cout << "Sonda" << std::endl;
    esvaziarCaminhos();
}

void SondasPilha::esvaziarCaminhos(){
    if(pilha->empty()){
        pilha->push(*caverna_->getInicio());
        return;
    }
    pilha->clear();
    delete pilha;
    pilha = nullptr;
}

bool SondasPilha::possuiCaminhos(){
    return !pilha->empty();
}

Quadrado* SondasPilha::proximoCaminho(){
    return pilha->top();
}

bool SondasPilha::estaFinalizado(){
    if(possuiCaminhos() == false || proximoCaminho()->getTipo() == caverna_->getFim()->getTipo()) {
        return true;
    }
        return false;
}

Quadrado* SondasPilha::passo(){
    if(possuiCaminhos() == false){
        std::cout << "Sem saída" << std::endl;
        return nullptr;
    }

    if(pilha->top()->getTipo() == caverna_->getFim()->getTipo()){
        getCaminho();
        return nullptr;
    }

    bool empty = true;
    Quadrado * posicaoAtual = proximoCaminho();

    for(int i = 0; i < 4; i++){
        Quadrado * vizinho = caverna_->getVizinhos(posicaoAtual, i);
        if (vizinho == nullptr){
        }else if(vizinho->getSituacao() == false && (vizinho->getTipo() == 0 || vizinho->getTipo() == 3)){                
            vizinho->setAnterior(posicaoAtual);
            vizinho->setSituacao(true);
            pilha->push(*vizinho);
            std::cout << "add:" << vizinho->getLinha() 
                         << ' ' << vizinho-> getColuna()
                         << std::endl;
            empty = false;
        }
    }
    std::cout << std::endl;
    if(empty == true) {
        pilha->pop();
    }

    return pilha->top();
}

void SondasPilha::encontrarCaminho() {
   while(!estaFinalizado()) {    
        passo();
    }
    passo();
}

void SondasPilha::getCaminho(){
    Stack<Quadrado> * caminho = new Stack<Quadrado>();
    Quadrado * posicaoAtual = proximoCaminho();

    caminho->push(*posicaoAtual);

    while(posicaoAtual->getAnterior()){
        posicaoAtual = (posicaoAtual->getAnterior());
        caminho->push(*posicaoAtual);
    }

    std::cout << "Caminho:" << std::endl;
    while (caminho->size() != 1) {
        std::cout << '[' << caminho->top()->getLinha()
                  << ',' << caminho->top()->getColuna()
                  << "]->";
        caminho->pop();
    }
    std::cout << '[' << caminho->top()->getLinha()
                  << ',' << caminho->top()->getColuna()
                  << ']' << '\n';
    caminho->clear();
    
}