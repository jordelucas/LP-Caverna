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

    Quadrado * posicaoAtual = proximoCaminho();

    for(int i = 0; i < 4; i++){
        Quadrado * vizinho = caverna_->getVizinhos(posicaoAtual, i);

        if (vizinho == nullptr){
        }else if(vizinho->getSituacao() == false && (vizinho->getTipo() == 0 || vizinho->getTipo() == 3)){                
            vizinho->setAnterior(posicaoAtual);
            vizinho->setSituacao(true);
            fila_->push_back(vizinho);
        }
    }

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
        passo();

    }

    passo();
}

void SondasFila::getCaminho(){
    std::ofstream arq_out("saida.txt", std::ofstream::app);
    arq_out << "Sonda Fila\n";
    if (!arq_out.fail()){
        if(possuiCaminhos() == false) {
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

        arq_out << "Caminho:" << std::endl;
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