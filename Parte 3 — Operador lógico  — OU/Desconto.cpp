#include <iostream>
using namespace std;

int main() {
    bool possuiCartao;
    bool membro;

    cout << "Possui cartao da loja? (1 = sim / 0 = nao): ";
    cin >> possuiCartao;

    cout << "E membro do programa de fidelidade? (1 = sim / 0 = nao): ";
    cin >> membro;

    if (possuiCartao || membro) {
        cout << "Cliente tem direito ao desconto." << endl;
    } 
    else {
        cout << "Cliente nao tem direito ao desconto." << endl;
    }

    return 0;
}