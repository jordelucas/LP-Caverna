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
    std::ofstream arq_out("saida.txt", std::ofstream::out);
    if (!arq_out.fail())
    {
        arq_out << "Saída Caverna\n\n"; 
    }
    arq_out.close();
    std:: string cavernas[10] = {"caverna-1.txt","caverna-2.txt","caverna-3.txt","caverna-4.txt","caverna-5.txt",
                                 "caverna-6.txt","caverna-7.txt","caverna-8.txt","caverna-9.txt","caverna-10.txt"};

    for (size_t i = 0; i < 10; i++){
        arq_in2.open(cavernas[i]);
        if (!arq_in2.fail())
        {
            cv2->carregar(arq_in2);

            SondasFila fila(cv2);
            fila.encontrarCaminho();
        }
        arq_in2.close();
    }
    
    

    delete cv;
    delete cv2;
    return 0;
}