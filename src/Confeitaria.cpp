//#include "Confeitaria.h"
#include "C:\Users\jonas\Desktop\TrabalhoGBc\include\Confeitaria.h"

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

            cout << "==================================================================================================" << endl;
            cout << "-----CONSULTA PRODUTO-----" << endl;
            cout << "ID: " << "\t\t\t" << (*itP)->getIdProduto()
            << "\nNome: " << "\t\t\t" << (*itP)->getNome()
            << "\nValor: " << "\t\t\t" << "R$" << (*itP)->getValor()
            << "\nUnidadeMedida: " << "\t\t" << (*itP)->getUnidadeMedida()
            << "\nQuantEstoque: " << "\t\t" << (*itP)->getQuantEstoque()
            << "\nQuantMinEstoque: " << "\t" << (*itP)->getQuantMinEstoque() << endl;
            cout << "\nInsumos necessarios para produzi-lo:" << endl;
            (*itP)->listaInsumos();
            cout << "==================================================================================================" << endl;

        }

    }

}
void Confeitaria::consultaProduto(string nomeEscolhido){

    for(vector<Produto*>::iterator itP = lstProdutos.begin(); itP != lstProdutos.end(); itP++){ // LAÇO PARA PROCURA DO PRODUTO ESCOLHIDO
        cout << "==================================================================================================" << endl;
        cout << "-----CONSULTA PRODUTO-----" << endl;
        if(nomeEscolhido == (*itP)->getNome()){

            cout << "ID: " << "\t\t\t" << (*itP)->getIdProduto()
            << "\nNome: " << "\t\t\t" << (*itP)->getNome()
            << "\nValor: " << "\t\t\t" << "R$" << (*itP)->getValor()
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
            << "\nValor: " << "\t\t\t" << "R$" << (*itI)->getValor()
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
            << "\nValor: " << "\t\t\t" << "R$" << (*itI)->getValor()
            << "\nUnidadeMedida: " << "\t\t" << (*itI)->getUnidadeMedida()
            << "\nQuantEstoque: " << "\t\t" << (*itI)->getQuantEstoque()
            << "\nQuantMinEstoque: " << "\t" << (*itI)->getQuantMinEstoque() << endl;

        }

    }

}

void Confeitaria::insumosAProduzir(){
    char opSN;
    int op12, cont = 0;

    cout << "==================================================================================================" << endl;
    cout << "-----LISTA DE INSUMOS A PRODUZIR-----" << endl;

    for(vector<Insumo*>::iterator itI = lstInsumos.begin(); itI != lstInsumos.end(); itI++)  // LÊ LISTA DE INSUMOS DO INÍCIO AO FIM
    {
        if((*itI)->getQuantEstoque() < (*itI)->getQuantMinEstoque())  // SE A QUANTIDADE MINIMA FOR MENOR QUE A ATUAL, ENTRA NO LAÇO
        {
            cout << "ID: " << "\t\t\t" <<(*itI)->getIdInsumo()
                 << "\nNome: " << "\t\t\t" <<(*itI)->getNome()
                 << "\nValor: " << "\t\t\t" << "R$" << (*itI)->getValor()
                 << "\nUnidadeMedida: " << "\t\t" << (*itI)->getUnidadeMedida()
                 << "\nQuantEstoque: " << "\t\t" << (*itI)->getQuantEstoque()
                 << "\nQuantMinEstoque: " << "\t" << (*itI)->getQuantMinEstoque() << endl << endl;
            cont++;
        }
    }
    cout << "==================================================================================================" << endl;
    if(cont != 0) // VERIFICA SE A LISTAGEM ESTÁ VAZIA
    {
        cout << "Deseja comprar os insumos que faltam (s/n)? ";
        cin >> opSN;

        if(opSN == 's' || opSN == 'S') //ESSAS OPÕES APENAS SUBSTITUEM OS VALORES DE quantEstoque DO INSUMO NA MEMÓRIA, NÃO SALVA NO ARQUIVO TXT!!!
        {
            cout << "1- Para adicionar apenas as quantidades que faltam.\n2- Para adicionar quantidades personalizadas\nOpcao escolhida: ";
            cin >> op12;

            system("cls");

            if(op12 == 1)
            {
                cout << "Opcao escolhida: 1- Adicionar apenas as quantidades que faltam\n";
                for(vector<Insumo*>::iterator itI = lstInsumos.begin(); itI != lstInsumos.end(); itI++) // LÊ LISTA DE INSUMOS DO INÍCIO AO FIM
                {
                    if((*itI)->getQuantEstoque() < (*itI)->getQuantMinEstoque()) // SE A QUANTIDADE MINIMA FOR MENOR QUE A ATUAL, ENTRA NO LAÇO
                    {
                        float dif = 0, varX = 0;

                        dif = (*itI)->getQuantMinEstoque() - (*itI)->getQuantEstoque();
                        varX = dif + (*itI)->getQuantEstoque();

                        (*itI)->setQuantEstoque(varX);
                        //(*itI)->inserirEstoque(varX); // PARA SALVAR NO ARQUIVO INSUMO.TXT DEVE SER CRIADO O MÉTODO inserirEstoque
                        varX = 0;
                        dif = 0;
                    }
                }
                cout << "Quantidades faltantes adicionadas com sucesso! \n";
            }
            if(op12 == 2)
            {
                cout << "Opcao escolhida: 2- Adicionar quantidades personalizadas\n";
                for(vector<Insumo*>::iterator itI = lstInsumos.begin(); itI != lstInsumos.end(); itI++) // LÊ LISTA DE INSUMOS DO INÍCIO AO FIM
                {
                    if((*itI)->getQuantEstoque() < (*itI)->getQuantMinEstoque()) // SE A QUANTIDADE MINIMA FOR MENOR QUE A ATUAL, ENTRA NO LAÇO
                    {
                        float dif = 0, varX = 0, quantAAdicionar = 0;

                        dif = (*itI)->getQuantMinEstoque() - (*itI)->getQuantEstoque();

                        cout << endl << "Dados do insumo:" ;
                        cout << "\nID: " << "\t\t\t" <<(*itI)->getIdInsumo()
                             << "\nNome: " << "\t\t\t" <<(*itI)->getNome()
                             << "\nValor: " << "\t\t\t" << "R$" << (*itI)->getValor()
                             << "\nUnidadeMedida: " << "\t\t" << (*itI)->getUnidadeMedida()
                             << "\nQuantEstoque: " << "\t\t" << (*itI)->getQuantEstoque()
                             << "\nQuantMinEstoque: " << "\t" << (*itI)->getQuantMinEstoque()
                             << "\n\nInsira a quantidade que deseja adicionar:\n*O minimo para este insumo eh " << dif << '!' << endl << "Quantidade desejada: ";
                        cin >> quantAAdicionar;
                        while(quantAAdicionar < dif)
                        {
                            cout << "\nERRO: A quantidade desejada deve ser maior que a minima! Por favor, tente novamente: "
                                 << "\n*O minimo para este produto eh " << dif << '!' << endl << "Quantidade desejada: ";
                            cin >> quantAAdicionar;
                        }
                        varX = quantAAdicionar + (*itI)->getQuantEstoque();
                        (*itI)->setQuantEstoque(varX);
                        //(*itI)->inserirEstoque(dif); // PARA SALVAR NO ARQUIVO PRODUTO.TXT DEVE SER CRIADO O MÉTODO inserirEstoque
                        varX = 0;
                        dif = 0;
                    }
                }
            }
        }
    }
}

void Confeitaria::produtosAProduzir(){
    char opSN;
    int op12, cont = 0;

    cout << "==================================================================================================" << endl;
    cout << "\n-----LISTA DE PRODUTOS A PRODUZIR-----\n";

    for(vector<Produto*>::iterator itI = lstProdutos.begin(); itI != lstProdutos.end(); itI++)  // LÊ LISTA DE PRODUTOS DO INÍCIO AO FIM
    {
        if((*itI)->getQuantEstoque() < (*itI)->getQuantMinEstoque())  // SE A QUANTIDADE MINIMA FOR MENOR QUE A ATUAL, ENTRA NO LAÇO
        {
            cout << "\nID: " << "\t\t\t" <<(*itI)->getIdProduto()
                 << "\nNome: " << "\t\t\t" <<(*itI)->getNome()
                 << "\nValor: " << "\t\t\t" << "R$" << (*itI)->getValor()
                 << "\nUnidadeMedida: " << "\t\t" << (*itI)->getUnidadeMedida()
                 << "\nQuantEstoque: " << "\t\t" << (*itI)->getQuantEstoque()
                 << "\nQuantMinEstoque: " << "\t" << (*itI)->getQuantMinEstoque() << endl;
            cont++;
        }
    }
    cout << "--------------------------------------\n\n";
    cout << "==================================================================================================" << endl;
    if(cont != 0) // VERIFICA SE A LISTAGEM ESTÁ VAZIA
    {
        cout << "Deseja comprar os produtos que faltam (s/n)? ";
        cin >> opSN;

        if(opSN == 's' || opSN == 'S') //ESSAS OPÕES APENAS SUBSTITUEM OS VALORES DE quantEstoque DO INSUMO NA MEMÓRIA, NÃO SALVA NO ARQUIVO TXT!!!
        {
            cout << "1- Para adicionar apenas as quantidades que faltam.\n2- Para adicionar quantidades personalizadas\nOpcao escolhida: ";
            cin >> op12;

            system("cls");

            if(op12 == 1)
            {
                cout << "Opcao escolhida: 1- Adicionar apenas as quantidades que faltam\n";
                for(vector<Produto*>::iterator itI = lstProdutos.begin(); itI != lstProdutos.end(); itI++) // LÊ LISTA DE PRODUTOS DO INÍCIO AO FIM
                {
                    if((*itI)->getQuantEstoque() < (*itI)->getQuantMinEstoque()) // SE A QUANTIDADE MINIMA FOR MENOR QUE A ATUAL, ENTRA NO LAÇO
                    {
                        float dif = 0, varX = 0;

                        dif = (*itI)->getQuantMinEstoque() - (*itI)->getQuantEstoque();
                        varX = dif + (*itI)->getQuantEstoque();

                        (*itI)->setQuantEstoque(varX);
                        //(*itI)->inserirEstoque(varX); // PARA SALVAR NO ARQUIVO PRODUTO.TXT DEVE SER CRIADO O MÉTODO inserirEstoque
                        varX = 0;
                        dif = 0;
                    }
                }
                cout << "Quantidades faltantes adicionadas com sucesso! \n";
            }
            if(op12 == 2)
            {
                cout << "Opcao escolhida: 2- Adicionar quantidades personalizadas\n";
                for(vector<Produto*>::iterator itI = lstProdutos.begin(); itI != lstProdutos.end(); itI++) // LÊ LISTA DE PRODUTOS DO INÍCIO AO FIM
                {
                    if((*itI)->getQuantEstoque() < (*itI)->getQuantMinEstoque()) // SE A QUANTIDADE MINIMA FOR MENOR QUE A ATUAL, ENTRA NO LAÇO
                    {
                        float dif = 0, varX = 0, quantAAdicionar = 0;

                        dif = (*itI)->getQuantMinEstoque() - (*itI)->getQuantEstoque();

                        cout << endl << "Dados do produto:" ;
                        cout << "\nID: " << "\t\t\t" <<(*itI)->getIdProduto()
                             << "\nNome: " << "\t\t\t" <<(*itI)->getNome()
                             << "\nValor: " << "\t\t\t" << "R$" << (*itI)->getValor()
                             << "\nUnidadeMedida: " << "\t\t" << (*itI)->getUnidadeMedida()
                             << "\nQuantEstoque: " << "\t\t" << (*itI)->getQuantEstoque()
                             << "\nQuantMinEstoque: " << "\t" << (*itI)->getQuantMinEstoque()
                             << "\n\nInsira a quantidade que deseja adicionar:\n*O minimo para este produto eh " << dif << '!' << endl << "Quantidade desejada: ";
                        cin >> quantAAdicionar;

                        while(quantAAdicionar < dif)
                        {
                            cout << "\nERRO: A quantidade desejada deve ser maior que a minima! Por favor, tente novamente: "
                                 << "\n*O minimo para este produto eh " << dif << '!' << endl << "Quantidade desejada: ";
                            cin >> quantAAdicionar;
                        }
                        varX = quantAAdicionar + (*itI)->getQuantEstoque();
                        (*itI)->setQuantEstoque(varX);
                        //(*itI)->inserirEstoque(dif); // PARA SALVAR NO ARQUIVO PRODUTO.TXT DEVE SER CRIADO O MÉTODO inserirEstoque
                        varX = 0;
                        dif = 0;
                    }
                }
            }
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
