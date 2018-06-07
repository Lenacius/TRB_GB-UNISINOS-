#include "Confeitaria.h"

Confeitaria::Confeitaria(){
    fstream file;
    int id;
    string nome;
    float valor;
    string unidadeMedida;
    float quantEstoque;
    float quantMinEstoque;
    string lixo;

    file.open("Produtos.txt", fstream::in);

    if(file.is_open()){

        getline(file, lixo);

        while(!file.eof()){

            file >> id;
            getline(file, nome, '\t');
            file >> valor;
            getline(file, unidadeMedida, '\t');
            file >> quantEstoque;
            file >> quantMinEstoque;

            Produto *p = new Produto();

            lstProdutos.push_back(p);
        }

    }
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

}

Confeitaria::~Confeitaria()
{
    //dtor
}

void Confeitaria::listarProdutos(){

}

void Confeitaria::listarInsumos(){}

void Confeitaria::atualizarProdutos(){}

void Confeitaria::atualizarInsumos(){}

void Confeitaria::venderProdutor(){}
