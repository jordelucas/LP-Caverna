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
    Caverna *cv2 = new Caverna();
    std::ifstream arq_in, arq_in2;

    std:: string cavernas[9] = {"caverna-1.txt","caverna-2.txt","caverna-4.txt","caverna-5.txt",
                                 "caverna-6.txt","caverna-7.txt","caverna-8.txt","caverna-9.txt","caverna-10.txt"};

    for (size_t i = 0; i < 9; i++){
        arq_in.open(cavernas[i]);
        arq_in2.open(cavernas[i]);
        
        if (!arq_in.fail())
        {
            cv->carregar(arq_in);
            cv2->carregar(arq_in2);

            SondasFila fila(cv);
            fila.encontrarCaminho();

            SondasPilha pilha(cv2);
            pilha.encontrarCaminho();
        }
        arq_in.close();
        arq_in2.close();
    }
    
    arq_in.close();
    arq_in2.close();
    
    delete cv;
    delete cv2;
    return 0;
}