#include <iostream>
using namespace std;

int main() {
    int idade;
    bool usuarioValido, senhaValida, bloqueado;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Usuario valido? (1 = sim / 0 = nao): ";
    cin >> usuarioValido;

    cout << "Senha valida? (1 = sim / 0 = nao): ";
    cin >> senhaValida;

    cout << "Usuario bloqueado? (1 = sim / 0 = nao): ";
    cin >> bloqueado;

    if (idade >= 18 && usuarioValido && senhaValida && !bloqueado) {
        cout << "Acesso permitido." << endl;
    } 
    else {
        cout << "Acesso negado." << endl;
    }

    return 0;
}