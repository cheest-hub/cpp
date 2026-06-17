/*Aula 15/06
prof: Erika
exercicio clase Pessoa
*/
#include <iostream>
#include <string>
#include <windows.h>

class Pessoa {
private:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade) {
        this->nome = nome;
        this->idade = idade;
    }

    void exibirDados() {
        std::cout << "Nome: " << this->nome << " | Idade: " << this->idade << " anos" << std::endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    Pessoa pessoa1("Ana Silva", 25);
    Pessoa pessoa2("João Santos", 34);

    pessoa1.exibirDados();
    pessoa2.exibirDados();

    return 0;
}