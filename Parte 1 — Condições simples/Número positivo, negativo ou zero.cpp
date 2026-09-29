#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    if (numero > 0) {
        cout << "Positivo." << endl;
    } 
    else if (numero < 0) {
        cout << "Negativo." << endl;
    } 
    else {
        cout << "Igual a zero." << endl;
    }

    return 0;
}