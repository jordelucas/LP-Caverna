#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Quadrado.h"
#include "Caverna.h"

int main(){
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
}