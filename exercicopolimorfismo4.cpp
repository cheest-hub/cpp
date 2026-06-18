#include <iostream>
#include <string>

class Produto {
protected:
    std::string nome;
    double preco;

public:
    Produto(std::string n, double p) : nome(n), preco(p) {}
    virtual ~Produto() {}

    virtual void exibirDados() const {
        std::cout << "Produto: " << nome << " | Preço: R$ " << preco << std::endl;
    }
};

// ==========================================
// SUBCLASSE: LIVRO
// ==========================================
class Livro : public Produto {
private:
    std::string autor;

public:
    Livro(std::string n, double p, std::string a) : Produto(n, p), autor(a) {}

    void exibirDados() const override {
        std::cout << "Livro: " << nome << " | Autor: " << autor << " | Preço: R$ " << preco << std::endl;
    }
};

// ==========================================
// SUBCLASSE: ELETRONICO
// ==========================================
class Eletronico : public Produto {
private:
    std::string marca;

public:
    Eletronico(std::string n, double p, std::string m) : Produto(n, p), marca(m) {}

    void exibirDados() const override {
        std::cout << "Eletrônico: " << nome << " | Marca: " << marca << " | Preço: R$ " << preco << std::endl;
    }
};

// ==========================================
// FUNÇÃO PRINCIPAL (MAIN)
// ==========================================
int main() {
    // Criando 2 objetos da classe Livro
    Livro livro1("O Senhor dos Anéis", 59.90, "J.R.R. Tolkien");
    Livro livro2("1984", 39.90, "George Orwell");

    // Criando 2 objetos da classe Eletronico
    Eletronico eletronico1("PlayStation 5", 3999.00, "Sony");
    Eletronico eletronico2("Galaxy S24", 4500.00, "Samsung");

    // Imprimindo os dados dos objetos criados
    std::cout << "--- LISTA DE LIVROS ---" << std::endl;
    livro1.exibirDados();
    livro2.exibirDados();

    std::cout << "\n--- LISTA DE ELETRÔNICOS ---" << std::endl;
    eletronico1.exibirDados();
    eletronico2.exibirDados();

    return 0;
}