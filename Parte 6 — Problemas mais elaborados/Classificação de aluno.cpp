#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    double media, frequencia;

    cout << "Digite o nome do aluno: ";
    cin >> nome;

    cout << "Digite a media: ";
    cin >> media;

    cout << "Digite a frequencia (%): ";
    cin >> frequencia;

    if (media >= 70 && frequencia >= 75) {
        cout << nome << ": Aprovado." << endl;
    }
    else if (media >= 50 && media < 70 && frequencia >= 75) {
        cout << nome << ": Recuperacao." << endl;
    }
    else {
        cout << nome << ": Reprovado." << endl;
    }

    return 0;
}