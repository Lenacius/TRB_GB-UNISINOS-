#ifndef INSUMO_H
#define INSUMO_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

//#include "C:\Users\jonas\Desktop\TrabalhoGBc\include\Confeitaria.h"

using namespace std;

class Insumo{

    private:
        /// ATRIBUTOS
        int idInsumo;
        string nome;
        float valor;
        string unidadeMedida;
        float quantEstoque;
        float quantMinEstoque;

        float entradaInsumo;
    public:
        /// CONSTRUTOR
        Insumo();
        Insumo(int idInsumo, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque);

        /// DESTRUTOR
        virtual ~Insumo();

        /// SETTERS_&_GETTERS
        int getIdInsumo();
        string getNome();
        float getValor();
        string getUnidadeMedida();
        float getQuantEstoque();
        float getQuantMinEstoque();

        void setIdInsumo(int idInsumo);
        void setNome(string nome);
        void setValor(float valor);
        void setUnidadeMedida(string unidadeMedida);
        void setQuantEstoque(float quantEstoque);
        void setQuantMinEstoque(float quantMinEstoque);


        /// MÉTODOS
        void inserirEstoque(float entradaInsumo);
        void removerEstoque();
};

#endif // INSUMO_H
