#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Confeitaria.h"

Confeitaria::Confeitaria(){
    fstream file;
    int idProduto;
    string nome;
    float valor;
    string unidadeMedida;
    float quantEstoque;
    float quantMinEstoque;
    string lixo; // VARIAVEL PARA IGNORAR LINHAS E TABULATURAS

    file.open("Produtos.txt", fstream::in); // ABRE O ARQUIVO PARA LEITURA

    if(file.is_open()){ // VERIFICA SE O ARQUIVO ESTA ABERTO

        getline(file, lixo);

        while(!file.eof()){ // ENQUANTO NÃO CHEGAR AO FINAL DO ARQUIVO FICA PEGANDO AS VARIAVEIS

            file >> idProduto;
            //cout << idProduto << '!' << endl;
            getline(file, lixo, '\t');
            getline(file, nome, '\t');
            //cout << nome << '!' << endl;
            file >> valor;
            //cout << valor << '!' << endl;
            getline(file, lixo, '\t');
            getline(file, unidadeMedida, '\t');
            //cout << unidadeMedida << '!' << endl;
            file >> quantEstoque;
            //cout << quantEstoque << '!' << endl;
            file >> quantMinEstoque;
            //cout << quantMinEstoque << '!' << endl;

            Produto *p = new Produto(idProduto, nome, valor, unidadeMedida, quantEstoque, quantMinEstoque); // ARMAZENA AS VARIAVEIS NUM PONTEIRO DA CLASSE PRODUTOS...

            lstProdutos.push_back(p); // ...PARA INTRODUZI-LOS NO FINAL DO VECTOR lstProdutos
        }

    }
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

}

Confeitaria::~Confeitaria(){}

void Confeitaria::listarProdutos(){

    for(vector<Produto*>::iterator it = lstProdutos.begin(); it != lstProdutos.end(); it++){ // UTILIZA O ITERADOR PARA PEGAR APENAS DADOS DE CADA COMPONENTE DO VECTOR DE PRODUTOS
        cout << (*it)->getIdProduto();
        cout << '\t' << (*it)->getNome();
        cout << '\t' << (*it)->getValor();
        cout << '\t' << (*it)->getUnidadeMedida();
        cout << '\t' << (*it)->getQuantEstoque();
        cout << '\t' << (*it)->getQuantMinEstoque() << endl;
    }

}

///A FAZER!!!!!

void Confeitaria::listarInsumos(){}

void Confeitaria::atualizarProdutos(){}

void Confeitaria::atualizarInsumos(){}

void Confeitaria::venderProdutor(){}
