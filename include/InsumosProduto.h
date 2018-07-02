#ifndef INSUMOSPRODUTO_H
#define INSUMOSPRODUTO_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

//#include <Insumo.h>
#include "C:\Users\jonas\Desktop\TrabalhoGBc1\include\Insumo.h"

using namespace std;

class InsumosProduto{

    private:
        /// ATRIBUTOS
        Insumo *insumo;
        float quantidade;

    public:
        /// CONSTRUTOR
        InsumosProduto();
        InsumosProduto(Insumo *insumo, float quantidade);
        string getUnidadeMedida();

        /// DESTRUTOR
        virtual ~InsumosProduto();

        /// SETTERS_&_GETTERS
        float getQuantidade();
        string getNomeInsumo();

        void setQuantidade(float quantidade);
};

#endif // INSUMOSPRODUTO_H
