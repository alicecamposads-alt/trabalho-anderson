#include <iostream>
using namespace std;

int main() {
    int idade;
    bool documentoValido;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Documento valido? (1 = sim / 0 = nao): ";
    cin >> documentoValido;

    if (idade >= 18 && documentoValido) {
        cout << "Pode iniciar o processo para obtencao da CNH." << endl;
    } 
    else {
        cout << "Nao pode iniciar o processo." << endl;
    }

    return 0;
}