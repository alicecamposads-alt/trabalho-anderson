/******************************************************************************
 Nome: Alice Risso Campos Faria
Professor: Anderson R. Lamas e Vanderlea Queiroz
Materia: INF101 - Programacao de Computadores I
Data: 04/11/2026

Trabalho: Sistema de Registro e Gestao de Contas Bancarias
Etapa 2
*******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    const int MAX_CONTAS = 100;
    const int MAX_MOVIMENTACOES = 500;

    // Dados das contas
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    int quantidadeContas = 0;

    // Historico de movimentacoes
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeMovimentacoes = 0;

    // CONTAS JA CADASTRADAS

    numeroConta[0] = 1001;
    nomeCliente[0] = "Ana";
    cpf[0] = "00000000000";
    tipoConta[0] = 1;
    saldo[0] = 1000.00;
    contaAtiva[0] = true;

    numeroConta[1] = 1002;
    nomeCliente[1] = "Bruno";
    cpf[1] = "11111111111";
    tipoConta[1] = 1;
    saldo[1] = 500.00;
    contaAtiva[1] = true;

    quantidadeContas = 2;

    int opcao;

    cout << fixed << setprecision(2);

    do {

        cout << "\n===== SISTEMA BANCARIO =====\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Listar contas\n";
        cout << "3 - Consultar conta\n";
        cout << "4 - Deposito\n";
        cout << "5 - Saque\n";
        cout << "6 - Transferencia\n";
        cout << "7 - Extrato\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // CADASTRAR CONTA
            case 1: {

                if (quantidadeContas >= MAX_CONTAS) {
                    cout << "Limite de contas atingido!\n";
                    break;
                }

                int numero;
                bool existe = false;

                cout << "Numero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        existe = true;
                        break;
                    }
                }

                if (numero <= 0 || existe) {
                    cout << "Numero invalido ou ja cadastrado!\n";
                    break;
                }

                cin.ignore();

                numeroConta[quantidadeContas] = numero;

                cout << "Nome: ";
                getline(cin, nomeCliente[quantidadeContas]);

                cout << "CPF: ";
                getline(cin, cpf[quantidadeContas]);

                cout << "Tipo (1-Corrente / 2-Poupanca): ";
                cin >> tipoConta[quantidadeContas];

                cout << "Saldo inicial: ";
                cin >> saldo[quantidadeContas];

                if ((tipoConta[quantidadeContas] != 1 &&
                     tipoConta[quantidadeContas] != 2) ||
                    saldo[quantidadeContas] < 0) {
                    cout << "Dados invalidos!\n";
                    break;
                }

                contaAtiva[quantidadeContas] = true;
                quantidadeContas++;

                cout << "Conta cadastrada com sucesso!\n";

                break;
            }

            // LISTAR CONTAS
            case 2: {

                for (int i = 0; i < quantidadeContas; i++) {

                    cout << "\nNumero: " << numeroConta[i];
                    cout << "\nCliente: " << nomeCliente[i];
                    cout << "\nCPF: " << cpf[i];
                    cout << "\nTipo: "
                         << (tipoConta[i] == 1 ? "Corrente" : "Poupanca");
                    cout << "\nSaldo: R$ " << saldo[i];
                    cout << "\nSituacao: "
                         << (contaAtiva[i] ? "Ativa" : "Inativa");
                    cout << "\n-------------------------\n";
                }

                break;
            }

            // CONSULTAR CONTA
            case 3: {

                int numero, indice = -1;

                cout << "Numero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada!\n";
                } else {
                    cout << "\nCliente: " << nomeCliente[indice];
                    cout << "\nSaldo: R$ " << saldo[indice] << endl;
                }

                break;
            }

            // DEPOSITO
            case 4: {

                int numero, indice = -1;
                double valor;

                cout << "Numero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta inexistente ou inativa!\n";
                    break;
                }

                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Historico cheio!\n";
                    break;
                }

                cout << "Valor do deposito: ";
                cin >> valor;

                if (valor <= 0) {
                    cout << "Valor invalido!\n";
                    break;
                }

                saldo[indice] += valor;

                contaMovimentacao[quantidadeMovimentacoes] = numero;
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valor;

                quantidadeMovimentacoes++;

                cout << "Deposito realizado!\n";
                cout << "Saldo atual: R$ " << saldo[indice] << endl;

                break;
            }

            // SAQUE
            case 5: {

                int numero, indice = -1;
                double valor;

                cout << "Numero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta inexistente ou inativa!\n";
                    break;
                }

                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Historico cheio!\n";
                    break;
                }

                cout << "Valor do saque: ";
                cin >> valor;

                if (valor <= 0) {
                    cout << "Valor invalido!\n";
                    break;
                }

                if (saldo[indice] < valor) {
                    cout << "Saldo insuficiente!\n";
                    break;
                }

                saldo[indice] -= valor;

                contaMovimentacao[quantidadeMovimentacoes] = numero;
                tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                valorMovimentacao[quantidadeMovimentacoes] = valor;

                quantidadeMovimentacoes++;

                cout << "Saque realizado!\n";
                cout << "Saldo atual: R$ " << saldo[indice] << endl;

                break;
            }

            // TRANSFERENCIA
            case 6: {

                int origem, destino;
                int indiceOrigem = -1;
                int indiceDestino = -1;
                double valor;

                cout << "Conta de origem: ";
                cin >> origem;

                cout << "Conta de destino: ";
                cin >> destino;

                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == origem)
                        indiceOrigem = i;

                    if (numeroConta[i] == destino)
                        indiceDestino = i;
                }

                if (indiceOrigem == -1 || indiceDestino == -1) {
                    cout << "Conta nao encontrada!\n";
                    break;
                }

                if (!contaAtiva[indiceOrigem] ||
                    !contaAtiva[indiceDestino]) {
                    cout << "Conta inativa!\n";
                    break;
                }

                if (indiceOrigem == indiceDestino) {
                    cout << "Escolha contas diferentes!\n";
                    break;
                }

                if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                    cout << "Historico sem espaco suficiente!\n";
                    break;
                }

                cout << "Valor da transferencia: ";
                cin >> valor;

                if (valor <= 0) {
                    cout << "Valor invalido!\n";
                    break;
                }

                if (saldo[indiceOrigem] < valor) {
                    cout << "Saldo insuficiente!\n";
                    break;
                }

                saldo[indiceOrigem] -= valor;
                saldo[indiceDestino] += valor;

                // Saida da conta de origem
                contaMovimentacao[quantidadeMovimentacoes] = origem;
                tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                valorMovimentacao[quantidadeMovimentacoes] = valor;

                quantidadeMovimentacoes++;

                // Entrada na conta de destino
                contaMovimentacao[quantidadeMovimentacoes] = destino;
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valor;

                quantidadeMovimentacoes++;

                cout << "Transferencia realizada!\n";

                break;
            }

            // EXTRATO
            case 7: {

                int numero, indice = -1;
                bool encontrou = false;

                cout << "Numero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada!\n";
                    break;
                }

                cout << "\n===== EXTRATO =====\n";

                for (int i = 0; i < quantidadeMovimentacoes; i++) {

                    if (contaMovimentacao[i] == numero) {

                        encontrou = true;

                        if (tipoMovimentacao[i] == 'D') {
                            cout << "Deposito/Entrada: R$ ";
                        } else {
                            cout << "Saque/Saida: R$ ";
                        }

                        cout << valorMovimentacao[i] << endl;
                    }
                }

                if (!encontrou) {
                    cout << "Nenhuma movimentacao.\n";
                }

                cout << "Saldo atual: R$ " << saldo[indice] << endl;

                break;
            }

            case 0:
                cout << "Sistema encerrado!\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}