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

    //c.toString();

    std::cout << c.getInicio()->getLinha() << " ";
    std::cout << c.getInicio()->getColuna() << "\n";

    std::cout << c.getFim()->getLinha() << " ";
    std::cout << c.getFim()->getColuna() << "\n";

    //vector v1 = c.getVizinhos(*c.getInicio());

    //Quadrado * vizinhos;
    //vizinhos = c.getVizinhos(vizinhos, *c.getInicio());
    
    Quadrado * vizinhos = new Quadrado[4];
    c.getVizinhos(vizinhos, *c.getInicio());
    std::cout << vizinhos[0].toString();
    std::cout << vizinhos[1].toString();
    std::cout << vizinhos[2].toString();
    std::cout << vizinhos[3].toString();
    delete [] vizinhos;

    // /delete vizinhos;
    //vector v1 = c.getVizinhos(*c.getInicio());
    /*std::cout << v1.at(0).getTipo() << "\n";
    std::cout << v1.at(1).getTipo() << "\n";
    std::cout << v1.at(2).getTipo() << "\n";
    std::cout << v1.at(3).getTipo() << "\n";*/

    //c.~Caverna();
    return 0;
}