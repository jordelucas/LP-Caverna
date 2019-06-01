#include "SondasPilha.h"

SondasPilha::SondasPilha(Caverna* caverna) {
    caverna_ = caverna;
    pilha = new Stack<Quadrado>();
    
    esvaziarCaminhos();
}

SondasPilha::~SondasPilha(){
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
    if(possuiCaminhos() || proximoCaminho()->getTipo() != caverna_->getFim()->getTipo()) {
        return false;
    }else{
        return true;
    }
}

Quadrado* SondasPilha::passo(){
    if(possuiCaminhos() == false){
        return nullptr;
    }

    if(pilha->top()->getTipo() == caverna_->getFim()->getTipo()){
        std::cout << "asdasdas" << std::endl;
        getCaminho();
        return nullptr;
    }

    bool empty = true;
    Quadrado * posicaoAtual = pilha->top();

    for(int i = 0; i < 4; i++){
        Quadrado * vizinho = caverna_->getVizinhos(posicaoAtual, i);
        if (vizinho == nullptr){
        }else if(vizinho->getSituacao() == false && (vizinho->getTipo() == 0 || vizinho->getTipo() == 3)){                
            //vizinhos[i].setAnterior(&pontAtual);
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
    //caverna_->getInicio()->setSituacao(false);
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
        std::cout << pilha->top()->getLinha(); 
        std::cout << pilha->top()->getColuna() << "\n";
        passo();
        //passo();
        //getCaminho();
    //}*/
}

void SondasPilha::getCaminho(){
    Stack<Quadrado> * caminho;

    Quadrado posicaoAtual = *proximoCaminho();
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