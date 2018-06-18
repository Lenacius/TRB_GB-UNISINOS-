#include "Produto.h"

/// CONSTRUTOR
Produto::Produto(){}

Produto::Produto(int idProduto, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque){

    this->idProduto = idProduto;
    this->nome = nome;
    this->valor = valor;
    this->unidadeMedida = unidadeMedida;
    this->quantEstoque = quantEstoque;
    this->quantMinEstoque = quantMinEstoque;

}

/// DESTRUTOR
Produto::~Produto(){}

/// SETTERS_&_GETTERS
int Produto::getIdProduto(){ return this->idProduto; }
string Produto::getNome(){ return this->nome; }
float Produto::getValor(){ return this->valor; }
string Produto::getUnidadeMedida(){ return this->unidadeMedida; }
float Produto::getQuantEstoque(){ return this->quantEstoque; }
float Produto::getQuantMinEstoque(){ return this->quantMinEstoque; }

void Produto::setIdProduto(int idProduto){ this->idProduto = idProduto; }
void Produto::setNome(string nome){ this->nome = nome; }
void Produto::setValor(float valor){ this->valor = valor; }
void Produto::setUnidadeMedida(string unidadeMedida){ this->unidadeMedida = unidadeMedida; }
void Produto::setQuantEstoque(float quantEstoque){ this->quantEstoque = quantEstoque; }
void Produto::setQuantMinEstoque(float quantMinEstoque){ this->quantMinEstoque = quantMinEstoque; }

/// MÉTODOS
void Produto::leInsumosProduto(Insumo *insumo, float quantidade){ // FUNÇÃO PARA ADICIONAR UM INSUMO A LISTA DE INSUMOS NECESSÁRIOS PARA O PRODUTO

    InsumosProduto *ponteiroInsumosProduto = new InsumosProduto(insumo, quantidade);

    this->lstInsumos.push_back(ponteiroInsumosProduto);

}

void Produto::listaInsumos(){

    for(vector<InsumosProduto*>::iterator itIP = this->lstInsumos.begin(); itIP != this->lstInsumos.end(); itIP++){ // LAÇO PARA LISTAR OS INSUMOS DE UM PRODUTO

        cout << "---" << (*itIP)->getNomeInsumo() << '\t';
        cout << (*itIP)->getQuantidade() << endl;

    }

}

void Produto::produzir(){}

void Produto::vender(){}
