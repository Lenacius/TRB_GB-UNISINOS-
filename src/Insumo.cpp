//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Insumo.h"
//#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Insumo.h"
#include "C:\Users\isamurs\Desktop\TRB_GB\include\Insumo.h"

Insumo::Insumo(){}

Insumo::Insumo(int idProduto, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque){

    this->idProduto = idProduto;
    this->nome = nome;
    this->valor = valor;
    this->unidadeMedida = unidadeMedida;
    this->quantEstoque = quantEstoque;
    this->quantMinEstoque = quantMinEstoque;

}

Insumo::~Insumo(){}

void Insumo::setIdProduto(int idProduto){} // FAZER!!!
void Insumo::setNome(string nome){} // FAZER!!!
void Insumo::setValor(float valor){} // FAZER!!!
void Insumo::setUnidadeMedida(string unidadeMedida){} // FAZER!!!
void Insumo::setQuantEstoque(float quantEstoque){} // FAZER!!!
void Insumo::setQuantMinEstoque(float quantMinEstoque){} // FAZER!!!

int Insumo::getIdProduto(){ return this->idProduto; }

string Insumo::getNome(){ return this->nome; }

float Insumo::getValor(){ return this->valor; }

string Insumo::getUnidadeMedida(){ return this->unidadeMedida; }

float Insumo::getQuantEstoque(){ return this->quantEstoque; }

float Insumo::getQuantMinEstoque(){ return this->quantMinEstoque; }
