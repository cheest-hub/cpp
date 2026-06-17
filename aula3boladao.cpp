#include <iostream>
#include <string>

int main() {
    // Variáveis para gerenciar os participantes no laço
    int qtdParticipantes;
    int contadorParticipante = 1;
    
    // Variáveis para armazenar o campeão do ranking de forma simples
    std::string nomeCampeao = "Nenhum";
    int maiorPontuacao = -1;

    std::cout << "=== BOLAÇÃO DA COPA (8 PAÍSES) ===\n";
    std::cout << "Quantos participantes vão jogar? ";
    std::cin >> qtdParticipantes;
    std::cin.ignore(); // Limpa o buffer do teclado

    // Estrutura de Repetição: Processa um participante por vez
    do {
        std::string nomeJogador;
        int totalPontos = 0;
        int palpiteM, palpiteV;

        std::cout << "\n-----------------------------------\n";
        std::cout << "Nome do Participante #" << contadorParticipante << ": ";
        std::getline(std::cin, nomeJogador);
        std::cout << "-----------------------------------\n";

        // ---- JOGO 1: Brasil x Alemanha (Resultado Real: 2 x 1) ----
        std::cout << "[" << nomeJogador << "] Brasil x Alemanha\n";
        std::cout << "Gols do Brasil: "; std::cin >> palpiteM;
        std::cout << "Gols da Alemanha: "; std::cin >> palpiteV;
        
        if (palpiteM == 2 && palpiteV == 1) {
            totalPontos += 10; // Placar exato
        } else if ((palpiteM > palpiteV && 2 > 1) || (palpiteM < palpiteV && 2 < 1) || (palpiteM == palpiteV && 2 == 1)) {
            totalPontos += 5;  // Acertou o vencedor (Brasil)
        } else {
            totalPontos += 0;  // Errou o jogo
        }

        // ---- JOGO 2: Argentina x França (Resultado Real: 1 x 1) ----
        std::cout << "\n[" << nomeJogador << "] Argentina x França\n";
        std::cout << "Gols da Argentina: "; std::cin >> palpiteM;
        std::cout << "Gols da França: "; std::cin >> palpiteV;

        if (palpiteM == 1 && palpiteV == 1) {
            totalPontos += 10; // Placar exato
        } else if ((palpiteM > palpiteV && 1 > 1) || (palpiteM < palpiteV && 1 < 1) || (palpiteM == palpiteV && 1 == 1)) {
            totalPontos += 5;  // Acertou o empate
        } else {
            totalPontos += 0;  // Errou o jogo
        }

        // ---- JOGO 3: Portugal x Espanha (Resultado Real: 0 x 2) ----
        std::cout << "\n[" << nomeJogador << "] Portugal x Espanha\n";
        std::cout << "Gols de Portugal: "; std::cin >> palpiteM;
        std::cout << "Gols da Espanha: "; std::cin >> palpiteV;

        if (palpiteM == 0 && palpiteV == 2) {
            totalPontos += 10; // Placar exato
        } else if ((palpiteM > palpiteV && 0 > 2) || (palpiteM < palpiteV && 0 < 2) || (palpiteM == palpiteV && 0 == 2)) {
            totalPontos += 5;  // Acertou o vencedor (Espanha)
        } else {
            totalPontos += 0;  // Errou o jogo
        }

        // ---- JOGO 4: Uruguai x Inglaterra (Resultado Real: 3 x 2) ----
        std::cout << "\n[" << nomeJogador << "] Uruguai x Inglaterra\n";
        std::cout << "Gols do Uruguai: "; std::cin >> palpiteM;
        std::cout << "Gols da Inglaterra: "; std::cin >> palpiteV;
        std::cin.ignore(); // Limpa o buffer antes do próximo getline

        if (palpiteM == 3 && palpiteV == 2) {
            totalPontos += 10; // Placar exato
        } else if ((palpiteM > palpiteV && 3 > 2) || (palpiteM < palpiteV && 3 < 2) || (palpiteM == palpiteV && 3 == 2)) {
            totalPontos += 5;  // Acertou o vencedor (Uruguai)
        } else {
            totalPontos += 0;  // Errou o jogo
        }

        // Exibe a pontuação individual imediata do jogador
        std::cout << "\n>> " << nomeJogador << " fez um total de: " << totalPontos << " pontos.\n";

        // Lógica do Ranking (Mantém salvo apenas quem está ganhando)
        if (totalPontos > maiorPontuacao) {
            maiorPontuacao = totalPontos;
            nomeCampeao = nomeJogador;
        }

        contadorParticipante++; // Incrementa o controle do laço

    } while (contadorParticipante <= qtdParticipantes);

    // 2. EXIBIÇÃO DO VENCEDOR (Simulando o topo do ranking)
    std::cout << "\n===================================\n";
    std::cout << "       VENCEDOR DO BOLAÇÃO         \n";
    std::cout << "===================================\n";
    std::cout << " 1º Lugar: " << nomeCampeao << " com " << maiorPontuacao << " pontos!\n";
    std::cout << "===================================\n";

    return 0;
}