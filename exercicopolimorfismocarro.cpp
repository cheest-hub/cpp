/*Aula 17/06
prof: Erika
exercicio clase tipos e polimorfismo
*/
#include <iostream>
#include <string>

using namespace std;

class Veiculo {
protected:
    string marca;

public:
    
    Veiculo(string m) : marca(m) {}

    string getMarca() const { return marca; }
};

// Classe Derivada: Carro (herda de Veiculo)
class Carro : public Veiculo {
private:
    string modelo;

public:
    // Construtor que chama o construtor da classe pai (Veiculo) e inicializa 'modelo'
    Carro(string m, string mod) : Veiculo(m), modelo(mod) {}
    
    // Método getter apenas para o main conseguir acessar o modelo privado
    string getModelo() const { return modelo; }
};

// Função principal para testar o código
int main() {
    // Criando um objeto da classe Carro
    Carro meuCarro("Toyota", "Corolla");

    // Exibindo os dados salvos
    std::cout << "Carro criado com sucesso!" << std::endl;
    std::cout << "Marca: " << meuCarro.getMarca() << std::endl;
    std::cout << "Modelo: " << meuCarro.getModelo() << std::endl;

    return 0;
}