#include <iostream>
using namespace std;

int main() {
    int idade;
    bool possuiIngresso;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Possui ingresso? (1 = sim / 0 = nao): ";
    cin >> possuiIngresso;

    if (idade >= 18 && possuiIngresso) {
        cout << "Entrada permitida." << endl;
    } 
    else {
        cout << "Entrada nao permitida." << endl;
    }

    return 0;
}