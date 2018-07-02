//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Confeitaria.h" //QUANDO FOR TRABALHAR NO TEU PC, COMENTA A LINHA ABAIXO
//#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Confeitaria.h"
#include "C:\Users\jonas\Desktop\TrabalhoGBc1\include\Confeitaria.h"

#include <iostream>

using namespace std;

int main(){

    Confeitaria *sonho = new Confeitaria(); // QUANDO CRIADA A VARIÁVEL O CONSTRUTOR JÁ PUXA OS DADOS DO ARQUIVO Produtos.txt

    sonho->listarProdutos(); // FUNÇÃO PARA CRIAR A LISTA DE PRODUTOS (SEM LISTA DE INSUMOS DO PRODUTO)
//    sonho->listarInsumos(); // FUNÇÃO PARA CRIAR A LISTA DE INSUMOS

//    sonho->consultaProduto(2);
//    sonho->consultaInsumo(3);

//    sonho->atualizarInsumos();
//    cout << endl;
//    sonho->listarInsumos();

    sonho->atualizarProdutos();
    cout << endl;
    sonho->listarProdutos();

    delete sonho;
    return 0;
}
