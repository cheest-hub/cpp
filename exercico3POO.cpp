/*Aula 15/06
prof: Erika
exercicio clase aluno
*/
#include <iostream>
#include <string>
#include <windows.h>

class Aluno {
private:
    std::string nome;
    double nota1;
    double nota2;

public:
    // Construtor para inicializar os atributos
    Aluno(std::string nome, double nota1, double nota2) {
        this->nome = nome;
        this->nota1 = nota1;
        this->nota2 = nota2;
    }

    // Método para calcular e retornar a média
    double calcularMedia() {
        return (this->nota1 + this->nota2) / 2.0;
    }

    // Método para mostrar a situação do aluno
    void mostrarResultado() {
        double media = calcularMedia();
        std::cout << "Aluno: " << this->nome << " | Média: " << media << " -> ";
        
        if (media >= 7.0) {
            std::cout << "APROVADO" << std::endl;
        } else {
            std::cout << "REPROVADO" << std::endl;
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Criação de dois alunos com notas diferentes
    Aluno aluno1("Carlos", 8.5, 7.0);
    Aluno aluno2("Mariana", 5.0, 6.5);

    // Exibição dos resultados
    aluno1.mostrarResultado();
    aluno2.mostrarResultado();

    return 0;
}