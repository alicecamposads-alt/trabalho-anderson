#include <iostream>
using namespace std;

int main() {
    bool manutencao;

    cout << "O sistema esta em manutencao? (1 = sim / 0 = nao): ";
    cin >> manutencao;

    if (!manutencao) {
        cout << "Sistema disponivel." << endl;
    } 
    else {
        cout << "Sistema indisponivel." << endl;
    }

    return 0;
}