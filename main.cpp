//#include "C:\Users\lolpa\Desktop\C++Projects\TRB_GB\include\Confeitaria.h" //QUANDO FOR TRABALHAR NO TEU PC, COMENTA A LINHA ABAIXO
//#include "C:\Users\jonas\Documents\GitHub\TRB_GB-UNISINOS-\include\Confeitaria.h"
#include "C:\Users\jonas\Desktop\TrabalhoGBc\include\Confeitaria.h"

#include <iostream>

using namespace std;

int main(){

    Confeitaria *sonho = new Confeitaria(); // QUANDO CRIADA A VARI�VEL O CONSTRUTOR J� PUXA OS DADOS DO ARQUIVO Produtos.txt

//    sonho->listarProdutos(); // FUN��O PARA CRIAR A LISTA DE PRODUTOS (SEM LISTA DE INSUMOS DO PRODUTO)
    sonho->listarInsumos(); // FUN��O PARA CRIAR A LISTA DE INSUMOS

//    sonho->consultaProduto(2);
//    sonho->consultaInsumo(3);

    sonho->insumosAProduzir();
    cout << endl;
    sonho->listarInsumos();

//    sonho->produtosAProduzir();
//    cout << endl;
//    sonho->listarProdutos();


    delete sonho;
    return 0;
}
