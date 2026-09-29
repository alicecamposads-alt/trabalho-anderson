#include <iostream>
#include <string>
using namespace std;

int main() {
    string senha;

    cout << "Digite uma senha de 6 digitos: ";
    cin >> senha;

    if (senha.length() == 6 &&
        senha[0] >= '1' &&
        senha[5] != '0') {

        cout << "Senha valida." << endl;
    } 
    else {
        cout << "Senha invalida." << endl;
    }

    return 0;
}