//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Insumo.h"
#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Insumo.h"

Insumo::Insumo(){}

Insumo::Insumo(int idInsumo, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque){

    this->idInsumo = idInsumo;
    this->nome = nome;
    this->valor = valor;
    this->unidadeMedida = unidadeMedida;
    this->quantEstoque = quantEstoque;
    this->quantMinEstoque = quantMinEstoque;

}

Insumo::~Insumo(){}

void Insumo::setIdInsumo(int idInsumo){

} // FAZER!!!
void Insumo::setNome(string nome){} // FAZER!!!
void Insumo::setValor(float valor){} // FAZER!!!
void Insumo::setUnidadeMedida(string unidadeMedida){} // FAZER!!!
void Insumo::setQuantEstoque(float quantEstoque){} // FAZER!!!
void Insumo::setQuantMinEstoque(float quantMinEstoque){} // FAZER!!!

int Insumo::getIdInsumo(){ return this->idInsumo; }

string Insumo::getNome(){ return this->nome; }

float Insumo::getValor(){ return this->valor; }

string Insumo::getUnidadeMedida(){ return this->unidadeMedida; }

float Insumo::getQuantEstoque(){ return this->quantEstoque; }

float Insumo::getQuantMinEstoque(){ return this->quantMinEstoque; }
