#include "Confeitaria.h"
#include "cstdlib"
#include "cstdio"

int main(){

    Confeitaria *sonho = new Confeitaria();

    char opcao = ' ';

    /*sonho->listarProdutos();
    //sonho->listarInsumos();

    //sonho->consultaInsumo(1);
    //sonho->consultaInsumo("Sal");

    //sonho->atualizarProduto();

    //sonho->consultaProduto(1);
    sonho->consultaProduto("Pao branco");

    sonho->venderProdutos();

    //sonho->listarProdutos();
    //sonho->listarVendas();

    //sonho->salvarConfeitaria();
    sonho->consultaProduto(1);*/

    /*sonho->listarInsumos();
    sonho->atualizarInsumos();
    sonho->listarInsumos();*/

    /*sonho->listarProdutos();
    sonho->listarInsumos();
    sonho->atualizarProdutos();
    sonho->listarProdutos();
    sonho->listarInsumos();*/

    while(opcao != '0'){

        system("cls");

        cout << "Administrador de Confeitaria" << endl;
        cout << "1 - Realizar venda" << endl
        << "2 - Consultar produto" << endl
        << "3 - Consultar insumo" << endl
        << "4 - Listar produtos a produzir" << endl
        << "5 - Listar insumos a comprar" << endl
        << "6 - Listar todos os produtos" << endl
        << "7 - Listar todos os insumos" << endl
        << "8 - Listar vendas" << endl
        << "9 - Salvar" << endl
        << "0 - Sair" << endl
        << "\nOpcao: ";

        cin >> opcao;

        switch(opcao){

            case '1':
                sonho->venderProdutos();//PROBLEMA
                break;

            case '2':
                fflush(stdin);
                cout << "Digite <1> para consultar por ID - Digite <2> para consultar por Nome: ";
                cin >> opcao;

                if(opcao == '1'){
                    int id;
                    fflush(stdin);
                    cout << "Digite o ID do produto desejado: ";
                    cin >> id;
		
                while(cin.fail()){ //VERIFICA SE USUARIO DIGIOU UM ID INTEIRO, CASO TENHA SIDO CHAR ELE PEDE PARA REPETIR
                    cout << "ERRO! VOCE NAO DIGITOU UM INTEIRO. TENTE NOVAMENTE: " << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> id;
                }

                    sonho->consultaProduto(id);
                    break;
                }
                else if(opcao == '2'){
                    string nome;
                    fflush(stdin);
                    cout << "Digite o Nome do produto desejado: ";
                    getline(cin, nome);
                    sonho->consultaProduto(nome);
                    break;
                }
                else cout << "ERRO! OPCAO INVALIDA!" << endl;

                break;

            case '3':
                fflush(stdin);
                cout << "Digite <1> para consultar por ID - Digite <2> para consultar por Nome: ";
                cin >> opcao;

                if(opcao == '1'){
                    int id;
                    fflush(stdin);
                    cout << "Digite o ID do insumo desejado: ";
                    cin >> id;
                    sonho->consultaInsumo(id);
                    break;
                }
                else if(opcao == '2'){
                    string nome;
                    fflush(stdin);
                    cout << "Digite o Nome do insumo desejado: ";
                    getline(cin, nome);
                    sonho->consultaInsumo(nome);
                    break;
                }
                else cout << "ERRO! OPCAO INVALIDA!" << endl;

                break;

            case '4':
                sonho->atualizarProdutos();
                break;

            case '5':
                sonho->atualizarInsumos();
                break;

            case '6':
                sonho->listarProdutos();
                break;

            case '7':
                sonho->listarInsumos();
                break;

            case '8':
                sonho->listarVendas();
                break;

            case '9':
                cout << "\nSalvando dados do sistema...\n" << endl;
                sonho->salvarConfeitaria();
                break;

            case '0':
                cout << "\ndesligando programa...\n" << endl;
                sonho->salvarConfeitaria();
                break;

            case 'p':
                break;

            default:
                cout << "\nERRO! OPCAO INVALIDA!\n" << endl;
                break;

        }

        system("pause");

    }

    delete sonho;
    return 0;

}
