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

    for(vector<Produto*>::iterator itP = this->lstProdutos.begin(); itP != this->lstProdutos.end(); itP++){ // LACO PARA ATRIBUIR A TODOS OS PRODUTOS A SUA LISTA DE INSUMOS CONSTITUINTES

        file.open("InsumosProduto.txt", fstream::in); // ABRE O ARQUIVO InsumosProduto.txt PARA LEITURA

        if(file.is_open()){

            getline(file, nome);

            while(!file.eof()){

                /*getline(file, nome, '\t');
                cout << nome << endl;
                getline(file, nome, '\t');
                cout << nome << endl;
                file >> quantidade;
                cout << quantidade << '!' << endl;*/



                //cout << 'B' << ' ';

                getline(file, nome, '\t'); // RECEBE O NOME DO PRODUTO

                cout << nome << "---" << (*itP)->getNome() << nome.compare((*itP)->getNome()) << endl;

                if(nome == (*itP)->getNome()){
                    cout << nome << '&' << (*itP)->getNome() << '!' << endl;
                    //file.get();
                    getline(file, nome, '\t'); // RECEBE O NOME DO INSUMO A PROCURAR
                    //cout << nome;

                    file >> quantidade;

                    for(vector<Insumo*>::iterator itI = this->lstInsumos.begin(); itI != this->lstInsumos.end(); itI++){ // LACO PARA PROCURAR O INSUMO ENCONTRADO NA LISTA DE INSUMOS NA LISTA DE INSUMOS

                        //cout << (*itI)->getNome() << '@';
                        if(nome == (*itI)->getNome()){

                            (*itP)->leInsumosProduto(*itI, quantidade);
                            cout << (*itI)->getNome() << ' ' << quantidade << endl;

                            break;

                        }

                    }
                    file.get();
                }
                else getline(file, nome); // lixo

                cout << endl;
            }

            file.close();

        }
        else cout << "ERRO! FALHA AO ABIR O ARQUIVO!" << endl;

    }

}

/// DESTRUTOR
Confeitaria::~Confeitaria(){}

/// MÉTODOS
void Confeitaria::listarProdutos(){

    cout << "IdProduto" << '\t' << "Nome" << '\t' << "Valor" << '\t' << "UnidadeMedida" << '\t' << "QuantEstoque" << '\t' << "QuantMinEstoque" << endl;

    for(vector<Produto*>::iterator itP = lstProdutos.begin(); itP != lstProdutos.end(); itP++){ // UTILIZA O ITERADOR PARA PEGAR APENAS DADOS DE CADA COMPONENTE DO VECTOR DE PRODUTOS
        cout << (*itP)->getIdProduto();
        cout << '\t' << (*itP)->getNome();
        cout << '\t' << (*itP)->getValor();
        cout << '\t' << (*itP)->getUnidadeMedida();
        cout << '\t' << (*itP)->getQuantEstoque();
        cout << '\t' << (*itP)->getQuantMinEstoque() << endl;
    }

}

void Confeitaria::listarInsumos(){

    cout << "IdInsumo" << '\t' << "Nome" << '\t' << "Valor" << '\t' << "UnidadeMedida" << '\t' << "QuantEstoque" << '\t' << "quantMinEstoque" << endl;

    for(vector<Insumo*>::iterator itI = lstInsumos.begin(); itI != lstInsumos.end(); itI++){ // UTILIZA O ITERADOR PARA PEGAR APENAS DADOS DE CADA COMPONENTE DO VECTOR DE INSUMOS
        cout << (*itI)->getIdInsumo();
        cout << '\t' << (*itI)->getNome();
        cout << '\t' << (*itI)->getValor();
        cout << '\t' << (*itI)->getUnidadeMedida();
        cout << '\t' << (*itI)->getQuantEstoque();
        cout << '\t' << (*itI)->getQuantMinEstoque() << endl;
    }

}
