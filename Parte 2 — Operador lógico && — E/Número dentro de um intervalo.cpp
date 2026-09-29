#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Digite um numero: ";
    cin >> numero;

    if (numero >= 10 && numero <= 50) {
        cout << "O numero esta entre 10 e 50." << endl;
    } 
    else {
        cout << "O numero nao esta entre 10 e 50." << endl;
    }

    return 0;
}