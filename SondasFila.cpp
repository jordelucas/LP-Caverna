#include "SondasFila.h"

SondasFila::SondasFila(Caverna* caverna) {
    caverna_ = caverna;
    fila_ = new Queue<Quadrado*>();
    
    esvaziarCaminhos();
}

SondasFila::~SondasFila(){
    fila_->clear();
    delete fila_;
}

void SondasFila::esvaziarCaminhos(){
    if(fila_->empty()){
        fila_->push_back(caverna_->getInicio());
        return;
    }
    fila_->clear();
    delete fila_;
}

bool SondasFila::possuiCaminhos(){
    return !fila_->empty();
}

Quadrado* SondasFila::proximoCaminho(){
    return *fila_->peek();
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

    if((*fila_->peek())->getTipo() == caverna_->getFim()->getTipo()){
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
            std::cout << "\n";
            fila_->push_back(vizinho);
            std::cout << "add:" << vizinho->getLinha() 
                         << ' ' << vizinho-> getColuna()
                         << std::endl;
            empty = false;
        }
    }

    std::cout << std::endl;

    if(fila_->size() == 1){
        fila_->clear();
        return nullptr;
    }else{

        fila_->pop_front();
    }

    return *fila_->peek();
}

void SondasFila::encontrarCaminho() {
    while(!estaFinalizado()) {   
        std::cout << "\n" << fila_->size() << "||" << (*fila_->peek())->getLinha() << " " << (*fila_->peek())->getColuna() << "\n";
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
    
    while(posicaoAtual->getAnterior()){
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
                  << ']' << '\n';
    caminho->clear();
    delete caminho;
}