#include <iostream>
#include <string>
#include <limits> // Necessária para o tratamento de erros do buffer

int main() {
    // Banco de dados simulado (Valores fixos)
    const std::string USER_DB = "admin";
    const std::string PASS_DB = "1234";

    std::string usuario;
    std::string senha;
    int tentativas =4 ;
    bool autenticado = false;

    std::cout << "========= SISTEMA DE AUTENTICACAO =========" << std::endl;

    // 1. ESTRUTURA DE REPETIÇÃO (Controla o número de tentativas)
    while (tentativas > 0 && !autenticado) {
        std::cout << "\nTentativas restantes: " << tentativas << std::endl;

        // 2. TRATAMENTO DE ERRO / CAPTURA DE DADOS SEGURA
        // std::getline impede que o programa quebre se o usuário digitar espaços
        std::cout << "Digite o seu login: ";
        std::getline(std::cin, usuario);

        std::cout << "Digite a sua senha: ";
        std::getline(std::cin, senha);

        // Validação de segurança de campos vazios
        if (usuario.empty() || senha.empty()) {
            std::cout << "[ERRO VITAL] Os campos nao podem ficar em branco!\n";
            continue; // Pula o resto do loop e pede os dados novamente sem gastar tentativa
        }

        // 3. ESTRUTURA CONDICIONAL (Validação de credenciais)
        if (usuario == USER_DB && senha == PASS_DB) {
            std::cout << "\n[SUCESSO] Acesso concedido! Bem-vindo ao sistema.\n";
            autenticado = true;
        } else {
            tentativas--;
            std::cout << "[ERRO] Login ou senha inválido.\n";
        }
    }

    // Fluxo final pós-loop
    if (!autenticado) {
        std::cout << "\n[BLOQUEIO DE SEGURANCA] Tentativas esgotadas. Conta bloqueada.\n";
    }

    return 0;
}