#include <iostream>
using namespace std;

int main() {

    // Variáveis utilizadas nas expressões
    int numero = 50;
    int idade = 20;
    bool possuiCarteira = true;
    bool usuarioValido = true;
    bool senhaValida = true;
    bool bloqueado = false;
    bool vip = false;
    double compra = 1200;

    // a) Número entre 20 e 100
    if (numero >= 20 && numero <= 100) {
        cout << "a) O numero esta entre 20 e 100." << endl;
    }

    // b) Número menor que 0 ou maior que 100
    if (numero < 0 || numero > 100) {
        cout << "b) O numero e menor que 0 ou maior que 100." << endl;
    } else {
        cout << "b) O numero nao e menor que 0 nem maior que 100." << endl;
    }

    // c) Pessoa maior de idade e com carteira de motorista
    if (idade >= 18 && possuiCarteira) {
        cout << "c) A pessoa e maior de idade e possui carteira." << endl;
    } else {
        cout << "c) A pessoa nao atende as duas condicoes." << endl;
    }

    // d) Pessoa menor de idade ou sem carteira de motorista
    if (idade < 18 || !possuiCarteira) {
        cout << "d) A pessoa e menor de idade ou nao possui carteira." << endl;
    } else {
        cout << "d) A pessoa nao e menor de idade e possui carteira." << endl;
    }

    // e) Usuario valido, senha valida e nao bloqueado
    if (usuarioValido && senhaValida && !bloqueado) {
        cout << "e) Usuario valido, senha valida e nao bloqueado." << endl;
    } else {
        cout << "e) Acesso nao permitido." << endl;
    }

    // f) Cliente VIP ou compra acima de R$ 1.000
    if (vip || compra > 1000) {
        cout << "f) Cliente VIP ou compra acima de R$ 1.000." << endl;
    } else {
        cout << "f) Cliente nao e VIP e a compra nao ultrapassa R$ 1.000." << endl;
    }

    return 0;
}