#include <iostream>
using namespace std;

int main() {
    bool bloqueado;

    cout << "O usuario esta bloqueado? (1 = sim / 0 = nao): ";
    cin >> bloqueado;

    if (!bloqueado) {
        cout << "Acesso permitido." << endl;
    } 
    else {
        cout << "Acesso negado." << endl;
    }

    return 0;
}