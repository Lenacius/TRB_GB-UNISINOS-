#ifndef INSUMOSPRODUTO_H
#define INSUMOSPRODUTO_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

#include "C:\Users\jonas\Desktop\TrabalhoGBc\include\Insumo.h"

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

        /// DESTRUTOR
        virtual ~InsumosProduto();

        /// SETTERS_&_GETTERS
        float getQuantidade();
        string getNomeInsumo();

        void setQuantidade(float quantidade);


};

#endif // INSUMOSPRODUTO_H
