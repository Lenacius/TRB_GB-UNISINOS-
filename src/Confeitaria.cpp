//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Confeitaria.h"
#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Confeitaria.h"


Confeitaria::Confeitaria(){
    fstream file;

    int idProduto;
    int idInsumo;
    string nome;
    float valor;
    string unidadeMedida;
    float quantEstoque;
    float quantMinEstoque;

    string lixo; // VARIAVEL PARA IGNORAR LINHAS E TABULATURAS

    file.open("Produto.txt", fstream::in); // ABRE O ARQUIVO PARA LEITURA

    if(file.is_open()){ // VERIFICA SE O ARQUIVO ESTA ABERTO

        while(!file.eof()){ // ENQUANTO NÃO CHEGAR AO FINAL DO ARQUIVO FICA PEGANDO AS VARIAVEIS

            getline(file, lixo, '\n');
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

            Produto *ponteiroProduto = new Produto(idProduto, nome, valor, unidadeMedida, quantEstoque, quantMinEstoque); // ARMAZENA AS VARIAVEIS NUM PONTEIRO DA CLASSE PRODUTOS...

            lstProdutos.push_back(ponteiroProduto); // ...PARA INTRODUZI-LOS NO FINAL DO VECTOR lstProdutos
        }

        file.close();

    }
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

    file.open("Insumo.txt", fstream::in);

    if(file.is_open()){

        getline(file, lixo);

        while(!file.eof()){

            file >> idInsumo;
            //cout << idInsumo << '!' << endl;
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

            Insumo *ponteiroInsumo = new Insumo(idInsumo, nome, valor, unidadeMedida, quantEstoque, quantMinEstoque); // ARMAZENA AS VARIAVEIS NUM PONTEIRO DA CLASSE INSUMO...

            lstInsumos.push_back(ponteiroInsumo);
        }

        file.close();

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

void Confeitaria::listarInsumos(){

    for(vector<Insumo*>::iterator it = lstInsumos.begin(); it != lstInsumos.end(); it++){ // UTILIZA O ITERADOR PARA PEGAR APENAS DADOS DE CADA COMPONENTE DO VECTOR DE PRODUTOS
        cout << (*it)->getIdProduto();
        cout << '\t' << (*it)->getNome();
        cout << '\t' << (*it)->getValor();
        cout << '\t' << (*it)->getUnidadeMedida();
        cout << '\t' << (*it)->getQuantEstoque();
        cout << '\t' << (*it)->getQuantMinEstoque() << endl;
    }


}

void Confeitaria::atualizarProdutos(){}

void Confeitaria::atualizarInsumos(){}

void Confeitaria::venderProduto(){}


void Confeitaria::consultaInsumo(){} // FAZER DEPOIS DOS SETS DOS INSUMOS!!! JONAS

void consultarProduto(){} // FAZER DEPOIS DOS SETS DOS PRODUTOS!!! JONAS
