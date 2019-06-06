#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Quadrado.h"
#include "Caverna.h"
#include "SondasPilha.h"
#include "SondasFila.h"

int main(){
    std::ifstream arq_in;
    std::ofstream arq_out("saida.txt", std::ofstream::out);
    std:: string cavernas[10] = {"caverna-1.txt","caverna-2.txt","caverna-3.txt","caverna-4.txt","caverna-5.txt",
                                 "caverna-6.txt","caverna-7.txt","caverna-8.txt","caverna-9.txt","caverna-10.txt"};
    
    for (size_t i = 0; i < 10; i++)
    {
        Caverna *cv = new Caverna();
        arq_in.open(cavernas[i]);
        cv->carregar(arq_in);

        SondasFila pilha(cv);

        pilha.encontrarCaminho();
        arq_in.close();
        delete cv;
    }

    return 0;
}