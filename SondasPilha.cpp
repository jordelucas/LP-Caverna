#include "SondasPilha.h"

SondasPilha::SondasPilha(Caverna* caverna) {
    caverna_ = caverna;
    pilha = new Stack<Quadrado*>();
    
    esvaziarCaminhos();
}

SondasPilha::~SondasPilha(){
    pilha->clear();
    delete pilha;
}

void SondasPilha::esvaziarCaminhos(){
    if(pilha->empty()){
        pilha->push(caverna_->getInicio());
        return;
    }
    pilha->clear();
}

bool SondasPilha::possuiCaminhos(){
    return !pilha->empty();
}

Quadrado* SondasPilha::proximoCaminho(){
    return *pilha->top();
}

bool SondasPilha::estaFinalizado(){
    if(possuiCaminhos() == false || proximoCaminho()->getTipo() == caverna_->getFim()->getTipo()) {
        return true;
    }
        return false;
}

Quadrado* SondasPilha::passo(){
    if(possuiCaminhos() == false){
        getCaminho();
        return nullptr;
    }

    if((*pilha->top())->getTipo() == caverna_->getFim()->getTipo()){
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
            pilha->push(vizinho);
            empty = false;

            if(vizinho->getTipo() == 3) {
                return *pilha->top();
            }
            
        }
    }

    if(empty == true) {
        if(pilha->size() == 1){
            pilha->clear();
            return nullptr;
        }else{
            pilha->pop();
        }
    }

    return proximoCaminho();
}

void SondasPilha::encontrarCaminho() {
   while(!estaFinalizado()) {   
        passo();
    }
    passo();
}

void SondasPilha::getCaminho(){
    std::ofstream arq_out("saida.txt", std::ofstream::app);
    if (!arq_out.fail()){
        if(possuiCaminhos() == false) {
            arq_out << "Pilha:" << std::endl;
            arq_out << "O caminho não pôde ser encontrado!\n\n";
            return;
        }

        Stack<Quadrado> * caminho = new Stack<Quadrado>();
        Quadrado * posicaoAtual = proximoCaminho();

        caminho->push(*posicaoAtual);

        while(posicaoAtual->getAnterior()){
            posicaoAtual = (posicaoAtual->getAnterior());
            caminho->push(*posicaoAtual);
        }

        arq_out << "Pilha:" << std::endl;
        while (caminho->top()->getTipo() != 3) {
            arq_out << '[' << caminho->top()->getLinha()
                    << ',' << caminho->top()->getColuna()
                    << "]->";
            caminho->pop();
        }

        arq_out << '[' << caminho->top()->getLinha()
                  << ',' << caminho->top()->getColuna()
                  << ']' << '\n' << '\n';

        caminho->clear();
        delete caminho;
    }else{
        std::cout << "Erro!" << std::endl;
    }

    arq_out.close();
}