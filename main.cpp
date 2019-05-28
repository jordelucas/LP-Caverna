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

    c.toString();

    arq_in.close();

    c.~Caverna();
    return 0;
}