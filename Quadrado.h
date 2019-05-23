#ifndef QUADRADO_H
#define QUADRADO_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Quadrado{
    private:
        int linha_;
        int coluna_;
        char tipo_;
    public:
        Quadrado();
        int getLinha();
        int getColuna();
        int getTipo();
        void toString();
};

Quadrado::Quadrado(): linha_(), coluna_(), tipo_()
{}
int Quadrado::getLinha(){
    return linha_;
}
int Quadrado::getColuna(){
    return coluna_;
}
int Quadrado::getTipo(){
    return tipo_;
}

void Quadrado::toString(){
    for (size_t i = 0; i < getColuna()*getLinha(); i++){ // Definir parada
        switch (getTipo()){
            case '0':
                std::cout << '_' << std::endl;
                break;

            case '1':
                std::cout << '#' << std::endl;
                break;

            case '2':
                std::cout << 'I' << std::endl;
                break;

            case '3':
                std::cout << 'F' << std::endl;
                break;
        }
        
    }
    
}

#endif // !QUADRADO_H
