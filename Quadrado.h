#ifndef QUADRADO_H
#define QUADRADO_H

class Quadrado{
    private:
        int linha_;
        int coluna_;
        int tipo_;
        Quadrado * anterior_;

    public: 
        Quadrado(int linha, int coluna, int tipo);
        Quadrado();
        int getLinha();
        int getColuna();
        int getTipo();
        Quadrado* getAnterior();
        void setAnterior(Quadrado quadrado);
        char toString();
};

#endif // !QUADRADO_H
