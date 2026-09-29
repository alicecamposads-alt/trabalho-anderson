#include <iostream>
using namespace std;

int main() {
    int idade;
    bool possuiCondicao;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Possui condicao que da direito a prioridade? (1 = sim / 0 = nao): ";
    cin >> possuiCondicao;

    if (idade >= 60 || possuiCondicao) {
        cout << "Atendimento prioritario." << endl;
    } 
    else {
        cout << "Atendimento normal." << endl;
    }

    return 0;
}