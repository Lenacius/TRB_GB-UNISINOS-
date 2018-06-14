#include "InsumosProduto.h"

/// CONSTRUTOR
InsumosProduto::InsumosProduto(){}

InsumosProduto::InsumosProduto(Insumo *insumo, float quantidade){

    this->insumo = insumo;
    this->quantidade = quantidade;

}

/// DESTRUTOR
InsumosProduto::~InsumosProduto(){}

/// SETTERS_&_GETTERS
void InsumosProduto::setQuantidade(float quantidade){ this->quantidade = quantidade; }

float InsumosProduto::getQuantidade(){ return this->quantidade; }
string InsumosProduto::getNomeInsumo(){ return this->insumo->getNome(); }
