#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "InsumosProduto.h"

using namespace std;

class Produto
{

    private:
        ///ATRIBUTOS
        int idProduto;
        string nome;
        float valor;
        string unidadeMedida;
        float quantEstoque;
        float quantMinEstoque;
        vector<InsumosProduto*> lstInsumos;

    public:
        ///METODOS
        Produto();
        Produto(int idProduto, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque);
        virtual ~Produto();
        void produzir();
        void vender();
        ///SETTERS_&_GETTERS
        void setIdProduto(int idProduto);
        void setNome(string nome);
        void setValor(float valor);
        void setUnidadeMedida(string unidadeMedida);
        void setQuantEstoque(float quantEstoque);
        void setQuantMinEstoque(float quantMinEstoque);
        int getIdProduto();
        string getNome();
        float getValor();
        string getUnidadeMedida();
        float getQuantEstoque();
        float getQuantMinEstoque();

};

#endif // PRODUTO_H
