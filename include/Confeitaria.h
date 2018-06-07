#ifndef CONFEITARIA_H
#define CONFEITARIA_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include "Produto.h"
#include "Insumo.h"
#include "Venda.h"

using namespace std;

class Confeitaria
{

    private:
        ///ATRIBUTOS
        vector<Produto*> lstProdutos;
        vector<Insumo*> lstInsumos;
        vector<Venda*> lstVendas;

    public:
        ///METODOS
        Confeitaria(); // CONSTRUTOR
        virtual ~Confeitaria(); // DESTRUTOR
        void listarProdutos(); // FEITO
        void listarInsumos();
        void atualizarProdutos();
        void atualizarInsumos();
        void venderProdutor();

};

#endif // CONFEITARIA_H
