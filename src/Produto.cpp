//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Produto.h"
//#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Produto.h"
#include "C:\Users\isamurs\Desktop\TRB_GB\include\Produto.h"

Produto::Produto(){}

Produto::Produto(int idProduto, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque){
    fstream file;
    string nomeInsumo;
    float quantidade;

    this->idProduto = idProduto;
    this->nome = nome;
    this->valor = valor;
    this->unidadeMedida = unidadeMedida;
    this->quantEstoque = quantEstoque;
    this->quantMinEstoque = quantMinEstoque;

    file.open("InsumosProduto.txt", fstream::in);

    if(file.is_open()){

        getline(file, nome); // CAPTURANDO A PRIMEIRA LINHA QUE NÃO POSSUI DADOS IMPORTANTES

        while(!file.eof()){ // ENQUANTO NÃO CHEGAR AO FINAL DO ARQUIVO

            getline(file, nome, '\t');
            if(nome == this->nome){ // VERIFICA SE O NOME DO PRODUTO É O MESMO QUE ESTÁ LISTADO NO ARQUIVO InsumosProduto.txt

                file.get(); // FUNÇÃO PARA CAPTURAR O \t PARA ENTÃO CAPTAR A VARIAVEL
                getline(file, nomeInsumo, '\t');
                //cout << nomeInsumo << '!' << endl;

                file >> quantidade;

            }
            else getline(file, nome); // CAPTURANDO INSUMOS DE OUTROS PRODUTOS PARA NÃO ENTRAREM NA LISTA DO PRODUTO X;

        }

        file.close();

    }
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!";


}

Produto::~Produto(){}

void Produto::produzir(){} // FAZER!!!
void Produto::vender(){} // FAZER!!!
void Produto::setIdProduto(int idProduto){} // FAZER!!!
void Produto::setNome(string nome){} // FAZER!!!
void Produto::setValor(float valor){} // FAZER!!!
void Produto::setUnidadeMedida(string unidadeMedida){} // FAZER!!!
void Produto::setQuantEstoque(float quantEstoque){} // FAZER!!!
void Produto::setQuantMinEstoque(float quantMinEstoque){} // FAZER!!!

int Produto::getIdProduto(){ return this->idProduto; }

string Produto::getNome(){ return this->nome; }

float Produto::getValor(){ return this->valor; }

string Produto::getUnidadeMedida(){ return this->unidadeMedida; }

float Produto::getQuantEstoque(){ return this->quantEstoque; }

float Produto::getQuantMinEstoque(){ return this->quantMinEstoque; }
