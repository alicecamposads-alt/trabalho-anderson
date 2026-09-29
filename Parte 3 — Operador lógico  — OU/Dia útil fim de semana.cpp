#include <iostream>
using namespace std;

int main() {
    int dia;

    cout << "Digite um numero de 1 a 7: ";
    cin >> dia;

    if (dia == 1 || dia == 7) {
        cout << "Fim de semana." << endl;
    } 
    else {
        cout << "Dia util." << endl;
    }

    return 0;
}