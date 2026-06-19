#include <iostream>
#include <string>
#include <memory>
#include <windows.h>


// ==========================================
// 1. CLASSES, HERANÇA E POLIMORFISMO
// ==========================================

// Classe Base: Personagem
class Personagem {
protected:
    std::string nome;
    std::string tipo;
    int nivel_poder;

public:
    Personagem(std::string n, std::string t, int poder) 
        : nome(n), tipo(t), nivel_poder(poder) {}

    // Destrutor virtual essencial para polimorfismo seguro
    virtual ~Personagem() = default;

    // Método polimórfico para exibir informações
    virtual void exibir_info() const {
        std::cout << "[" << tipo << "] " << nome << " (Poder: " << nivel_poder << ")";
    }

    // Getter necessário para a ordenação na árvore
    int get_nivel_poder() const { return nivel_poder; }
};

// Classe Derivada: Chefe da Floresta (Herança)
class ChefeDaFloresta : public Personagem {
private:
    std::string reino;

public:
    ChefeDaFloresta(std::string n, std::string t, int poder, std::string r)
        : Personagem(n, t, poder), reino(r) {}

    // Sobrescrita polimórfica (Polimorfismo)
    void exibir_info() const override {
        // Chama o comportamento da classe base
        Personagem::exibir_info();
        // Adiciona o comportamento específico do Chefe
        std::cout << " <Chefe do Reino: " << reino << ">";
    }
};

// ==========================================
// 2. ESTRUTURA DA ÁRVORE BINÁRIA DE BUSCA
// ==========================================

struct No {
    std::shared_ptr<Personagem> personagem;
    std::shared_ptr<No> esquerda;
    std::shared_ptr<No> direita;

    No(std::shared_ptr<Personagem> p) : personagem(p), esquerda(nullptr), direita(nullptr) {}
};

// Função para inserir um novo personagem respeitando as regras de poder
std::shared_ptr<No> inserir(std::shared_ptr<No> raiz, std::shared_ptr<Personagem> novo) {
    if (raiz == nullptr) {
        return std::make_shared<No>(novo);
    }

    if (novo->get_nivel_poder() < raiz->personagem->get_nivel_poder()) {
        raiz->esquerda = inserir(raiz->esquerda, novo);
    } else {
        raiz->direita = inserir(raiz->direita, novo);
    }

    return raiz;
}

// Percurso em Ordem (In-Order) para exibir do menor para o maior poder
void percorrer_em_ordem(std::shared_ptr<No> raiz) {
    if (raiz == nullptr) return;

    percorrer_em_ordem(raiz->esquerda);
    
    // Chamada polimórfica: decide em tempo de execução se chama a exibição comum ou de Chefe
    raiz->personagem->exibir_info();
    std::cout << "\n";
    
    percorrer_em_ordem(raiz->direita);
}

// ==========================================
// 3. EXECUÇÃO DO DESAFIO (MAIN)
// ==========================================

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::shared_ptr<No> floresta = nullptr;

    // Criando e adicionando 6 personagens (incluindo 2 Chefes)
    // Usamos shared_ptr para gerenciar a memória automaticamente
    floresta = inserir(floresta, std::make_shared<Personagem>("Lupi", "Animal", 45));
    floresta = inserir(floresta, std::make_shared<Personagem>("Mago Merlin", "Mago", 90));
    
    // Inserindo os Chefes (aqui acontece o upcasting implícito seguro)
    floresta = inserir(floresta, std::make_shared<ChefeDaFloresta>("Chefe Dragão", "Dragão", 150, "Montanhas de Fogo"));
    floresta = inserir(floresta, std::make_shared<Personagem>("Fada Flora", "Fada", 30));
    floresta = inserir(floresta, std::make_shared<ChefeDaFloresta>("Rainha Elfa", "Elfo", 120, "Bosque Sagrado"));
    floresta = inserir(floresta, std::make_shared<Personagem>("Goblino", "Monstro", 15));

    // Exibindo os resultados
    std::cout << "--- PERSONAGENS DA FLORESTA ENCANTADA (ORDEM DE PODER) ---\n\n";
    percorrer_em_ordem(floresta);
    std::cout << "\n----------------------------------------------------------\n";

    return 0;
}