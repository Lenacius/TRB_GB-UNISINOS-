#include "Confeitaria.h"

/// CONSTRUTOR
Confeitaria::Confeitaria(){

    fstream file;

    int id;
    string nome;
    float valor;
    string unidadeMedida;
    float quantEstoque;
    float quantMinEstoque;

    string nomeInsumo;
    float quantidade;

    file.open("Produtos.txt", fstream::in); // ABRE O ARQUIVO Produtos.txt PARA LEITURA

    if(file.is_open()){

        getline(file, nome); // CAPTURA A PRIMEIRA LINHA QUE CONTÉM APENAS DADOS NOMINAIS

        while(!file.eof()){ // ENQUANTO NÃO CHEGAR NO FINAL DO ARQUIVO

            file >> id;

            file.get(); // FUNÇÃO PARA CAPTURAR APENAS UM CARACTER, NO CASO '\t'
            getline(file, nome, '\t');

            file >> valor;

            file.get();
            getline(file, unidadeMedida, '\t');

            file >> quantEstoque;

            file >> quantMinEstoque;

            Produto *ponteiroProduto = new Produto(id, nome, valor, unidadeMedida, quantEstoque, quantMinEstoque); // ARMAZENA AS VARIAVEIS NUM PONTEIRO DA CLASSE PRODUTOS...

            this->lstProdutos.push_back(ponteiroProduto); // ...PARA INTRODUZI-LOS NO FINAL DO VECTOR lstProdutos

        }

        file.close();

    } // FIM DA LEITURA DOS DADOS PARA A LISTA DE PRODUTOS
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

    file.open("Insumos.txt", fstream::in); // ABRE O ARQUIVO Insumos.txt PARA LEITURA

    if(file.is_open()){

        getline(file, nome);

        while(!file.eof()){

            file >> id;

            file.get();
            getline(file, nome, '\t');

            file >> valor;

            file.get();
            getline(file, unidadeMedida, '\t');

            file >> quantEstoque;

            file >> quantMinEstoque;

            Insumo *ponteiroInsumo = new Insumo(id, nome, valor, unidadeMedida, quantEstoque, quantMinEstoque); // ARMAZENA AS VARIAVEIS NUM PONTEIRO DA CLASSE INSUMOS...

            this->lstInsumos.push_back(ponteiroInsumo); // ...PARA INTRODUZI-LOS NO FINAL DO VECTOR lstInsumos

        }

        file.close();

    } // FIM DA LEITURA DOS DADOS PARA A LISTA DE INSUMOS
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

    file.open("InsumosProduto.txt", fstream::in); // ABRE O ARQUIVO InsumosProduto.txt PARA LEITURA

    if(file.is_open()){

        getline(file, nome);

        while(!file.eof()){

            getline(file, nome, '\t'); // CAPTURA NOME DO PRODUTO
            //cout << nome << '&';
            getline(file, nomeInsumo, '\t'); // CAPTURA NOME DO INSUMO
            //cout << nomeInsumo << '&';
            file >> quantidade; // CAPTURA QUANTIDADE
            //cout << quantidade << endl;
            file.get(); // CAPTURA '\n'

            for(vector<Produto*>::iterator itP = this->lstProdutos.begin(); itP != this->lstProdutos.end(); itP++){

                for(vector<Insumo*>::iterator itI = this->lstInsumos.begin(); itI != this->lstInsumos.end(); itI++){

                    if(nome == (*itP)->getNome() && nomeInsumo == (*itI)->getNome()){

                        //cout << nome << '&' << nomeInsumo << endl;
                        (*itP)->leInsumosProduto(*itI, quantidade);
                        break;

                    }
                }

            }

        }

        file.close();

    } // FIM DA LEITURA DOS DADOS PARA A LISTA DE INSUMOS DE CADA PRODUTO
    else cout << "ERRO! FALHA AO ABRIR O ARQUIVO!" << endl;

}

/// DESTRUTOR
Confeitaria::~Confeitaria(){}

/// MÉTODOS
void Confeitaria::consultaProduto(int idEscolhido){

    for(vector<Produto*>::iterator itP = lstProdutos.begin(); itP != lstProdutos.end(); itP++){ // LAÇO PARA PROCURA DO PRODUTO ESCOLHIDO

        if(idEscolhido == (*itP)->getIdProduto()){

            cout << "ID: " << "\t\t\t" << (*itP)->getIdProduto()
            << "\nNome: " << "\t\t\t" << (*itP)->getNome()
            << "\nValor: " << "\t\t\t" << (*itP)->getValor()
            << "\nUnidadeMedida: " << "\t\t" << (*itP)->getUnidadeMedida()
            << "\nQuantEstoque: " << "\t\t" << (*itP)->getQuantEstoque()
            << "\nQuantMinEstoque: " << "\t" << (*itP)->getQuantMinEstoque() << endl;
            cout << "\nInsumos necessarios para produzi-lo:" << endl;
            (*itP)->listaInsumos();

        }

    }

}
void Confeitaria::consultaProduto(string nomeEscolhido){

    for(vector<Produto*>::iterator itP = lstProdutos.begin(); itP != lstProdutos.end(); itP++){ // LAÇO PARA PROCURA DO PRODUTO ESCOLHIDO

        if(nomeEscolhido == (*itP)->getNome()){

            cout << "ID: " << "\t\t\t" << (*itP)->getIdProduto()
            << "\nNome: " << "\t\t\t" << (*itP)->getNome()
            << "\nValor: " << "\t\t\t" << (*itP)->getValor()
            << "\nUnidadeMedida: " << "\t\t" << (*itP)->getUnidadeMedida()
            << "\nQuantEstoque: " << "\t\t" << (*itP)->getQuantEstoque()
            << "\nQuantMinEstoque: " << "\t" << (*itP)->getQuantMinEstoque() << endl;
            cout << "\nInsumos necessarios para produzi-lo:" << endl;
            (*itP)->listaInsumos();

        }

    }

}

void Confeitaria::consultaInsumo(int idEscolhido){

    for(vector<Insumo*>::iterator itI = lstInsumos.begin(); itI != lstInsumos.end(); itI++){ // LAÇO PARA PROCURA DO INSUMO ESCOLHIDO

        if(idEscolhido == (*itI)->getIdInsumo()){

            cout << "ID: " << "\t\t\t" <<(*itI)->getIdInsumo()
            << "\nNome: " << "\t\t\t" <<(*itI)->getNome()
            << "\nValor: " << "\t\t\t" << (*itI)->getValor()
            << "\nUnidadeMedida: " << "\t\t" << (*itI)->getUnidadeMedida()
            << "\nQuantEstoque: " << "\t\t" << (*itI)->getQuantEstoque()
            << "\nQuantMinEstoque: " << "\t" << (*itI)->getQuantMinEstoque() << endl;

        }

    }

}
void Confeitaria::consultaInsumo(string nomeEscolhido){

    for(vector<Insumo*>::iterator itI = lstInsumos.begin(); itI != lstInsumos.end(); itI++){ // LAÇO PARA PROCURA DO INSUMO ESCOLHIDO

        if(nomeEscolhido == (*itI)->getNome()){

            cout << "ID: " << "\t\t\t" <<(*itI)->getIdInsumo()
            << "\nNome: " << "\t\t\t" <<(*itI)->getNome()
            << "\nValor: " << "\t\t\t" << (*itI)->getValor()
            << "\nUnidadeMedida: " << "\t\t" << (*itI)->getUnidadeMedida()
            << "\nQuantEstoque: " << "\t\t" << (*itI)->getQuantEstoque()
            << "\nQuantMinEstoque: " << "\t" << (*itI)->getQuantMinEstoque() << endl;

        }

    }

}

void Confeitaria::listarProdutos(){

    cout << "IdProduto" << '\t' << "Nome" << '\t' << "Valor" << '\t' << "UnidadeMedida" << '\t' << "QuantEstoque" << '\t' << "QuantMinEstoque" << endl;

    for(vector<Produto*>::iterator itP = lstProdutos.begin(); itP != lstProdutos.end(); itP++){ // UTILIZA O ITERADOR PARA PEGAR APENAS DADOS DE CADA COMPONENTE DO VECTOR DE PRODUTOS
        cout << (*itP)->getIdProduto();
        cout << '\t' << (*itP)->getNome();
        cout << '\t' << (*itP)->getValor();
        cout << '\t' << (*itP)->getUnidadeMedida();
        cout << '\t' << (*itP)->getQuantEstoque();
        cout << '\t' << (*itP)->getQuantMinEstoque() << endl;

        //(*itP)->listaInsumos();
    }

}

void Confeitaria::listarInsumos(){

    cout << "IdInsumo" << '\t' << "Nome" << '\t' << "Valor" << '\t' << "UnidadeMedida" << '\t' << "QuantEstoque" << '\t' << "quantMinEstoque" << endl;

    for(vector<Insumo*>::iterator itI = lstInsumos.begin(); itI != lstInsumos.end(); itI++){ // UTILIZA O ITERADOR PARA PEGAR APENAS DADOS DE CADA COMPONENTE DO VECTOR DE PRODUTOS
        cout << (*itI)->getIdInsumo();
        cout << '\t' << (*itI)->getNome();
        cout << '\t' << (*itI)->getValor();
        cout << '\t' << (*itI)->getUnidadeMedida();
        cout << '\t' << (*itI)->getQuantEstoque();
        cout << '\t' << (*itI)->getQuantMinEstoque() << endl;
    }

}
