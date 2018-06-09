//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Confeitaria.h" //QUANDO FOR TRABALHAR NO TEU PC, COMENTA A LINHA ABAIXO
#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Confeitaria.h"

#include <iostream>

using namespace std;

int main(){

    Confeitaria *sonho = new Confeitaria(); // QUANDO CRIADA A VARIÁVEL O CONSTRUTOR JÁ PUXA OS DADOS DO ARQUIVO Produtos.txt

    //sonho->listarProdutos(); // FUNÇÃO PARA CRIAR A LISTA DE PRODUTOS (SEM LISTA DE INSUMOS DO PRODUTO)
    //sonho->listarInsumos(); // FUNÇÃO PARA CRIAR A LISTA DE INSUMOS

    delete sonho;
    return 0;
}
