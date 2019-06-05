#include "SondasFila.h"

SondasFila::SondasFila(Caverna* caverna) {
    caverna_ = caverna;
    fila = new Queue<Quadrado>();
    
    esvaziarCaminhos();
}

SondasFila::~SondasFila(){
    fila->clear();
    delete fila;
}

void SondasFila::esvaziarCaminhos(){
    if(fila->empty()){
        fila->push_back(*caverna_->getInicio());
        return;
    }
    fila->clear();
    delete fila;
}

bool SondasFila::possuiCaminhos(){
    return !fila->empty();
}

Quadrado* SondasFila::proximoCaminho(){
    //while (fila->peek()->getSituacao() == true) {
    //    fila->pop_front();
    //}

    return fila->peek();
}

bool SondasFila::estaFinalizado(){
    if(possuiCaminhos() == false || proximoCaminho()->getTipo() == caverna_->getFim()->getTipo()) {
        return true;
    }
        return false;
}

Quadrado* SondasFila::passo(){
    if(possuiCaminhos() == false){
        getCaminho();
        return nullptr;
    }

    if(fila->peek()->getTipo() == caverna_->getFim()->getTipo()){
        getCaminho();
        return nullptr;
    }

    Quadrado * posicaoAtual = proximoCaminho();

    for(int i = 0; i < 4; i++){
        Quadrado * vizinho = caverna_->getVizinhos(posicaoAtual, i);
        if (vizinho == nullptr){
        }else if(vizinho->getAnterior() == nullptr && (vizinho->getTipo() == 0 || vizinho->getTipo() == 3)){  
            //std::cout << "--" << posicaoAtual->getLinha() << " " << posicaoAtual->getColuna() << "---\n";                                        
            
            vizinho->setAnterior(posicaoAtual);
            caverna_->toString();    
            std::cout << "\n";        
            fila->push_back(*vizinho);
            caverna_->toString();            
            
            std::cout << "add:" << vizinho->getLinha() 
                         << ' ' << vizinho-> getColuna()
                         << std::endl;
            vizinho = nullptr;
            /*
            if(vizinho->getTipo() == 3) {
                return fila->peek();
            }*/
            //caverna_->toString();
            
        }
    }
    std::cout << std::endl;

    if(fila->size() == 1){
        fila->clear();
    }else{
        //posicaoAtual->setSituacao(true);
        proximoCaminho();
    }

    //posicaoAtual = nullptr;

    return fila->peek();
}

void SondasFila::encontrarCaminho() {
    while(!estaFinalizado()) {   
        std::cout << "\n" << fila->size() << "||" << fila->peek()->getLinha() << " " << fila->peek()->getColuna() << "\n";
        passo();
    }
    passo();
}

void SondasFila::getCaminho(){
    if(possuiCaminhos() == false) {
        std::cout << "O caminho não pôde ser encontrado!\n";
        return;
    }

    Stack<Quadrado> * caminho = new Stack<Quadrado>();
    Quadrado * posicaoAtual = proximoCaminho();

    caminho->push(*posicaoAtual);

//    while(posicaoAtual->getAnterior()){
 //       std::cout << posicaoAtual->getTipo();
   //     posicaoAtual = (posicaoAtual->getAnterior());
     //   caminho->push(*posicaoAtual);
    //}

    //std::cout << posicaoAtual->getAnterior()->getLinha() << " " << posicaoAtual->getAnterior()->getColuna() << "\n";

    /*while(posicaoAtual->getAnterior()){
        posicaoAtual = (posicaoAtual->getAnterior());
        caminho->push(*posicaoAtual);
    }

    std::cout << std::endl << "Caminho:" << std::endl;
    while (caminho->top()->getTipo() != 3) {
        std::cout << '[' << caminho->top()->getLinha()
                  << ',' << caminho->top()->getColuna()
                  << "]->";
        caminho->pop();
    }
    std::cout << '[' << caminho->top()->getLinha()
                  << ',' << caminho->top()->getColuna()
                  << ']' << '\n';*/
    caminho->clear();
}