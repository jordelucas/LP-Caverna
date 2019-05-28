#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

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

    //c.~Caverna();
    return 0;
}