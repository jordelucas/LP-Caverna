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
        Quadrado(int linha, int coluna, char tipo);
        int getLinha();
        int getColuna();
        int getTipo();
        std::string toString();
};

#endif // !QUADRADO_H
