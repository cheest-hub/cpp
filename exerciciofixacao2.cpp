/*Aula 16/06
prof: Erika
exercicio 2 classe com encapsulamento produto
*/
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    Produto(string n, double p) {
        nome = n;
        setPreco(p); // Usa o setter para garantir a validação desde a criação
    }

    string getNome() const { return nome; }
    double getPreco() const { return preco; }

    void setNome(string n) {
        nome = n;
    }

    void setPreco(double p) {
        if (p > 0) {
            preco = p;
        } else {
            cout << "Erro: O preco do produto '" << nome << "' nao pode ser zero ou negativo!" << endl;
            preco = 0.01;
        }
    }

    void exibirDados() const {
        cout << "Produto: " << nome << " | Preco: R$" << preco << endl;
    }
};

int main() {

    SetConsoleOutputCP(65001);

    cout << "--- Criando e Testando Produtos ---\n" << endl;

    Produto p1("Notebook", 3500.99);
    p1.exibirDados();

    Produto p2("Caneta Azul", -1.50); 
    p2.exibirDados();

    cout << "\n--- Alterando valores com Setters ---\n" << endl;

    // Testando alteração válida
    p2.setNome("Caneta Azul");
    p2.setPreco(5.50);
    p2.exibirDados();

    // Testando alteração inválida (preço zero)
    p1.setPreco(0);
    p1.exibirDados();

    return 0;
};