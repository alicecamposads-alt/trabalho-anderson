/******************************************************************************
 Etapa 2
 Aluna: Alice Risso Campos Faria
Professor: Anderson
Materia: INF101 - Programacao de Computadores I
Data: 28/10/2026
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main() {

    // Variaveis
    const int MAX_CONTAS = 100;

    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS] = {false};
    bool cadastrada[MAX_CONTAS] = {false};

    int opcao;
    int numero;
    int posicao;
    int i;
    int tipo;

    // Menu do sistema
    do {
        cout << "\n************" << endl;
        cout << "BANCO ALICE" << endl;
        cout << "************" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1: {
                // Encontrar uma posicao livre
                posicao = -1;

                for (i = 0; i < MAX_CONTAS; i++) {
                    if (!cadastrada[i]) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    cout << "Limite de 5 contas atingido!" << endl;
                    break;
                }

                cout << "\nNumero da conta: ";
                cin >> numeroConta[posicao];

                if (numeroConta[posicao] <= 0) {
                    cout << "Numero da conta invalido!" << endl;
                    break;
                }

                // Verificar se o numero ja existe
                bool existe = false;

                for (i = 0; i < MAX_CONTAS; i++) {
                    if (cadastrada[i] &&
                        numeroConta[i] == numeroConta[posicao] &&
                        i != posicao) {
                        existe = true;
                    }
                }

                if (existe) {
                    cout << "Essa conta ja esta cadastrada!" << endl;
                    break;
                }

                cin.ignore();

                cout << "Nome do cliente: ";
                getline(cin, nomeCliente[posicao]);

                cout << "CPF do cliente: ";
                getline(cin, cpf[posicao]);

                cout << "Tipo da conta (1 - Corrente / 2 - Poupanca): ";
                cin >> tipo;

                if (tipo != 1 && tipo != 2) {
                    cout << "Tipo de conta invalido!" << endl;
                    break;
                }

                tipoConta[posicao] = tipo;

                cout << "Saldo inicial: ";
                cin >> saldo[posicao];

                if (saldo[posicao] < 0) {
                    cout << "O saldo nao pode ser negativo!" << endl;
                    break;
                }

                contaAtiva[posicao] = true;
                cadastrada[posicao] = true;

                cout << "Conta cadastrada com sucesso!" << endl;
                break;
            }

            case 2: {
                // Consultar os dados da conta
                cout << "Digite o numero da conta: ";
                cin >> numero;

                posicao = -1;

                for (i = 0; i < MAX_CONTAS; i++) {
                    if (cadastrada[i] && numeroConta[i] == numero) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    cout << "Conta nao encontrada!" << endl;
                } else {
                    cout << "\nNumero: " << numeroConta[posicao] << endl;
                    cout << "Cliente: " << nomeCliente[posicao] << endl;
                    cout << "CPF: " << cpf[posicao] << endl;

                    if (tipoConta[posicao] == 1) {
                        cout << "Tipo: Corrente" << endl;
                    } else {
                        cout << "Tipo: Poupanca" << endl;
                    }

                    cout << "Saldo: R$ " << saldo[posicao] << endl;

                    if (contaAtiva[posicao]) {
                        cout << "Situacao: Ativa" << endl;
                    } else {
                        cout << "Situacao: Inativa" << endl;
                    }
                }
                break;
            }

            case 3: {
                // Verificar saldo
                cout << "Digite o numero da conta: ";
                cin >> numero;

                posicao = -1;

                for (i = 0; i < MAX_CONTAS; i++) {
                    if (cadastrada[i] && numeroConta[i] == numero) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    cout << "Conta nao encontrada!" << endl;
                } else if (!contaAtiva[posicao]) {
                    cout << "A conta esta inativa!" << endl;
                } else {
                    cout << "Saldo atual: R$ "
                         << saldo[posicao] << endl;
                }
                break;
            }

            case 4: {
                // Alterar tipo da conta
                cout << "Digite o numero da conta: ";
                cin >> numero;

                posicao = -1;

                for (i = 0; i < MAX_CONTAS; i++) {
                    if (cadastrada[i] && numeroConta[i] == numero) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    cout << "Conta nao encontrada!" << endl;
                } else if (!contaAtiva[posicao]) {
                    cout << "A conta esta inativa!" << endl;
                } else {
                    cout << "Novo tipo (1 - Corrente / 2 - Poupanca): ";
                    cin >> tipo;

                    if (tipo == 1 || tipo == 2) {
                        tipoConta[posicao] = tipo;
                        cout << "Tipo alterado com sucesso!" << endl;
                    } else {
                        cout << "Tipo invalido!" << endl;
                    }
                }
                break;
            }

            case 5: {
                // Ativar ou desativar conta
                cout << "Digite o numero da conta: ";
                cin >> numero;

                posicao = -1;

                for (i = 0; i < MAX_CONTAS; i++) {
                    if (cadastrada[i] && numeroConta[i] == numero) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    cout << "Conta nao encontrada!" << endl;
                } else {
                    contaAtiva[posicao] = !contaAtiva[posicao];

                    if (contaAtiva[posicao]) {
                        cout << "Conta ativada!" << endl;
                    } else {
                        cout << "Conta desativada!" << endl;
                    }
                }
                break;
            }

            case 6:
                cout << "Sistema encerrado!" << endl;
                break;

            default:
                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 6);

    return 0;
}