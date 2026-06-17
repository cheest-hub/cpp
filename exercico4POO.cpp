/*Aula 15/06
prof: Erika
exercicio clase Pessoa
*/
#include <iostream>
#include <string>
#include <windows.h>

class ContaBancaria {
private:
    std::string titular;
    double saldo;

public:
    // Construtor: Inicializa o titular e começa o saldo com 0.0 por padrão
    ContaBancaria(std::string titular, double saldoInicial = 0.0) {
        this->titular = titular;
        this->saldo = saldoInicial;
    }

    // Método para depositar dinheiro
    void depositar(double valor) {
        if (valor > 0) {
            this->saldo += valor;
            std::cout << "Depósito de R$ " << valor << " realizado com sucesso!" << std::endl;
        } else {
            std::cout << "Erro: O valor do depósito deve ser positivo." << std::endl;
        }
    }

    // Método para sacar dinheiro
    void sacar(double valor) {
        if (valor > this->saldo) {
            std::cout << "Erro: Saldo insuficiente para sacar R$ " << valor << "." << std::endl;
        } else if (valor <= 0) {
            std::cout << "Erro: O valor do saque deve ser positivo." << std::endl;
        } else {
            this->saldo -= valor;
            std::cout << "Saque de R$ " << valor << " realizado com sucesso!" << std::endl;
        }
    }

    // Método para exibir o saldo atual
    void mostrarSaldo() {
        std::cout << "Titular: " << this->titular << " | Saldo Atual: R$ " << this->saldo << std::endl;
    }
};

int main() {
    // Configura o console para aceitar acentos (UTF-8)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Criação de uma conta bancária com saldo inicial de R$ 500.00
    ContaBancaria minhaConta("Carlos Oliveira", 500.00);
    minhaConta.mostrarSaldo();
    std::cout << "-----------------------------------" << std::endl;

    // Faz um depósito de R$ 250.00
    minhaConta.depositar(250.00);

    // Faz um saque de R$ 100.00
    minhaConta.sacar(100.00);
    std::cout << "-----------------------------------" << std::endl;

    // Mostra o saldo final
    minhaConta.mostrarSaldo();

    return 0;
}