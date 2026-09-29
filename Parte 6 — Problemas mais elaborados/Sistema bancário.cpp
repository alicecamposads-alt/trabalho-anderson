#include <iostream>
using namespace std;

int main() {
    double saldo, valorSaque;

    cout << "Digite o saldo: ";
    cin >> saldo;

    cout << "Digite o valor do saque: ";
    cin >> valorSaque;

    if (valorSaque > 0 && valorSaque <= saldo) {
        saldo = saldo - valorSaque;

        cout << "Saque realizado com sucesso." << endl;
        cout << "Saldo restante: R$ " << saldo << endl;
    } 
    else if (valorSaque <= 0) {
        cout << "Saque invalido: o valor deve ser maior que zero." << endl;
    } 
    else {
        cout << "Saque nao realizado: saldo insuficiente." << endl;
    }

    return 0;
}