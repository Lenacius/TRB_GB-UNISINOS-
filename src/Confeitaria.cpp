//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Confeitaria.h"
//#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Confeitaria.h"
#include "C:\Users\isamurs\Desktop\TRB_GB\include\Confeitaria.h"


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

        getline(file, nome); // CAPTURANDO A PRIMEIRA LINHA QUE NÃO POSSUI DADOS IMPORTANTES

        while(!file.eof()){ // ENQUANTO NÃO CHEGAR AO FINAL DO ARQUIVO FICA PEGANDO AS VARIAVEIS

            file >> idProduto;
            //cout << idProduto << '!' << endl;

            file.get(); // FUNÇÃO PARA CAPTURAR O \t PARA ENTÃO CAPTAR A VARIAVEL
            getline(file, nome, '\t');
            //cout << nome << '!' << endl;

            file >> valor;
            //cout << valor << '!' << endl;

            file.get();
            getline(file, unidadeMedida, '\t');
            //cout << unidadeMedida << '!' << endl;

            file >> quantEstoque;
            //cout << quantEstoque << '!' << endl;

            file >> quantMinEstoque;
            //cout << quantMinEstoque << '!' << endl;

            Produto *ponteiroProduto = new Produto(idProduto, nome, valor, unidadeMedida, quantEstoque, quantMinEstoque); // ARMAZENA AS VARIAVEIS NUM PONTEIRO DA CLASSE PRODUTOS...

            this->lstProdutos.push_back(ponteiroProduto); // ...PARA INTRODUZI-LOS NO FINAL DO VECTOR lstProdutos
        }

        file.close();

    }
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

    file.open("Insumos.txt", fstream::in);

    if(file.is_open()){

        getline(file, nome);

        while(!file.eof()){

            file >> idProduto;
            //cout << idProduto << '!' << endl;

            file.get();
            getline(file, nome, '\t');
            //cout << nome << '!' << endl;

            file >> valor;
            //cout << valor << '!' << endl;

            file.get();
            getline(file, unidadeMedida, '\t');
            //cout << unidadeMedida << '!' << endl;

            file >> quantEstoque;
            //cout << quantEstoque << '!' << endl;

            file >> quantMinEstoque;
            //cout << quantMinEstoque << '!' << endl;

            Insumo *ponteiroInsumo = new Insumo(idProduto, nome, valor, unidadeMedida, quantEstoque, quantMinEstoque); // ARMAZENA AS VARIAVEIS NUM PONTEIRO DA CLASSE PRODUTOS...

            lstInsumos.push_back(ponteiroInsumo);
        }

        file.close();

    }
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

}

Confeitaria::~Confeitaria(){}

void Confeitaria::listarProdutos(){ // FUNÇÃO PARA CRIAR A LISTA DE PRODUTOS (SEM LISTA DE INSUMOS DO PRODUTO)

    cout << "IdProduto" << '\t' << "Nome" << '\t' << "Valor" << '\t' << "UnidadeMedida" << '\t' << "QuantEstoque" << '\t' << "QuantMinEstoque" << endl;

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

void Confeitaria::listarInsumos(){ // FUNÇÃO PARA CRIAR A LISTA DE INSUMOS

    cout << "IdInsumo" << '\t' << "Nome" << '\t' << "Valor" << '\t' << "UnidadeMedida" << '\t' << "QuantEstoque" << '\t' << "quantMinEstoque" << endl;

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
