#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Produto.h"

Produto::Produto(){}

Produto::Produto(int idProduto, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque){

    this->idProduto = idProduto;
    this->nome = nome;
    this->valor = valor;
    this->unidadeMedida = unidadeMedida;
    this->quantEstoque = quantEstoque;
    this->quantMinEstoque = quantMinEstoque;

}

Produto::~Produto()
{
    //dtor
}


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
