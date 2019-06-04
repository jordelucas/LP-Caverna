#ifndef QUADRADO_H
#define QUADRADO_H

class Quadrado{
    private:
        int linha_;
        int coluna_;
        int tipo_;
        bool situacao_;
        Quadrado * last_;

    public: 
        Quadrado(int linha, int coluna, int tipo);
        Quadrado();
        int getLinha();
        int getColuna();
        int getTipo();
        Quadrado * getAnterior();
        bool getSituacao();
        void setSituacao(bool situacao);
        void setAnterior(Quadrado * quadrado);
        void resetar();
        char toString();
};

#endif // !QUADRADO_H
