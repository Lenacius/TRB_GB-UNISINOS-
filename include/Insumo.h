#ifndef INSUMO_H
#define INSUMO_H

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

class Insumo{

    private:
        ///ATRIBUTOS
        int idProduto;
        string nome;
        float valor;
        string unidadeMedida;
        float quantEstoque;
        float quantMinEstoque;

    public:
        ///METODOS
        Insumo();
        Insumo(int idProduto, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque);
        virtual ~Insumo();
        void inserirEstoque();
        void removerEstoque();
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

#endif // INSUMO_H
