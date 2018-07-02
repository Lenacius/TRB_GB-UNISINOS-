//#include "InsumosProduto.h"
#include "C:\Users\jonas\Desktop\TrabalhoGBc1\include\InsumosProduto.h"

/// CONSTRUTOR
InsumosProduto::InsumosProduto(){}

InsumosProduto::InsumosProduto(Insumo *insumo, float quantidade){

    this->insumo = insumo;
    this->quantidade = quantidade;

}

/// DESTRUTOR
InsumosProduto::~InsumosProduto(){}

/// SETTERS_&_GETTERS
float InsumosProduto::getQuantidade(){ return this->quantidade; }
string InsumosProduto::getNomeInsumo(){ return this->insumo->getNome(); }

void InsumosProduto::setQuantidade(float quantidade){ this->quantidade = quantidade; }
string InsumosProduto::getUnidadeMedida(){ return this->insumo->getUnidadeMedida(); }
