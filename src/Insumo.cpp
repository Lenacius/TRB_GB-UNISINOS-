#include "Insumo.h"

/// CONSTRUTOR
Insumo::Insumo(){}

Insumo::Insumo(int idInsumo, string nome, float valor, string unidadeMedida, float quantEstoque, float quantMinEstoque){

    this->idInsumo = idInsumo;
    this->nome = nome;
    this->valor = valor;
    this->unidadeMedida = unidadeMedida;
    this->quantEstoque = quantEstoque;
    this->quantMinEstoque = quantMinEstoque;

}

/// DESTRUTOR
Insumo::~Insumo(){}

/// SETTERS_&_GETTERS
int Insumo::getIdInsumo(){ return this->idInsumo; }
string Insumo::getNome(){ return this->nome; }
float Insumo::getValor(){ return this->valor; }
string Insumo::getUnidadeMedida(){ return this->unidadeMedida; }
float Insumo::getQuantEstoque(){ return this->quantEstoque; }
float Insumo::getQuantMinEstoque(){ return this->quantMinEstoque; }

void Insumo::setIdInsumo(int idInsumo){ this->idInsumo = idInsumo; }
void Insumo::setNome(string nome){ this->nome = nome; }
void Insumo::setValor(float valor){ this->valor = valor; }
void Insumo::setUnidadeMedida(string unidadeMedida){ this->unidadeMedida = unidadeMedida; }
void Insumo::setQuantEstoque(float quantEstoque){ this->quantEstoque = quantEstoque; }
void Insumo::setQuantMinEstoque(float quantMinEstoque){ this->quantMinEstoque = quantMinEstoque; }

/// MÉTODOS
void Insumo::inserirEstoque(){}
void Insumo::removerEstoque(){}
