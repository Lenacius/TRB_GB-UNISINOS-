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
        int idInsumo;
        string nome;
        float valor;
        string unidadeMedida;
        float quantEstoque;
        float quantMinEstoque;

    public:
        ///METODOS
        Insumo();
        Insumo(int idInsumo, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque);
        virtual ~Insumo();
        void inserirEstoque();
        void removerEstoque();
        ///SETTERS_&_GETTERS
        void setIdInsumo(int idInsumo);
        void setNome(string nome);
        void setValor(float valor);
        void setUnidadeMedida(string unidadeMedida);
        void setQuantEstoque(float quantEstoque);
        void setQuantMinEstoque(float quantMinEstoque);
        int getIdInsumo();
        string getNome();
        float getValor();
        string getUnidadeMedida();
        float getQuantEstoque();
        float getQuantMinEstoque();

        void consultaInsumo();

};

#endif // INSUMO_H
