//#include "Produto.h"
#include "C:\Users\jonas\Desktop\TrabalhoGBc1\include\Produto.h"

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
        cout << (*itIP)->getQuantidade() << '(' << (*itIP)->getUnidadeMedida() << ')' << endl;

    }

}

void Produto::produzir(int opcao)
{
    Insumo insumo;

    if(opcao == 1)
    {
        this->setQuantEstoque(this->getQuantMinEstoque());
    }
    if(opcao == 2)
    {
        if(this->getQuantEstoque() < this->getQuantMinEstoque()) // SE A QUANTIDADE MINIMA FOR MENOR QUE A ATUAL, ENTRA NO LAÇO
        {
            float dif = 0, quantAAdicionar = 0;

            dif = this->getQuantMinEstoque() - this->getQuantEstoque();

            cout << endl << "Dados do produto:" ;
            cout << "\nID: " << "\t\t\t" << this->getIdProduto()
                 << "\nNome: " << "\t\t\t" << this->getNome()
                 << "\nValor: " << "\t\t\t" << "R$" << this->getValor()
                 << "\nUnidadeMedida: " << "\t\t" << this->getUnidadeMedida()
                 << "\nQuantEstoque: " << "\t\t" << this->getQuantEstoque()
                 << "\nQuantMinEstoque: " << "\t" << this->getQuantMinEstoque()
                 << "\n\nInsira a quantidade que deseja adicionar:\n*O minimo para este produto eh " << dif << '!' << endl << "Quantidade desejada: ";
            cin >> quantAAdicionar;

            while(quantAAdicionar < dif)
            {
                cout << "\nERRO: A quantidade desejada deve ser maior que a minima! Por favor, tente novamente: "
                     << "\n*O minimo para este produto eh " << dif << '!' << endl << "Quantidade desejada: ";
                cin >> quantAAdicionar;
            }

            for(vector<InsumosProduto*>::iterator itIP = this->lstInsumos.begin(); itIP != this->lstInsumos.end(); itIP++){ // LAÇO PARA LISTAR OS INSUMOS DE UM PRODUTO
                (*itIP)->getNomeInsumo();
                (*itIP)->getQuantidade();
                // VERIFICAR SE O INSUMO TEM QUANTIDADE EM ESTOQUE DISPONÍVEL PARA PRODUZIR A QTD DESEJADA DO PRODUTO
                // CRIAR MÉTODO QUE VERIFIQUE A QUANTIDADE EM ESTOQUE DO INSUMO
                //insumo.removerEstoque(); --NÃO CONSEGUI CHAMAR O INSUMO CERTO
            }

            this->setQuantEstoque(quantAAdicionar + this->getQuantEstoque());

            dif = 0;
        }
    }
}


void Produto::vender(){}
