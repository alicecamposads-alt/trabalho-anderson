#include <iostream>
using namespace std;

int main() {
    double media, frequencia;

    cout << "Digite a media: ";
    cin >> media;

    cout << "Digite a frequencia (%): ";
    cin >> frequencia;

    if (media >= 60 && frequencia >= 75) {
        cout << "Aprovado." << endl;
    } 
    else {
        cout << "Reprovado." << endl;
    }

    return 0;
}