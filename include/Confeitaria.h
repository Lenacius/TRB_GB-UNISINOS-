#ifndef CONFEITARIA_H
#define CONFEITARIA_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

//#include "Produto.h"
#include "C:\Users\jonas\Desktop\TrabalhoGB\TrabalhoGB\include\Produto.h"
//#include "Insumo.h"
#include "C:\Users\jonas\Desktop\TrabalhoGB\TrabalhoGB\include\Insumo.h"
//#include "Venda.h"
#include "C:\Users\jonas\Desktop\TrabalhoGB\TrabalhoGB\include\Venda.h"

using namespace std;

class Confeitaria{

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
        void venderProduto();

        void consultaInsumo(int idEscolha);
        void consultaInsumo(string nomeEscolhido);

};

#endif // CONFEITARIA_H
