#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Quadrado.h"
#include "Caverna.h"
#include "SondasPilha.h"
#include "SondasFila.h"

int main(){
    Caverna *cv = new Caverna();
    std::ifstream arq_in;
    arq_in.open("caverna-1.txt");

    cv->carregar(arq_in);

    arq_in.close();

    cv->toString();

    SondasFila pilha(cv);
    pilha.encontrarCaminho();

    std::cout << "Inicio: " << cv->getInicio()->getLinha() << " " << cv->getInicio()->getColuna() <<"\n";
    std::cout << "Fim: " << cv->getFim()->getLinha() << " " << cv->getFim()->getColuna() <<"\n";

    cv->resetar();

    return 0;
}
    //pilha.encontrarCaminho();
    //std::cout << "Buscou o caminho\n";
/*
    Caverna c;

    std::ifstream arq_in;

    arq_in.open("teste.txt");
    c.carregar(arq_in);
    arq_in.close();

    c.toString();

    std::cout << "\n";
    std::cout << "Inicio: " << c.getInicio()->getLinha() << " " << c.getInicio()->getColuna() << "\n";
    std::cout << "Fim: " << c.getFim()->getLinha() << " " << c.getFim()->getColuna() << "\n\n";
    
    Quadrado * vizinhos = new Quadrado[4];
    c.getVizinhos(vizinhos, *c.getInicio());
    std::cout << vizinhos[0].toString();
    std::cout << vizinhos[1].toString();
    std::cout << vizinhos[2].toString();
    std::cout << vizinhos[3].toString();
    std::cout << "\n";
    delete [] vizinhos;
    //c.~Caverna();
    return 0;

*/
