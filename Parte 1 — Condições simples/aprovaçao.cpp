#include <iostream>
using namespace std;

int main() {
    double nota1, nota2, media;

    cout << "Digite a primeira nota: ";
    cin >> nota1;

    cout << "Digite a segunda nota: ";
    cin >> nota2;

    media = (nota1 + nota2) / 2;

    cout << "Media: " << media << endl;

    if (media >= 60) {
        cout << "Aprovado." << endl;
    } 
    else {
        cout << "Reprovado." << endl;
    }

    return 0;
}