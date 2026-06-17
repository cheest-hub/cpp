#include <iostream>
#include <string>
#include <clocale>

int main() {

    std::setlocale(LC_ALL, "Portuguese");

    // Variáveis de controle do laço
    int qtdParticipantes;
    int contador = 1;

    // Variáveis isoladas para salvar o pódio (Nomes)
    std::string p1_nome = "Vazio", p2_nome = "Vazio", p3_nome = "Vazio";
    
    // Variáveis isoladas para salvar as pontuações do pódio
    int p1_pontos = -1, p2_pontos = -1, p3_pontos = -1;

    std::cout << "=== BOLAÇÃO DA COPA (8 PAÍSES) ===\n";
    std::cout << "Quantos participantes vão jogar (Máximo 3)? ";
    std::cin >> qtdParticipantes;
    std::cin.ignore();

    // Garante o limite de até 3 para não estourar as variáveis fixas
    if (qtdParticipantes > 3) {
        qtdParticipantes = 3;
    }

    // Estrutura de repetição Principal
    do {
        std::string nomeJogador;
        int totalPontos = 0;
        int palpiteM, palpiteV;

        std::cout << "\n-----------------------------------\n";
        std::cout << "Nome do Participante #" << contador << ": ";
        std::getline(std::cin, nomeJogador);
        std::cout << "-----------------------------------\n";

        // ---- JOGO 1: Brasil x Alemanha (Real: 2 x 1) ----
        std::cout << "[" << nomeJogador << "] Brasil x Alemanha\n";
        std::cout << "Gols do Brasil: "; std::cin >> palpiteM;
        std::cout << "Gols da Alemanha: "; std::cin >> palpiteV;
        
        if (palpiteM == 2 && palpiteV == 1) {
            totalPontos += 10;
        } else if ((palpiteM > palpiteV && 2 > 1) || (palpiteM < palpiteV && 2 < 1) || (palpiteM == palpiteV && 2 == 1)) {
            totalPontos += 5;
        } else {
            totalPontos += 0;
        }

        // ---- JOGO 2: Argentina x França (Real: 1 x 1) ----
        std::cout << "\n[" << nomeJogador << "] Argentina x França\n";
        std::cout << "Gols da Argentina: "; std::cin >> palpiteM;
        std::cout << "Gols da França: "; std::cin >> palpiteV;

        if (palpiteM == 1 && palpiteV == 1) {
            totalPontos += 10;
        } else if ((palpiteM > palpiteV && 1 > 1) || (palpiteM < palpiteV && 1 < 1) || (palpiteM == palpiteV && 1 == 1)) {
            totalPontos += 5;
        } else {
            totalPontos += 0;
        }

        // ---- JOGO 3: Portugal x Espanha (Real: 0 x 2) ----
        std::cout << "\n[" << nomeJogador << "] Portugal x Espanha\n";
        std::cout << "Gols de Portugal: "; std::cin >> palpiteM;
        std::cout << "Gols da Espanha: "; std::cin >> palpiteV;

        if (palpiteM == 0 && palpiteV == 2) {
            totalPontos += 10;
        } else if ((palpiteM > palpiteV && 0 > 2) || (palpiteM < palpiteV && 0 < 2) || (palpiteM == palpiteV && 0 == 2)) {
            totalPontos += 5;
        } else {
            totalPontos += 0;
        }

        // ---- JOGO 4: Uruguai x Inglaterra (Real: 3 x 2) ----
        std::cout << "\n[" << nomeJogador << "] Uruguai x Inglaterra\n";
        std::cout << "Gols do Uruguai: "; std::cin >> palpiteM;
        std::cout << "Gols da Inglaterra: "; std::cin >> palpiteV;
        std::cin.ignore(); 

        if (palpiteM == 3 && palpiteV == 2) {
            totalPontos += 10;
        } else if ((palpiteM > palpiteV && 3 > 2) || (palpiteM < palpiteV && 3 < 2) || (palpiteM == palpiteV && 3 == 2)) {
            totalPontos += 5;
        } else {
            totalPontos += 0;
        }

        // Exibe a pontuação final calculada do jogador atual
        std::cout << "\n>> " << nomeJogador << " terminou com: " << totalPontos << " pontos.\n";

        // LÓGICA DO RANKING: Encaixa o jogador na posição correta usando IF/ELSE mudando as posições de nível
        if (totalPontos >= p1_pontos) {
            // Empurra o antigo 2º para 3º, e o antigo 1º para 2º
            p3_pontos = p2_pontos; p3_nome = p2_nome;
            p2_pontos = p1_pontos; p2_nome = p1_nome;
            // Define o novo 1º lugar
            p1_pontos = totalPontos; p1_nome = nomeJogador;
        } 
        else if (totalPontos >= p2_pontos) {
            // Empurra o antigo 2º para 3º
            p3_pontos = p2_pontos; p3_nome = p2_nome;
            // Define o novo 2º lugar
            p2_pontos = totalPontos; p2_nome = nomeJogador;
        } 
        else if (totalPontos >= p3_pontos) {
            // Define o novo 3º lugar
            p3_pontos = totalPontos; p3_nome = nomeJogador;
        }

        contador++;

    } while (contador <= qtdParticipantes);

    // 2. EXIBIÇÃO DO RANKING DINÂMICO ESTRUTURADO
    std::cout << "\n===================================\n";
    std::cout << "         RANKING DO BOLAÇÃO        \n";
    std::cout << "===================================\n";
    
    if (qtdParticipantes >= 1) {
        std::cout << " 1º Lugar: " << p1_nome << " - " << p1_pontos << " pontos\n";
    }
    if (qtdParticipantes >= 2) {
        std::cout << " 2º Lugar: " << p2_nome << " - " << p2_pontos << " pontos\n";
    }
    if (qtdParticipantes == 3) {
        std::cout << " 3º Lugar: " << p3_nome << " - " << p3_pontos << " pontos\n";
    }
    
    std::cout << "===================================\n";

    return 0;
}