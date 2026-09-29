#include <iostream>
using namespace std;

int main() {
    double media, renda;

    cout << "Digite a media: ";
    cin >> media;

    cout << "Digite a renda familiar: ";
    cin >> renda;

    if ((media >= 80 && renda <= 2000) || media >= 90) {
        cout << "Pode receber a bolsa de estudos." << endl;
    } 
    else {
        cout << "Nao pode receber a bolsa de estudos." << endl;
    }

    return 0;
}