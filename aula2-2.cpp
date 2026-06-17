#include <iostream>
#include <string>
#include <stdexcept> // Biblioteca necessária para usar as exceções (runtime_error)

// 1. FUNÇÃO DE VALIDAÇÃO (Deixa a função main limpa e organizada)
bool verificarCredenciais(std::string user, std::string pass) {
    const std::string USER_DB = "admin";
    const std::string PASS_DB = "1234";

    // TRATAMENTO DE ERRO COM EXCEÇÃO: Se algum campo estiver vazio, dispara um erro
    if (user.empty() || pass.empty()) {
        throw std::runtime_error("Campos obrigatorios nao preenchidos!");
    }

    // Retorna verdadeiro se os dados baterem com o banco de dados
    return (user == USER_DB && pass == PASS_DB);
}

int main() {
    std::string usuario, senha;
    int tentativas = 3;
    bool autenticado = false;

    std::cout << "========= SISTEMA PROTEGIDO POR FUNCOES =========" << std::endl;

    // ESTRUTURA DE REPETIÇÃO
    while (tentativas > 0 && !autenticado) {
        std::cout << "\nTentativas restantes: " << tentativas << std::endl;
        
        std::cout << "Digite o login: ";
        std::getline(std::cin, usuario);

        std::cout << "Digite a senha: ";
        std::getline(std::cin, senha);

        // Bloco de captura de erros (Try / Catch)
        try {
            // Tenta executar a validação dentro da função
            if (verificarCredenciais(usuario, senha)) {
                std::cout << "\n[SUCESSO] Acesso liberado!" << std::endl;
                autenticado = true;
            } else {
                tentativas--;
                std::cout << "[ERRO] Login ou senha invalidos." << std::endl;
            }
        } 
        // Se a função disparar um "throw", o "catch" captura o erro aqui embaixo
        catch (const std::runtime_error& erro) {
            std::cout << "[ALERTA DO SISTEMA] " << erro.what() << " Tente novamente.\n";
            // Não reduz o número de tentativas por ser apenas um erro de digitação
        }
    }

    if (!autenticado) {
        std::cout << "\n[BLOQUEIO] Conta temporariamente suspensa por seguranca.\n";
    }

    return 0;
}