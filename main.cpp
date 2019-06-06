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
    std::ofstream arq_out("saida.txt", std::ofstream::out);
    if (!arq_out.fail())
    {
        arq_out << "Saída Caverna\n"; 
    }
    arq_out.close();

    arq_in.open("caverna-1.txt");
    if (!arq_in.fail()){
        cv->carregar(arq_in);
    }
    arq_in.close();

    SondasPilha sondaPilha(cv);

    SondasFila sondaFila(cv);

    sondaFila.encontrarCaminho();

    delete cv;
    return 0;
}