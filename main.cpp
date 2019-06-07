#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Quadrado.h"
#include "Caverna.h"
#include "SondasPilha.h"
#include "SondasFila.h"

int main(){
    std::ifstream arq_in, arq_in2;
    std::ofstream arq_out("saida.txt", std::ofstream::out);
    arq_out.close();
    std:: string cavernas[10] = {"caverna-1.txt","caverna-2.txt","caverna-3.txt","caverna-4.txt","caverna-5.txt",
                                 "caverna-6.txt","caverna-7.txt","caverna-8.txt","caverna-9.txt","caverna-10.txt"};
    Caverna *cv = nullptr;
    for (size_t i = 0; i < 10; i++)
    {
        std::ofstream arq_out("saida.txt", std::ofstream::app);
        
        arq_out <<  cavernas[i] << " | ";
        
        cv = new Caverna();
        arq_out.close();

        arq_in.open(cavernas[i]);
        cv->carregar(arq_in);
        arq_in.close();

        SondasFila fila(cv);
        fila.encontrarCaminho();
        cv->resetar();

        delete cv;
        
        arq_out.open("saida.txt", std::ofstream::app);
      
        arq_out <<  cavernas[i] << " | ";
        arq_out.close();

        cv = new Caverna();

        arq_in.open(cavernas[i]);
        cv->carregar(arq_in);
        arq_in.close();

        SondasPilha pilha(cv);
        pilha.encontrarCaminho();
        
        delete cv;
    }

    return 0;
}