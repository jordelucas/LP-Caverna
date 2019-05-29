#ifndef QUADRADO_H
#define QUADRADO_H

class Quadrado{
    private:
        int linha_;
        int coluna_;
        int tipo_;

    public: 
        Quadrado(int linha, int coluna, int tipo);
        int getLinha();
        int getColuna();
        int getTipo();
        char toString();
};

#endif // !QUADRADO_H
