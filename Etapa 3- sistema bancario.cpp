/******************************************************************************
 Nome: Alice Risso Campos Faria
 Professor:  Anderson R. Lamas e Vanderlea Queiroz
 Materia: INF101 - Programacao de Computadores I
 Data: 18/11/2026
 Trabalho: Sistema de Registro e Gestao de Contas Bancarias
 *******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

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


// FUNCOES DE ARQUIVO

void limparLinha(string &linha) {
    while (!linha.empty() &&
           (linha[linha.size() - 1] == '\r' ||
            linha[linha.size() - 1] == '\n')) {
        linha.erase(linha.size() - 1);
    }
}

// Carregar contas
void carregarContas() {
    quantidadeContas = 0;

    ifstream arquivo("contas.txt");

    if (!arquivo.is_open()) {
        return;
    }

    string linha;

    while (quantidadeContas < MAX_CONTAS &&
           getline(arquivo, linha)) {

        limparLinha(linha);

        if (linha.empty()) {
            continue;
        }

        stringstream ss(linha);
        string campo[6];
        int n = 0;

        while (n < 6 && getline(ss, campo[n], ';')) {
            n++;
        }

        if (n < 6) {
            continue;
        }

        numeroConta[quantidadeContas] = atoi(campo[0].c_str());
        nomeCliente[quantidadeContas] = campo[1];
        cpf[quantidadeContas] = campo[2];
        tipoConta[quantidadeContas] = atoi(campo[3].c_str());
        saldo[quantidadeContas] = atof(campo[4].c_str());
        contaAtiva[quantidadeContas] =
            (atoi(campo[5].c_str()) == 1);

        quantidadeContas++;
    }

    arquivo.close();
}

// Salvar contas
void salvarContas() {
    ofstream arquivo("contas.txt");

    if (arquivo.is_open()) {
        arquivo << fixed << setprecision(2);

        for (int i = 0; i < quantidadeContas; i++) {
            arquivo << numeroConta[i] << ";"
                    << nomeCliente[i] << ";"
                    << cpf[i] << ";"
                    << tipoConta[i] << ";"
                    << saldo[i] << ";"
                    << (contaAtiva[i] ? 1 : 0) << endl;
        }

        arquivo.close();
    } else {
        cout << "ERRO: nao foi possivel salvar o arquivo contas.txt\n";
    }
}

// Carregar movimentacoes
void carregarMovimentacoes() {
    quantidadeMovimentacoes = 0;

    ifstream arquivo("movimentacoes.txt");

    if (!arquivo.is_open()) {
        return;
    }

    string linha;

    while (quantidadeMovimentacoes < MAX_MOVIMENTACOES &&
           getline(arquivo, linha)) {

        limparLinha(linha);

        if (linha.empty()) {
            continue;
        }

        stringstream ss(linha);
        string campo[3];
        int n = 0;

        while (n < 3 && getline(ss, campo[n], ';')) {
            n++;
        }

        if (n < 3 || campo[1].empty()) {
            continue;
        }

        contaMovimentacao[quantidadeMovimentacoes] =
            atoi(campo[0].c_str());

        tipoMovimentacao[quantidadeMovimentacoes] = campo[1][0];

        valorMovimentacao[quantidadeMovimentacoes] =
            atof(campo[2].c_str());

        quantidadeMovimentacoes++;
    }

    arquivo.close();
}

// Salvar movimentacoes
void salvarMovimentacoes() {
    ofstream arquivo("movimentacoes.txt");

    if (arquivo.is_open()) {
        arquivo << fixed << setprecision(2);

        for (int i = 0; i < quantidadeMovimentacoes; i++) {
            arquivo << contaMovimentacao[i] << ";"
                    << tipoMovimentacao[i] << ";"
                    << valorMovimentacao[i] << endl;
        }

        arquivo.close();
    } else {
        cout << "ERRO: nao foi possivel salvar o arquivo movimentacoes.txt\n";
    }
}


// PROGRAMA PRINCIPAL

int main() {

    carregarContas();
    carregarMovimentacoes();

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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcao = -1;
        }

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

            string nome, cpfDigitado;
            int tipo;
            double saldoInicial;

            cout << "Nome: ";
            getline(cin, nome);

            cout << "CPF: ";
            getline(cin, cpfDigitado);

            cout << "Tipo (1-Corrente / 2-Poupanca): ";
            cin >> tipo;

            cout << "Saldo inicial: ";
            cin >> saldoInicial;

            for (size_t i = 0; i < nome.size(); i++) {
                if (nome[i] == ';') {
                    nome[i] = ' ';
                }
            }

            for (size_t i = 0; i < cpfDigitado.size(); i++) {
                if (cpfDigitado[i] == ';') {
                    cpfDigitado[i] = ' ';
                }
            }

            if (nome.empty() || cpfDigitado.empty() ||
                (tipo != 1 && tipo != 2) || saldoInicial < 0) {

                cout << "Dados invalidos!\n";
                break;
            }

            numeroConta[quantidadeContas] = numero;
            nomeCliente[quantidadeContas] = nome;
            cpf[quantidadeContas] = cpfDigitado;
            tipoConta[quantidadeContas] = tipo;
            saldo[quantidadeContas] = saldoInicial;
            contaAtiva[quantidadeContas] = true;

            quantidadeContas++;

            salvarContas();

            cout << "Conta cadastrada com sucesso!\n";

            break;
        }

        // LISTAR CONTAS
        case 2: {

            if (quantidadeContas == 0) {
                cout << "Nenhuma conta cadastrada.\n";
                break;
            }

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

            salvarContas();
            salvarMovimentacoes();

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

            salvarContas();
            salvarMovimentacoes();

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

                if (numeroConta[i] == origem) {
                    indiceOrigem = i;
                }

                if (numeroConta[i] == destino) {
                    indiceDestino = i;
                }
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

            salvarContas();
            salvarMovimentacoes();

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