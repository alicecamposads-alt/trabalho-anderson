#include <iostream>
using namespace std;

int main() {
    bool membro, possuiCartao;
    double valorCompra;

    cout << "E membro? (1 = sim / 0 = nao): ";
    cin >> membro;

    cout << "Possui cartao? (1 = sim / 0 = nao): ";
    cin >> possuiCartao;

    cout << "Digite o valor da compra: ";
    cin >> valorCompra;

    if ((membro && possuiCartao) || valorCompra > 500) {
        cout << "Cliente tem direito ao desconto especial." << endl;
    } 
    else {
        cout << "Cliente nao tem direito ao desconto especial." << endl;
    }

    return 0;
}