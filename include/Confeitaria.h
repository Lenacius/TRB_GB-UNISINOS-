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

class Confeitaria{

    private:
        /// ATRIBUTOS
        vector<Produto*> lstProdutos;
        vector<Insumo*> lstInsumos;
        vector<Venda*> lstVendas;

    public:
        /// CONSTRUTOR
        Confeitaria();

        /// DESTRUTOR
        virtual ~Confeitaria();

        /// MÉTODOS
        void consultaProduto(int idEscolhido);
        void consultaProduto(string nomeEscolhido);

        void consultaInsumo(int idEscolhido);
        void consultaInsumo(string nomeEscolhido);

        void listarVendas();

        void listarProdutos();
        void listarInsumos();

        void venderProdutos();

};

#endif // CONFEITARIA_H
