/*Aula 16/06
prof: Erika
exercicio 1 clase com encapsulamento
*/
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class ContaBancaria {
private:
    string titular;
    double saldo;
public:
    ContaBancaria(string t, double s) : titular(t), saldo(s){}


    string getTitular() const { return titular; }
    double getSaldo() const {return saldo; }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << " deposito de R$ " << valor  << " Realizado com susceso. " << endl;
        }
        else {
            cout << "valor invalido para depositar " << endl; 
        }
    }

    bool sacar(double valor) {
        if (valor > 0 && valor <= saldo){
            saldo -= valor;
            cout << " Saque de R$ " << valor << " realizado. "<<endl;
            return true;
        }else {
            cout << "saldo insuficiente ou valor invalido! " << endl;
            return false;
        }
    }

};

int main() {
    
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    ContaBancaria conta("joão", 1000.0);

    cout << "Titular: " << conta.getTitular() << endl;
    cout << "Saldo: " << conta.getSaldo() << endl;

    conta.depositar(500.0);
    conta.sacar(200.0);
    conta.sacar(2000.0);

    cout << "saldo final R$: " << conta.getSaldo() << endl;

};