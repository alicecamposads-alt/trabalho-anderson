#include <iostream>
using namespace std;

int main() {
    int idade;

    cout << "Digite sua idade: ";
    cin >> idade;

    if (idade < 16) {
        cout << "Nao pode votar." << endl;
    }
    else if (idade >= 16 && idade <= 17) {
        cout << "Voto facultativo." << endl;
    }
    else if (idade >= 18 && idade <= 69) {
        cout << "Voto obrigatorio." << endl;
    }
    else {
        cout << "Voto facultativo." << endl;
    }

    return 0;
}